#include "stdafx.h"
#include "TokenScanner.h"


Token* TokenScanner::Scan(FILE* f)
{

	char c;
	string str = "";//��ʼΪ�մ�
	Token* tokenptr = NULL;
	tokenptr = new Token();
	tokenptr->content = "";
	StateType state = START;
	while (state != DONE) {
		c = fgetc(f);

		switch (state)
		{
			/* ��ǰDFA״̬stateΪ��ʼ״̬START,DFA���ڵ�ǰ���ʿ�ʼλ�� */
		case START:
			str += c;		//���ӳ���

			if (isdigit(c))
				state = INNUM;
			else if (isalpha(c))
				state = INID;
			else if (c == ':')
				state = INASSIGN;
			else if (c == '.')
				state = INRANGE;
			else if (c == '\'')
			{
				state = INCHAR;
				str = str.substr(0, str.length() - 1);
			}
			else if ((c == ' ') || (c == '\t') || (c == '\n') || (c == '\r')) {
				str = str.substr(0, str.length() - 1);
				if ((c == '\n') || (c == '\r'))
					Line++;
			}
			else if (c == '{')
			{
				str = str.substr(0, str.length() - 1);
				state = INCOMMENT;
			}
			else
			{
				state = DONE;
				switch (c)
				{
					/* ��ǰ�ַ�cΪEOF,�ַ��洢��־save����ΪFALSE,����洢     *
					* ��ǰʶ�𵥴ʷ���ֵcurrentToken����Ϊ�ļ���������ENDFILE */
				case EOF:
					str = str.substr(0, str.length() - 1);
					tokenptr->type = ENDFILE;
					break;
				case '=':
					tokenptr->type = EQ;
					break;
				case '<':
					tokenptr->type = LT;
					break;
				case '+':
					tokenptr->type = PLUS;
					break;
				case '-':
					tokenptr->type = MINUS;
					break;
				case '*':
					tokenptr->type = TIMES;
					break;
				case '/':
					tokenptr->type = OVER;
					break;

				case '(':
					tokenptr->type = LPAREN;
					break;

				case ')':
					tokenptr->type = RPAREN;
					break;

				case ';':
					tokenptr->type = SEMI;
					break;
				case ',':
					tokenptr->type = COMMA;
					break;

				case '[':
					tokenptr->type = LMIDPAREN;
					break;

				case ']':
					tokenptr->type = RMIDPAREN;
					break;
				default:
					tokenptr->type = ERRORR;
					Error = true;
					break;
				}
			}
			break;
			/********** ��ǰ״̬Ϊ��ʼ״̬START�Ĵ������ **********/
		case INCOMMENT:
			if (c == EOF)
			{
				state = DONE;
				tokenptr->type = ENDFILE;

			}

			/* ��ǰ�ַ�cΪ"}",ע�ͽ���.��ǰDFA״̬state����Ϊ��ʼ״̬START */
			else if (c == '}')
				state = START;
			break;
			/********** ��ǰ״̬Ϊע��״̬INCOMMENT�Ĵ������ **********/
		case INASSIGN:
			str += c;
			state = DONE;

			/* ��ǰ�ַ�cΪ"=",��ǰʶ�𵥴ʷ���ֵcurrentToken����Ϊ��ֵ����ASSIGN */
			if (c == '=')
				tokenptr->type = ASSIGN;

			else
			{
				fseek(f, -1, SEEK_CUR);
				str = str.substr(0, str.length() - 1);
				tokenptr->type = ERRORR;
				Error = true;
			}
			break;
			/********** ��ǰ״̬Ϊ��ֵ״̬INASSIGN�Ĵ������ **********/
		case INRANGE:
			str += c;
			state = DONE;

			if (c == '.')
				tokenptr->type = UNDERANGE;

			else
			{
				fseek(f, -1, SEEK_CUR);
				str = str.substr(0, str.length() - 1);
				tokenptr->type = DOT;
			}
			break;
		case INNUM:

			str += c;
			if (!isdigit(c))
			{
				fseek(f, -1, SEEK_CUR);
				str = str.substr(0, str.length() - 1);
				state = DONE;
				tokenptr->type = INTC;
			}
			break;

		case INCHAR:
			str += c;
			if (isalnum(c))
			{
				char c1 = fgetc(f);
				if (c1 == '\'')
				{
					state = DONE;
					tokenptr->type = CHARC;
				}
				else
				{
					fseek(f, -1, SEEK_CUR);
				}
			}
			else
			{
				fseek(f, -1, SEEK_CUR);
				str = str.substr(0, str.length() - 1);
				state = DONE;
				tokenptr->type = ERRORR;
				Error = true;
			}
			break;

		case INID:
			str += c;
			if (!isalnum(c))
			{
				fseek(f, -1, SEEK_CUR);
				str = str.substr(0, str.length() - 1);
				state = DONE;
				tokenptr->type = ID;
			}
			break;
		case DONE:
			break;
		default:
			//fprintf(listing, "Scanner Bug: state= %d\n", state);
			Error = true;
			state = DONE;
			tokenptr->type = ERRORR;
			break;
		}
	}
	if (state == DONE)
	{

		if (tokenptr->type == ID)
		{
			tokenptr->type = ReservedLookup(str);
			if (tokenptr->type == ID)		//д���������� ��ط��߼��е����⵫�ǲ�Ӱ����
				tokenptr->content = str;
			//strcpy(tokenString, tokenString);
		}
		tokenptr->line = Line;
		tokenptr->content = str;
	}
	return tokenptr;
}

LexType TokenScanner::ReservedLookup(string str)
{
	for (int i = 0; i < 21; i++)
		if (str == reservedWords[i].str)
			return reservedWords[i].tok;
	return ID;
}

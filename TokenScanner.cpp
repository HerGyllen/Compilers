#include "stdafx.h"
#include "TokenScanner.h"


Token* TokenScanner::Scan(FILE* f)
{

	char c;
	string str = "";//初始为空串
	Token* tokenptr = NULL;
	tokenptr = new Token();
	tokenptr->content = "";
	StateType state = START;
	while (state != DONE) {
		c = fgetc(f);

		switch (state)
		{
			/* 当前DFA状态state为开始状态START,DFA处于当前单词开始位置 */
		case START:
			str += c;		//增加长度

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
					/* 当前字符c为EOF,字符存储标志save设置为FALSE,无需存储     *
					* 当前识别单词返回值currentToken设置为文件结束单词ENDFILE */
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
			/********** 当前状态为开始状态START的处理结束 **********/
		case INCOMMENT:
			if (c == EOF)
			{
				state = DONE;
				tokenptr->type = ENDFILE;

			}

			/* 当前字符c为"}",注释结束.当前DFA状态state设置为开始状态START */
			else if (c == '}')
				state = START;
			break;
			/********** 当前状态为注释状态INCOMMENT的处理结束 **********/
		case INASSIGN:
			str += c;
			state = DONE;

			/* 当前字符c为"=",当前识别单词返回值currentToken设置为赋值单词ASSIGN */
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
			/********** 当前状态为赋值状态INASSIGN的处理结束 **********/
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
			if (tokenptr->type == ID)		//写完我再来改 这地方逻辑有点问题但是不影响结果
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

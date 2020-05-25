#include "stdafx.h"
#include "Parser.h"

static string �ʷ�����[100] = { "ENDFILE", "ERRORR" ,
"PROGRAM", "PROCEDURE", "TYPE", "VAR", "IF",
"THEN", "ELSE"," FI", "WHILE", "DO",
"ENDWH", "BEGIN", "END", "READ", "WRITE",
"ARRAY", "OF", "RECORD", "RETURN",
"INTEGER", "CHARR",
/* ���ַ����ʷ��� */
"ID", "INTC","CHARC",
/*������� */
"ASSIGN", "EQ", "LT", "PLUS", "MINUS",
"TIMES", "OVER"," LPAREN", "RPAREN", "DOT",
"COLON", "SEMI","COMMA"," LMIDPAREN", "RMIDPAREN",
"UNDERANGE"
};
//����ջ���﷨��ջ�ĳ�ʼ��
Parser::Parser() {
	stack<Symbol> symbol;
	this->symbol = symbol;
	stack<TreeNode**> tree;
	this->tree = tree;
	stack<TreeNode*> opstack;
	this->opstack = opstack;
	stack<TreeNode*> numstack;
	this->numstack = numstack;
	this->expflag = 0;
	this->getExpResult = 0;
	this->getExpResult2 = 0;
}

string Parser::Parse(vector<Token>& Tokenlist)
{
	this->Error = false;
	int t[67][42];
	LL1_init(t);
	this->symbol.push(Program);//����ֱ��ѹ��vt��lextape�����Զ����ù��캯��
	this->root = new TreeNode(1, ProK);
	this->tree.push(&(this->root->child[2]));
	this->tree.push(&(this->root->child[1]));
	this->tree.push(&(this->root->child[0]));

	string str = "";

	std::vector<Token>::iterator Tokeniterator = Tokenlist.begin();
	while (!this->symbol.empty() && this->Error == false) {
		this->currentToken = *Tokeniterator;
		this->lineno = currentToken.line;
		int lineno = currentToken.line;
		if (currentToken.type == ENDFILE || Tokeniterator == Tokenlist.end()) {
			str.append("������");
			str.append(to_string(lineno));
			str.append("�ļ���ǰ����\r\n");
			this->Error = true;
			break;
		}
		Symbol curSym = this->symbol.top();
		//��ǰջ��Ϊ�ռ���
		if (curSym.vt == vt_uninit) {
			if (curSym.lex == currentToken.type) {
				this->symbol.pop();
				/*������*/
				if (currentToken.type == ID) {
					str.append("����: ");
					str.append(to_string(currentToken.line));
					str.append("    ");
					str.append(to_string(currentToken.type));
					str.append("     ");
					str.append(currentToken.content);
					str.append("\r\n");
				}
				else {
					str.append("����: ");
					str.append(to_string(currentToken.line));
					str.append("    ");
					str.append(to_string(currentToken.type));
					str.append("     ");
					str.append(�ʷ�����[currentToken.type]);
					str.append("\r\n");

				}
				Tokeniterator++;			//��ȡ��һ��token
				this->currentToken = *Tokeniterator;

			}
			else {
				str.append("������");
				str.append(to_string(lineno));
				str.append("    ���������ʴ�");
				str.append("\r\n");
				this->Error = true;
			}
		}
		//��ǰջ��Ϊ���ռ���
		else {
			this->symbol.pop();
			int pnum = t[curSym.vt][currentToken.type];
			if (pnum == -1) {
				str.append("������");
				str.append(to_string(lineno));
				str.append("    û����Ӧ����ʽ������");
				str.append("\r\n");
				this->Error = true;
			}
			str.append(predict(pnum));
		}
	}
	Token token = *Tokeniterator;
	if (token.type == ENDFILE && this->symbol.empty() && this->Error == false)
	{
		str.append("�﷨����������δ���ִ���");
		str.append("\r\n");
	}
	return str;
}

string Parser::predict(int pnum) {
	string str = "";
	str.append("ѡ�ò���ʽ���:  ");
	str.append(to_string(pnum));
	str.append("\r\n");
	if (pnum == 1)
		process1();
	else if (pnum == 2)
		process2();
	else if (pnum == 3)
		process3();
	else if (pnum == 4)
		process4();
	else if (pnum == 5)
		process5();
	else if (pnum == 6)
		process6();
	else if (pnum == 7)
		process7();
	else if (pnum == 8)
		process8();
	else if (pnum == 9)
		process9();
	else if (pnum == 10)
		process10();
	else if (pnum == 11)
		process11();
	else if (pnum == 12)
		process12();
	else if (pnum == 13)
		process13();
	else if (pnum == 14)
		process14();
	else if (pnum == 15)
		process15();
	else if (pnum == 16)
		process16();
	else if (pnum == 17)
		process17();
	else if (pnum == 18)
		process18();
	else if (pnum == 19)
		process19();
	else if (pnum == 20)
		process20();
	else if (pnum == 21)
		process21();
	else if (pnum == 22)
		process22();
	else if (pnum == 23)
		process23();
	else if (pnum == 24)
		process24();
	else if (pnum == 25)
		process25();
	else if (pnum == 26)
		process26();
	else if (pnum == 27)
		process27();
	else if (pnum == 28)
		process28();
	else if (pnum == 29)
		process29();
	else if (pnum == 30)
		process30();
	else if (pnum == 31)
		process31();
	else if (pnum == 32)
		process32();
	else if (pnum == 33)
		process33();
	else if (pnum == 34)
		process34();
	else if (pnum == 35)
		process35();
	else if (pnum == 36)
		process36();
	else if (pnum == 37)
		process37();
	else if (pnum == 38)
		process38();
	else if (pnum == 39)
		process39();
	else if (pnum == 40)
		process40();
	else if (pnum == 41)
		process41();
	else if (pnum == 42)
		process42();
	else if (pnum == 43)
		process43();
	else if (pnum == 44)
		process44();
	else if (pnum == 45)
		process45();
	else if (pnum == 46)
		process46();
	else if (pnum == 47)
		process47();
	else if (pnum == 48)
		process48();
	else if (pnum == 49)
		process49();
	else if (pnum == 50)
		process50();
	else if (pnum == 51)
		process51();
	else if (pnum == 52)
		process52();
	else if (pnum == 53)
		process53();
	else if (pnum == 54)
		process54();
	else if (pnum == 55)
		process55();
	else if (pnum == 56)
		process56();
	else if (pnum == 57)
		process57();
	else if (pnum == 58)
		process58();
	else if (pnum == 59)
		process59();
	else if (pnum == 60)
		process60();
	else if (pnum == 61)
		process61();
	else if (pnum == 62)
		process62();
	else if (pnum == 63)
		process63();
	else if (pnum == 64)
		process64();
	else if (pnum == 65)
		process65();
	else if (pnum == 66)
		process66();
	else if (pnum == 67)
		process67();
	else if (pnum == 68)
		process68();
	else if (pnum == 69)
		process69();
	else if (pnum == 70)
		process70();
	else if (pnum == 71)
		process71();
	else if (pnum == 72)
		process72();
	else if (pnum == 73)
		process73();
	else if (pnum == 74)
		process74();
	else if (pnum == 75)
		process75();
	else if (pnum == 76)
		process76();
	else if (pnum == 77)
		process77();
	else if (pnum == 78)
		process78();
	else if (pnum == 79)
		process79();
	else if (pnum == 80)
		process80();
	else if (pnum == 81)
		process81();
	else if (pnum == 82)
		process82();
	else if (pnum == 83)
		process83();
	else if (pnum == 84)
		process84();
	else if (pnum == 85)
		process85();
	else if (pnum == 86)
		process86();
	else if (pnum == 87)
		process87();
	else if (pnum == 88)
		process88();
	else if (pnum == 89)
		process89();
	else if (pnum == 90)
		process90();
	else if (pnum == 91)
		process91();
	else if (pnum == 92)
		process92();
	else if (pnum == 93)
		process93();
	else if (pnum == 94)
		process94();
	else if (pnum == 95)
		process95();
	else if (pnum == 96)
		process96();
	else if (pnum == 97)
		process97();
	else if (pnum == 98)
		process98();
	else if (pnum == 99)
		process99();
	else if (pnum == 100)
		process100();
	else if (pnum == 101)
		process101();
	else if (pnum == 102)
		process102();
	else if (pnum == 103)
		process103();
	else if (pnum == 104)
		process104();
	return str;
}

int Parser::Priosity(LexType op) {
	if (op == END)
		return 0;
	else if (op == EQ || op == LT)
		return 1;
	else if (op == PLUS || op == MINUS)
		return 2;
	else if (op == TIMES || op == OVER)
		return 3;
	else
		return -1;
}

string Parser::PrintTree(TreeNode* treenode)
{
	/*���ַ�������ʽ���*/
	string str = "";
	int j;
	/* ����������,ÿ�ν����﷨���ڵ㶼������������ */
	this->indentation += 4;
	while (treenode != NULL)
	{
		if ((int)(treenode->lineno == 0))
			str.append( "         "); //9���ո�
		else
			switch (treenode->lineno / 10) {
			case 0:
				str.append("line:");
				str.append(to_string(treenode->lineno)); 
				str.append("   ");
				break;
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
				str.append("line:");
				str.append(to_string(treenode->lineno));
				str.append("  ");
				break;
			default:
				str.append("line:");
				str.append(to_string(treenode->lineno));
				str.append("  ");
				break;
			}

		string space(this->indentation, ' ');	//��ӡ��Ӧ�Ŀո�,��������
		str.append(space);

		switch (treenode->nodekind)
		{
		case ProK:
			str.append("ProK  ");
			break;
		case PheadK:
			str.append("PheadK  ");
			str.append(treenode->name[0]);
			str.append("  ");
			break;
		case DecK:
		{
			str.append("DecK  ");
			if (treenode->attr.procAttr.paramt == varparamtype)
				str.append("var param:  ");
			if (treenode->attr.procAttr.paramt == valparamtype)
				str.append("value param:  ");
			switch (treenode->kind.dec)
			{
			case  ArrayK:
			{
				str.append("ArrayK  ");
				str.append(to_string(treenode->attr.arrayAttr.up));
				str.append("  ");
				str.append(to_string(treenode->attr.arrayAttr.low));
				str.append("  ");
				if (treenode->attr.arrayAttr.childType == CharK)
					str.append("Chark  ");
				else if (treenode->attr.arrayAttr.childType == CharK)
					str.append("IntegerK  ");
			}; break;
			case  CharK:
				str.append("CharK  ");
				break;
			case  IntegerK:
				str.append("IntegerK  ");
				break;
			case  RecordK:
				str.append("RecordK  ");
				break;
			case  IdK:
				str.append("IdK  ");
				str.append(treenode->type_name);
				str.append("  ");
				break;
			default:
				str.append("error1");
				this->Error = true;
			};
			if (treenode->idnum != 0) {
				for (int i = 0; i <= (treenode->idnum); i++) {
					str.append(treenode->name[i]);
					str.append("  ");
				}
			}
			else
			{
				str.append("wrong!no var!\t\n");
				this->Error = true;
			}
		}
		break;
		case TypeK:
			str.append("TypeK  ");
			break;
		case VarK:
			str.append("VarK  ");
			//if (treenode->table[0] != NULL) {
			//	cout << "TypeK  ";
			//	//fprintf(listing, "%d  %d  ", tree->table[0]->attrIR.More.VarAttr.off, tree->table[0]->attrIR.More.VarAttr.level);
			//}
			break;
		case ProcDecK:
			str.append("ProcDecK  ");
			str.append(treenode->name[0]);
			str.append("  ");
			//if (tree->table[0] != NULL)
			break;
		case StmLK:
			str.append("StmLk  ");
			break;
		case StmtK:
		{
			str.append("StmtK  ");
			switch (treenode->kind.stmt)
			{
			case IfK:
				str.append("If  ");
				break;
			case WhileK:
				str.append("While  ");
				break;
			case AssignK:
				str.append("Assign  ");
				break;
			case ReadK:
				str.append("Read  ");
				str.append(treenode->name[0]);
				str.append("  ");
				/*	if (tree->table[0] != NULL)
						fprintf(listing, "%d   %d  ", tree->table[0]->attrIR.More.VarAttr.off, tree->table[0]->attrIR.More.VarAttr.level);*/
				break;
			case WriteK:
				str.append("Write  ");
				break;
			case CallK:
				str.append("Call  ");
				str.append(treenode->name[0]);
				str.append("  ");
				break;
			case ReturnK:
				str.append("Return  ");
				break;
			default:
				str.append("error2!");
				this->Error = true;
				break;
			}
		}break;
		case ExpK:
		{
			str.append("ExpK  ");
			switch (treenode->kind.exp)
			{
			case OpK:
			{
				str.append("Op  ");
				switch (treenode->attr.expAttr.op)
				{
				case EQ:
					str.append("=  "); break;
				case LT:
					str.append("<  "); break;
				case PLUS:
					str.append("+  "); break;
				case MINUS:
					str.append("-  "); break;
				case TIMES:
					str.append("*  "); break;
				case OVER:
					str.append("/  "); break;
				default:
					str.append("error3!");
					this->Error = true;
					break;
				}
				if (treenode->attr.expAttr.varkind == ArrayMembV)
				{
					str.append("ArrayMember  ");
					str.append(treenode->name[0]);
					str.append("  ");
				}
			}; break;	//case ExpK:
			case ConstK:
				str.append("Const  ");
				switch (treenode->attr.expAttr.varkind)
				{
				case IdV:
					str.append("Id  ");
					str.append(treenode->name[0]);
					str.append("  ");
					break;
				case FieldMembV:
					str.append("FieldMember  ");
					str.append(treenode->name[0]);
					str.append("  ");
					break;
				case ArrayMembV:
					str.append("ArrayMember  ");
					str.append(treenode->name[0]);
					str.append("  ");
					break;
				default:
					str.append("var type error!");
					this->Error = true;
					break;
				}
				str.append(to_string(treenode->attr.expAttr.val));
				str.append("  ");
				break;
			case IdeK:
				str.append("IdeK  ");
				switch (treenode->attr.expAttr.varkind)
				{
				case IdV:
					str.append("Id  ");
					str.append(treenode->name[0]);
					str.append("  ");
					break;
				case FieldMembV:
					str.append("FieldMember  ");
					str.append(treenode->name[0]);
					str.append("  ");
					break;
				case ArrayMembV:
					str.append("ArrayMember  ");
					str.append(treenode->name[0]);
					str.append("  ");
					break;
				default:
					str.append("var type error!");
					this->Error = true;
					break;
				}
				/*if (tree->table[0] != NULL)
					fprintf(listing, "%d   %d  ", tree->table[0]->attrIR.More.VarAttr.off, tree->table[0]->attrIR.More.VarAttr.level);*/
				break;
			default:
				str.append("error4!");
				this->Error = true;
				break;
			}
		}break;
		default:
			str.append("error5!");
			this->Error = true;
			break;
		}
		str.append("\r\n");
		for (j = 0; j < 3; j++)
			str+=PrintTree(treenode->child[j]);
		treenode = treenode->sibling;
	}
	/* ����������,ÿ���˳��﷨���ڵ�ʱ�������� */
	
	this->indentation -= 4;
	return str;
}

//����ʽ�� <Program>  :: = ProgramHead  DeclarePart  ProgramBody
void Parser::process1()
{
	symbol.push(DOT);
	symbol.push(ProgramBody);
	symbol.push(DeclarePart);
	symbol.push(ProgramHead);

}

//����ʽ��<ProgramHead>  ::= PROGRAM ProgramName 
void Parser::process2()
{
	symbol.push(ProgramName);
	symbol.push(PROGRAM);
	TreeNode** t = tree.top();
	tree.pop();
	currentP = new TreeNode(this->lineno, PheadK);
	*(t) = currentP;
}

//����ʽ�� <ProgramName> ::=  ID;   
void Parser::process3()
{
	symbol.push(ID);

	currentP->name[currentP->idnum] = currentToken.content;
	currentP->idnum++;
}

//����ʽ�� <DeclarePart> ::= TypeDec  VarDec  FuncDec 
void Parser::process4()
{
	symbol.push(ProcDec);
	symbol.push(VarDec);
	symbol.push(TypeDec);
}

//����ʽ�� <TypeDec> :: = ��
void Parser::process5()
{
	//�պ���
}
//����ʽ�� <TypeDec> ::= TypeDeclaration 
void Parser::process6()
{
	symbol.push(TypeDeclaration);
}

//����ʽ�� <TypeDeclaration> :: = TYPE TypeDecList
void Parser::process7()
{
	symbol.push(TypeDecList);
	symbol.push(TYPE);


	TreeNode** t = tree.top();
	tree.pop();
	currentP = new TreeNode(this->lineno, TypeK); /*����Type��Ϊ��־�Ľ�㣬�����ӽ�㶼����������*/
	(*t) = currentP;							 /*ͷ�����ֵܽ��ָ��ָ��˽��*/
	tree.push(&((*currentP).sibling));			/* ѹ��ָ����������ڵ��ָ��*/
	tree.push(&((*currentP).child[0]));			 /*ѹ��ָ���һ�����������ڵ��ָ��*/
}
//����ʽ�� <TypeDecList> ::= TypeId = TypeDef ; TypeDecMore 
void Parser::process8()
{
	symbol.push(TypeDecMore);
	symbol.push(SEMI);
	symbol.push(TypeName);
	symbol.push(EQ);
	symbol.push(TypeId);

	TreeNode** t = tree.top();
	tree.pop();
	currentP = new TreeNode(this->lineno, DecK); /*����һ����ʾ���������Ľ�㣬�����κ���Ϣ*/

	(*t) = currentP;			 /*���ǵ�һ��������Type���͵��ӽ��ָ��ǰ��㣬 ��������һ�������������ֵܽ��*/

	tree.push(&((*currentP).sibling));
}
//����ʽ��<TypeDecMore> :: = ��
void Parser::process9()
{
	tree.pop();					/*û��������������������ʱ�﷨��ջ����ŵ������һ�����������ڵ���ֵܽڵ㣬����*/
}
//����ʽ�� <TypeDecMore> ::=  TypeDecList  
void Parser::process10()
{
	symbol.push(TypeDecList);
}

//����ʽ�� <TypeId >  ::=  ID 
void Parser::process11()
{
	symbol.push(ID);

	currentP->name[currentP->idnum] = currentToken.content;
	currentP->idnum++;

}
//����ʽ�� <TypeDef> ::=  BaseType 
void Parser::process12()
{
	symbol.push(BaseType);

	/*������������͵����⣬���ﲻ��ֱ����currentP->kind.dec=IntegerK; ��Ӧ����ô��������Ӧ��������*/
	this->dectemp = &(currentP->kind.dec);

}
//����ʽ�� <TypeDef > ::=   StructureType 
void Parser::process13()
{
	symbol.push(StructureType);
}

//����ʽ�� <TypeDef> ::=  ID 
void Parser::process14()
{
	symbol.push(ID);

	/*���������Ͳ���Ϊ���ͱ�ʶ��*/
	(*currentP).kind.dec = IdK;
	currentP->type_name = currentToken.content;
}

//����ʽ��  <BaseType> :: = INTEGER
void Parser::process15()
{
	symbol.push(INTEGER);

	/*���������Ͳ���Ϊ��������*/
	(*this->dectemp) = IntegerK;
}

//����ʽ�� <BaseType> ::=   CHARR
void Parser::process16()
{
	symbol.push(CHARR);

	/*���������Ͳ���Ϊ��������*/
	(*this->dectemp) = CharK;
}
//����ʽ�� <StructureType> :: = ArrayType
void Parser::process17()
{
	symbol.push(ArrayType);
}
//����ʽ��  <StructureType> ::= RecType  
void Parser::process18()
{
	symbol.push(RecType);
}
//����ʽ�� <ArrayType> ::= ARRAY [low..top ] OF BaseType 
void Parser::process19()
{
	symbol.push(BaseType);
	symbol.push(OF);
	symbol.push(RMIDPAREN);
	symbol.push(Top);
	symbol.push(UNDERANGE);
	symbol.push(Low);
	symbol.push(LMIDPAREN);
	symbol.push(ARRAY);

	/*����������Ϊ��������*/
	(*currentP).kind.dec = ArrayK;

	dectemp = &(currentP->attr.arrayAttr.childType);
}

//����ʽ�� <Low>   ::=  INTC  
void Parser::process20()
{
	symbol.push(INTC);

	/*�洢������½�*/
	(*currentP).attr.arrayAttr.low = std::stoi(currentToken.content);
}
//����ʽ�� <Top>  ::=  INTC  
void Parser::process21()
{
	symbol.push(INTC);

	/*�洢������Ͻ�*/
	(*currentP).attr.arrayAttr.up = std::stoi(currentToken.content);

}
//����ʽ�� <RecType > ::=  RECORD  FieldDecList  END 
void Parser::process22()
{
	symbol.push(END);
	symbol.push(FieldDecList);
	symbol.push(RECORD);

	/*���������Ͳ���Ϊ��¼����*/
	(*currentP).kind.dec = RecordK;

	saveP = currentP; /*ѹ�뵱ǰ�ڵ㣬��Ϊ�˴������ص���ǰ�ڵ㣬��Ҫ��Ϊ�˱����������ֱ�ʶ�������ں��濼��*/
	tree.push(&((*currentP).child[0]));
}
//����ʽ�� <FieldDecList > ::= BaseType  IdList ; FieldDecMore 
void Parser::process23()
{
	symbol.push(FieldDecMore);
	symbol.push(SEMI);
	symbol.push(IdList);
	symbol.push(BaseType);

	TreeNode** t = tree.top();
	tree.pop();
	currentP = new TreeNode(this->lineno, DecK);

	this->dectemp = (&(currentP->kind.dec));
	(*t) = currentP;		/*���ǵ�һ��������record���͵��ӽ��ָ��ǰ��㣬��������һ����¼���������ֵܽ��*/
	tree.push(&((*currentP).sibling));
}

//����ʽ�� <FieldDecList>  ::=  ArrayType IdList ; FieldDecMore 
void Parser::process24()
{
	symbol.push(FieldDecMore);
	symbol.push(SEMI);
	symbol.push(IdList);
	symbol.push(ArrayType);


	TreeNode** t = tree.top();
	tree.pop();
	currentP = new TreeNode(this->lineno, DecK); /*���ɼ�¼���͵���һ���򣬲����κ���Ϣ*/
	(*t) = currentP;	/*���ǵ�һ��������record���͵��ӽ��ָ��ǰ��㣬��������һ����¼���������ֵܽ��*/
	tree.push(&((*currentP).sibling));
}

//����ʽ�� <FieldDecMore >  ::=  �� 
void Parser::process25()
{
	/*����û�м�¼���͵���һ�����ˣ��ָ���ǰ��¼���ͽڵ��ָ��*/
	tree.pop();
	currentP = saveP;
}

//����ʽ�� <FieldDecMore> :: = FieldDecList
void Parser::process26()
{
	symbol.push(FieldDecList);
}
//����ʽ�� <IdList >  ::=  id  IdMore 
void Parser::process27()
{
	symbol.push(IdMore);
	symbol.push(ID);

	/*��¼һ�����и���������������Ϣ*/
	currentP->name[currentP->idnum] = currentToken.content;
	currentP->idnum++;
}
//����ʽ�� <IdMore > :: = ��
void Parser::process28()
{
	// �պ��� 
}

//����ʽ�� <IdMore > ::=  , IdList  
void Parser::process29()
{
	symbol.push(IdList);
	symbol.push(COMMA);
}

//����ʽ�� <VarDec>  :: = ��
void Parser::process30()
{
	//�պ����������κζ�����ѡ���������ʽ����ʾ����û�б��������� 
}
//����ʽ�� <VarDec > ::=   VarDeclaration 
void Parser::process31()
{
	symbol.push(VarDeclaration);
}
//����ʽ�� <VarDeclaration> ::= VAR  VarDecList 
void Parser::process32()
{
	symbol.push(VarDecList);
	symbol.push(VAR);

	currentP = new TreeNode(this->lineno, VarK); //*����һ����־���������Ľڵ�*/
	TreeNode** t = tree.top();
	tree.pop();
	(*t) = currentP;
	tree.push(&((*currentP).sibling));  /*ѹ��ָ����������ָ��*/
	tree.push(&((*currentP).child[0])); /*ѹ��ָ���һ�����������ڵ��ָ��*/
}
//����ʽ�� <VarDecList > ::= TypeDef VarIdList ; VarDecMore 
void Parser::process33()
{
	symbol.push(VarDecMore);
	symbol.push(SEMI);
	symbol.push(VarIdList);
	symbol.push(TypeName);

	TreeNode** t = tree.top();
	tree.pop();
	currentP = new TreeNode(this->lineno, DecK);/*����һ���µ������ڵ㣬�����ʾ��������*/
	(*t) = currentP;       /*���ǵ�һ���ڵ㣬�����������ͷָ��ָ��������������ǰһ�����������ĺ��*/
	tree.push(&((*currentP).sibling));
}
//����ʽ�� <VarDecMore > ::=  �� 
void Parser::process34()
{
	tree.pop();
}
//����ʽ�� <VarDecMore > ::= VarDecList 
void Parser::process35()
{
	symbol.push(VarDecList);
}
void Parser::process36()
{
	symbol.push(VarIdMore);
	symbol.push(ID);
	currentP->name[currentP->idnum] = currentToken.content;
	currentP->idnum++;
}

void Parser::process37()
{

}

void Parser::process38()
{
	symbol.push(VarIdList);
	symbol.push(COMMA);
}

void Parser::process39()
{

}

void Parser::process40()
{
	symbol.push(ProcDeclaration);
}

void Parser::process41()
{
	symbol.push(ProcDecMore);
	symbol.push(ProcBody);
	symbol.push(ProcDecPart);
	symbol.push(SEMI);
	symbol.push(RPAREN);
	symbol.push(ParamList);
	symbol.push(LPAREN);
	symbol.push(ProcName);
	symbol.push(PROCEDURE);
	currentP = new TreeNode(currentToken.line, ProcDecK);
	TreeNode** t = tree.top();
	tree.pop();
	(*t) = currentP;

	tree.push(&(currentP->sibling));

	tree.push(&(currentP->child[2]));
	tree.push(&(currentP->child[1]));
	tree.push(&(currentP->child[0]));
}

void Parser::process42()
{

}

void Parser::process43()
{
	symbol.push(ProcDeclaration);
}

void Parser::process44()
{
	symbol.push(ID);
	currentP->name[currentP->idnum] = currentToken.content;
	currentP->idnum++;
}

void Parser::process45()
{
	tree.pop();
}

void Parser::process46()
{
	symbol.push(ParamDecList);
}

void Parser::process47()
{
	symbol.push(ParamMore);
	symbol.push(Param);
}

void Parser::process48()
{
	tree.pop();
}

void Parser::process49()
{
	symbol.push(ParamDecList);
	symbol.push(SEMI);
}

void Parser::process50()
{
	symbol.push(FormList);
	symbol.push(TypeName);
	currentP = new TreeNode(currentToken.line, DecK);
	currentP->attr.procAttr.paramt = valparamtype;
	TreeNode** t = tree.top();
	(*t) = currentP;
	tree.pop();
	tree.push(&(currentP->sibling));
}

void Parser::process51()
{
	symbol.push(FormList);
	symbol.push(TypeName);
	symbol.push(VAR);
	currentP = new TreeNode(currentToken.line, DecK);
	currentP->attr.procAttr.paramt = varparamtype;
	TreeNode** t = tree.top();
	(*t) = currentP;
	tree.pop();
	tree.push(&(currentP->sibling));
}

void Parser::process52()
{
	symbol.push(FidMore);
	symbol.push(ID);
	currentP->name[currentP->idnum] = currentToken.content;
	currentP->idnum++;
}

void Parser::process53()
{

}

void Parser::process54()
{
	symbol.push(FormList);
	symbol.push(COMMA);
}

void Parser::process55()
{
	symbol.push(DeclarePart);
}

void Parser::process56()
{
	symbol.push(ProgramBody);
}

void Parser::process57()
{
	symbol.push(END);
	symbol.push(StmList);
	symbol.push(BEGIN);
	tree.pop();
	currentP = new TreeNode(currentToken.line, StmLK);
	TreeNode** t = tree.top();
	(*t) = currentP;
	tree.pop();
	tree.push(&(currentP->child[0]));
}

void Parser::process58()
{
	symbol.push(StmMore);
	symbol.push(Stm);
}

void Parser::process59()
{
	tree.pop();
}

void Parser::process60()
{
	symbol.push(StmList);
	symbol.push(SEMI);
}

void Parser::process61()
{
	symbol.push(ConditionalStm);
	currentP = new TreeNode(currentToken.line, StmtK);
	currentP->kind.stmt = IfK;
	TreeNode** t = tree.top();
	(*t) = currentP;
	tree.pop();
	tree.push(&(currentP->sibling));
}

void Parser::process62()
{
	symbol.push(LoopStm);
	currentP = new TreeNode(currentToken.line, StmtK);
	currentP->kind.stmt = WhileK;
	TreeNode** t = tree.top();
	(*t) = currentP;
	tree.pop();
	tree.push(&(currentP->sibling));
}

void Parser::process63()
{
	symbol.push(InputStm);
	currentP = new TreeNode(currentToken.line, StmtK);
	currentP->kind.stmt = ReadK;
	TreeNode** t = tree.top();
	(*t) = currentP;
	tree.pop();
	tree.push(&(currentP->sibling));
}

void Parser::process64()
{
	symbol.push(OutputStm);
	currentP = new TreeNode(currentToken.line, StmtK);
	currentP->kind.stmt = WriteK;
	TreeNode** t = tree.top();
	(*t) = currentP;
	tree.pop();
	tree.push(&(currentP->sibling));
}

void Parser::process65()
{
	symbol.push(ReturnStm);
	currentP = new TreeNode(currentToken.line, StmtK);
	currentP->kind.stmt = ReturnK;
	TreeNode** t = tree.top();
	(*t) = currentP;
	tree.pop();
	tree.push(&(currentP->sibling));
}

void Parser::process66()
{
	symbol.push(AssCall);
	symbol.push(ID);
	currentP = new TreeNode(currentToken.line, StmtK);
	currentP->kind.stmt = AssignK;
	TreeNode* t = new TreeNode(currentToken.line, ExpK);
	t->kind.exp = IdeK;
	t->name[0] = currentToken.content;
	t->idnum++;
	currentP->child[0] = t;
	TreeNode** t1 = tree.top();
	(*t1) = currentP;
	tree.pop();
	tree.push(&(currentP->sibling));
}

void Parser::process67()
{
	symbol.push(AssignmentRest);
	currentP->kind.stmt = AssignK;
}

void Parser::process68()
{
	symbol.push(CallStmRest);
	currentP->child[0]->attr.expAttr.varkind = IdV;
	currentP->kind.stmt = CallK;
}

void Parser::process69()
{
	symbol.push(Exp);
	symbol.push(ASSIGN);
	symbol.push(VariMore);
	tree.push(&(currentP->child[1]));
	currentP = currentP->child[0];
	TreeNode* t = new TreeNode(this->lineno, ExpK);
	t->kind.exp = OpK;
	t->attr.expAttr.op = END;
	t->attr.expAttr.varkind = IdV;
	t->attr.expAttr.type = Void;

	opstack.push(t);
}

void Parser::process70()
{
	symbol.push(FI);
	symbol.push(StmList);
	symbol.push(ELSE);
	symbol.push(StmList);
	symbol.push(THEN);
	symbol.push(RelExp);
	symbol.push(IF);
	tree.push(&(currentP->child[2]));
	tree.push(&(currentP->child[1]));
	tree.push(&(currentP->child[0]));
}

//<LoopStm> ::= WHILE RelExp DO StmList ENDWH
void Parser::process71()
{
	symbol.push(ENDWH);
	symbol.push(StmList);
	symbol.push(DO);
	symbol.push(RelExp);
	symbol.push(WHILE);

	/*�������ĵڶ������ӽڵ�child[1]�ĵ�ַѹ���﷨��ջ*/
	tree.push(&(currentP->child[1]));

	/*�������ĵ�һ�����ӽڵ�child[0]�ĵ�ַѹ���﷨��ջ*/
	tree.push(&(currentP->child[0]));
}

//<InputStm> ::= READ ( InVar )
void Parser::process72()
{
	symbol.push(RPAREN);
	symbol.push(Invar);
	symbol.push(LPAREN);
	symbol.push(READ);
}

//<InVar> ::= ID
void Parser::process73()
{
	symbol.push(ID);

	/*����ʶ�����ִ����������ڵ��У���Ϊ������������˽ڵ��еı�
	ʶ�������� 1��*/
	currentP->name[currentP->idnum] = currentToken.content;
	currentP->idnum++;
}

//<OutputStm> ::= WRITE( Exp )
void Parser::process74()
{
	symbol.push(RPAREN);
	symbol.push(Exp);
	symbol.push(LPAREN);
	symbol.push(WRITE);

	/*��ǰд�ڵ�Ķ��ӽڵ��ַ���﷨��ջ*/
	tree.push(&(currentP->child[0]));

	/*����һ���������ڵ�t��������END*/
	TreeNode* t = new TreeNode(this->lineno, ExpK);
	t->kind.exp = OpK;
	t->attr.expAttr.op = END;
	t->attr.expAttr.varkind = IdV;
	t->attr.expAttr.type = Void;
	/*��tѹ�������ջ����Ϊջ�ױ�־*/
	opstack.push(t);
}

//<ReturnStm> ::= RETURN
void Parser::process75()
{
	symbol.push(RETURN);
}
//<CallStmRest> ::= ( ActParamList )
void Parser::process76()
{
	symbol.push(RPAREN);
	symbol.push(ActParamList);
	symbol.push(LPAREN);

	/*ѹ�뺯���������ĵ�һ�����ӽڵ�*/
	tree.push(&(currentP->child[1]));
}

//<ActParamList> ::= ��
void Parser::process77()
{
	tree.pop();
}

//<ActParamList> ::= Exp ActParamMore
void Parser::process78()
{
	symbol.push(ActParamMore);
	symbol.push(Exp);

	/*����һ���������ڵ�t��������END*/
	TreeNode* t = new TreeNode(this->lineno, ExpK);
	t->kind.exp = OpK;
	t->attr.expAttr.op = END;
	t->attr.expAttr.varkind = IdV;
	t->attr.expAttr.type = Void;
	/*��tѹ�������ջ����Ϊջ�ױ�־*/
	opstack.push(t);
}

//<ActParamMore> ::= ��
void Parser::process79()
{
	;
}

//<ActParamMore> ::= , ActParamList
void Parser::process80()
{
	symbol.push(ActParamList);
	symbol.push(COMMA);

	/*ѹ��ǰʵ�νڵ���ֵܽڵ����﷨��ջ��*/
	tree.push(&(currentP->sibling));
}

//<RelExp> ::= Exp OtherRelE
void Parser::process81()
{
	symbol.push(OtherRelE);
	symbol.push(Exp);

	/*����һ���������ڵ�t��������END*/
	TreeNode* t = new TreeNode(this->lineno, ExpK);
	t->kind.exp = OpK;
	t->attr.expAttr.op = END;
	t->attr.expAttr.varkind = IdV;
	t->attr.expAttr.type = Void;
	/*��tѹ�������ջ����Ϊջ�ױ�־*/
	opstack.push(t);

	/*getExpResult��ֵΪ��*/
	getExpResult = false;
}

//<OtherRelE> ::= CmpOp Exp
void Parser::process82()
{
	symbol.push(Exp);
	symbol.push(CmpOp);

	/*����һ�����������ͱ��ʽ�ڵ㣬��¼�����ϵ����������ݡ�*/
	currentP = new TreeNode(this->lineno, ExpK);
	currentP->kind.exp = OpK;
	currentP->attr.expAttr.varkind = IdV;
	currentP->attr.expAttr.type = Void;
	currentP->attr.expAttr.op = currentToken.type;

	LexType  sTop = opstack.top()->attr.expAttr.op;
	while (Priosity(sTop) >= Priosity(currentToken.type))
		/*ջ��������sTop���ȼ����ڻ��ߵ��ڵ�ǰ�����*/
	{
		/*��������ջ���õ��������ڵ�t*/
		TreeNode* t = opstack.top();
		opstack.pop();
		TreeNode* Rnum = numstack.top();
		/*��������ջ���õ��Ҳ������ڵ�Rnum����������ڵ�Lnum*/
		numstack.pop();
		TreeNode* Lnum = numstack.top();
		numstack.pop();
		/*t������ӽڵ�child[0]��ֵLnum,�Ҷ��ӽڵ�child[1]��ֵRnum*/
		t->child[1] = Rnum;
		t->child[0] = Lnum;
		/*��tѹ�������ջ��*/
		numstack.push(t);

		sTop = opstack.top()->attr.expAttr.op;
	}

	/*������ϵ���ʽҲ����,�õ����ʽ�����ʶ getExpResult Ϊ�档*/
	opstack.push(currentP);

	getExpResult = true;
}

//<Exp> ::= Term OtherTerm 
void Parser::process83()
{
	symbol.push(OtherTerm);
	symbol.push(Term);
}

//<OtherTerm> ::= ��
void Parser::process84()
{
	if ((currentToken.type == RPAREN) && (expflag != 0))
		/*��ǰtokenΪ������)����expflag��Ϊ0*/
	{
		while (opstack.top()->attr.expAttr.op != LPAREN)
			/* ������ջ������������( */
		{
			TreeNode* t = opstack.top();
			opstack.pop();
			TreeNode* Rnum = numstack.top();
			numstack.pop();
			TreeNode* Lnum = numstack.top();
			numstack.pop();

			t->child[0] = Lnum;
			t->child[1] = Rnum;
			numstack.push(t);
		}

		opstack.pop();

		expflag--;
	}
	else
		/*��ǰtoken����������)����expflag����0*/
	{
		if ((getExpResult) || (getExpResult2))
			/*getExpResult��getExpResult2Ϊ��*/
		{
			while (opstack.top()->attr.expAttr.op != END)
				/*������ջ������ջ�ױ�ʾEND*/
			{
				TreeNode* t = opstack.top();
				opstack.pop();
				TreeNode* Rnum = numstack.top();
				numstack.pop();
				TreeNode* Lnum = numstack.top();
				numstack.pop();

				t->child[0] = Lnum;
				t->child[1] = Rnum;

				numstack.push(t);
			}

			/*����ջ�ױ�־*/
			opstack.pop();

			/*�Ӳ�����ջ�������ʽ������͸�currentP*/
			currentP = numstack.top();
			numstack.pop();

			/*���﷨��ջt��ʹ��Ӧָ��(*t)��ֵcurrentP*/
			TreeNode** t = tree.top();
			tree.pop();

			/*��ֵָ��ָ����ʽ���ڵ�*/
			(*t) = currentP;

			getExpResult2 = false;
		}
	}
}

//<OtherTerm> ::= AddOp Exp 
void Parser::process85()
{
	symbol.push(Exp);
	symbol.push(AddOp);


	/*����һ���������ڵ�currentP�����ݵ��ڵ�ǰToken�Ĵʷ���Ϣ��Ϊ����*/
	currentP = new TreeNode(this->lineno, ExpK);
	currentP->kind.exp = OpK;
	currentP->attr.expAttr.op = currentToken.type;
	currentP->attr.expAttr.varkind = IdV;
	currentP->attr.expAttr.type = Void;
	LexType  sTop = opstack.top()->attr.expAttr.op;
	while (Priosity(sTop) >= Priosity(currentToken.type))
		/*ջ��������sTop���ȼ����ڻ���ڵ�ǰ������currentP*/
	{
		TreeNode* t = opstack.top();
		opstack.pop();
		TreeNode* Rnum = numstack.top();
		numstack.pop();
		TreeNode* Lnum = numstack.top();
		numstack.pop();
		t->child[0] = Lnum;
		t->child[1] = Rnum;
		numstack.push(t);

		sTop = opstack.top()->attr.expAttr.op;
	}
	/*��ǰ������currentPѹ�������ջ*/
	opstack.push(currentP);
}

//<Term> ::= Factor OtherFactor
void Parser::process86()
{
	symbol.push(OtherFactor);
	symbol.push(Factor);
}

//<OtherFactor> ::= ��
void Parser::process87()
{
	;
}

//<OtherFactor> ::= MultOp Term 
void Parser::process88()
{
	symbol.push(Term);
	symbol.push(MultOp);

	/*����һ���������ڵ�cuttentP�����ݵ��ڵ�ǰtoken�Ĵʷ���ϢΪ*��*/
	currentP = new TreeNode(this->lineno, ExpK);
	currentP->kind.exp = OpK;
	currentP->attr.expAttr.op = currentToken.type;
	currentP->attr.expAttr.varkind = IdV;
	currentP->attr.expAttr.type = Void;

	LexType  sTop = opstack.top()->attr.expAttr.op;
	while (Priosity(sTop) >= Priosity(currentToken.type))
		/*ջ��������sTop���ȼ����ڻ���ڵ�ǰ������currentP*/
	{
		TreeNode* t = opstack.top();
		opstack.pop();
		TreeNode* Rnum = numstack.top();
		numstack.pop();
		TreeNode* Lnum = numstack.top();
		numstack.pop();
		t->child[0] = Lnum;
		t->child[1] = Rnum;

		numstack.push(t);

		sTop = opstack.top()->attr.expAttr.op;
	}
	/*��ǰ������currentPѹ�������ջ*/
	opstack.push(currentP);
}

//<Factor> ::= ( Exp ) 
void Parser::process89()
{
	symbol.push(RPAREN);
	symbol.push(Exp);
	symbol.push(LPAREN);

	/*����һ���������ڵ� t*/
	TreeNode* t = new TreeNode(this->lineno, ExpK);
	t->kind.exp = OpK;
	t->attr.expAttr.op = currentToken.type;
	t->attr.expAttr.varkind = IdV;
	t->attr.expAttr.type = Void;

	/*�����Žڵ�currentP��ջ*/
	opstack.push(t);

	/*δ��������Ÿ���expflag��1*/
	expflag++;
}

//<Factor> ::= INTC
void Parser::process90()
{
	symbol.push(INTC);

	/*����һ�������������ڵ� t*/
	TreeNode* t = new TreeNode(this->lineno, ExpK);
	t->kind.exp = ConstK;
	t->attr.expAttr.varkind = IdV;
	t->attr.expAttr.type = Void;
	t->attr.expAttr.val = std::stoi(currentToken.content);

	/*�����ڵ��������ջ*/
	numstack.push(t);
}

//<Factor> ::= Variable
void Parser::process91()
{
	symbol.push(Variable);
}

//<Variable> ::= ID VariMore
void Parser::process92()
{
	symbol.push(VariMore);
	symbol.push(ID);

	/*����һ�������ı��ʽ�ڵ�*/
	currentP = new TreeNode(this->lineno, ExpK);
	currentP->kind.exp = IdeK;
	currentP->attr.expAttr.varkind = IdV;
	currentP->attr.expAttr.type = Void;		/* ָ�����﷨���ڵ�t��Ա: ���ͼ������typeΪVoid */

	/*����־�����ּ���ڵ���*/
	currentP->name[currentP->idnum] = currentToken.content;

	/*��ʶ������+1*/
	currentP->idnum++;

	numstack.push(currentP);
}

//<VariMore> ::= ��
void Parser::process93()
{
	/*��ʶ������*/
	currentP->attr.expAttr.varkind = IdV;
}

//<VariMore> ::= [ Exp ]
void Parser::process94()
{
	symbol.push(RMIDPAREN);
	symbol.push(Exp);
	symbol.push(LMIDPAREN);

	/*�����ľ�����������Ϊ�����Ա����*/
	currentP->attr.expAttr.varkind = ArrayMembV;
	tree.push(&currentP->child[0]);

	/*Ҫ������ʽ����ѹ�������ջһ������������ȼ��������ջ�ױ�־*/
	TreeNode* t = new TreeNode(this->lineno, ExpK);
	t->kind.exp = OpK;
	t->attr.expAttr.op = END;
	t->attr.expAttr.varkind = IdV;
	t->attr.expAttr.type = Void;
	opstack.push(t);

	getExpResult2 = true;
}

//<VariMore> ::= . FieldVar
void Parser::process95()
{
	symbol.push(FieldVar);
	symbol.push(DOT);

	/*��ǰ�����ڵ�ľ�����������Ϊ���Ա���ͱ���*/
	currentP->attr.expAttr.varkind = FieldMembV;

	/*ѹ�����Ա�����ڵ�Ķ��ӽڵ�*/
	tree.push(&currentP->child[0]);
}

//<FieldVar> ::= ID FieldVarMore
void Parser::process96()
{
	symbol.push(FieldVarMore);
	symbol.push(ID);

	/*��¼��ĳ�Ա*/

	currentP = new TreeNode(this->lineno, ExpK);
	currentP->kind.exp = IdeK;
	currentP->attr.expAttr.varkind = IdV;
	currentP->attr.expAttr.type = Void;		/* ָ�����﷨���ڵ�t��Ա: ���ͼ������typeΪVoid */

	/*����־��������ڵ���*/
	currentP->name[currentP->idnum] = currentToken.content;

	currentP->idnum++;

	TreeNode** t = tree.top();
	tree.pop();

	(*t) = currentP;
}

//<FieldVarMore> ::= ��
void Parser::process97()
{
	/*���Ա�Ǳ�ʶ������*/
	currentP->attr.expAttr.varkind = IdV;
}

//<FieldVarMore> ::= [ Exp ]
void Parser::process98()
{
	symbol.push(RMIDPAREN);
	symbol.push(Exp);
	symbol.push(LMIDPAREN);

	currentP->attr.expAttr.varkind = ArrayMembV;
	tree.push(&currentP->child[0]);

	TreeNode* t = new TreeNode(this->lineno, ExpK);
	t->kind.exp = OpK;
	t->attr.expAttr.varkind = IdV;
	t->attr.expAttr.type = Void;		/* ָ�����﷨���ڵ�t��Ա: ���ͼ������typeΪVoid */
	t->attr.expAttr.op = END;
	opstack.push(t);

	getExpResult2 = true;
}

//<CmpOp> ::= LT
void Parser::process99()
{
	symbol.push(LT);
}

//<CmpOp> ::= EQ
void Parser::process100()
{
	symbol.push(EQ);
}

//<AddOp> ::= PLUS
void Parser::process101()
{
	symbol.push(PLUS);
}

//<AddOp> ::= MINUS
void Parser::process102()
{
	symbol.push(MINUS);
}

//<MultOp> ::= TIMES
void Parser::process103()
{
	symbol.push(TIMES);
}

//<MultOp> ::= OVER
void Parser::process104()
{
	symbol.push(OVER);
}
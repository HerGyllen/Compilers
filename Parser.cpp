#include "stdafx.h"
#include "Parser.h"

static string 词法类型[100] = { "ENDFILE", "ERRORR" ,
"PROGRAM", "PROCEDURE", "TYPE", "VAR", "IF",
"THEN", "ELSE"," FI", "WHILE", "DO",
"ENDWH", "BEGIN", "END", "READ", "WRITE",
"ARRAY", "OF", "RECORD", "RETURN",
"INTEGER", "CHARR",
/* 多字符单词符号 */
"ID", "INTC","CHARC",
/*特殊符号 */
"ASSIGN", "EQ", "LT", "PLUS", "MINUS",
"TIMES", "OVER"," LPAREN", "RPAREN", "DOT",
"COLON", "SEMI","COMMA"," LMIDPAREN", "RMIDPAREN",
"UNDERANGE"
};
//符号栈和语法树栈的初始化
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
	this->symbol.push(Program);//可以直接压入vt或lextape，会自动调用构造函数
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
			str.append("行数：");
			str.append(to_string(lineno));
			str.append("文件提前结束\r\n");
			this->Error = true;
			break;
		}
		Symbol curSym = this->symbol.top();
		//当前栈顶为终极符
		if (curSym.vt == vt_uninit) {
			if (curSym.lex == currentToken.type) {
				this->symbol.pop();
				/*测试用*/
				if (currentToken.type == ID) {
					str.append("行数: ");
					str.append(to_string(currentToken.line));
					str.append("    ");
					str.append(to_string(currentToken.type));
					str.append("     ");
					str.append(currentToken.content);
					str.append("\r\n");
				}
				else {
					str.append("行数: ");
					str.append(to_string(currentToken.line));
					str.append("    ");
					str.append(to_string(currentToken.type));
					str.append("     ");
					str.append(词法类型[currentToken.type]);
					str.append("\r\n");

				}
				Tokeniterator++;			//读取下一个token
				this->currentToken = *Tokeniterator;

			}
			else {
				str.append("行数：");
				str.append(to_string(lineno));
				str.append("    非期望单词错");
				str.append("\r\n");
				this->Error = true;
			}
		}
		//当前栈顶为非终极符
		else {
			this->symbol.pop();
			int pnum = t[curSym.vt][currentToken.type];
			if (pnum == -1) {
				str.append("行数：");
				str.append(to_string(lineno));
				str.append("    没有相应产生式，错误");
				str.append("\r\n");
				this->Error = true;
			}
			str.append(predict(pnum));
		}
	}
	Token token = *Tokeniterator;
	if (token.type == ENDFILE && this->symbol.empty() && this->Error == false)
	{
		str.append("语法分析结束，未发现错误");
		str.append("\r\n");
	}
	return str;
}

string Parser::predict(int pnum) {
	string str = "";
	str.append("选用产生式序号:  ");
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
	/*以字符串的形式输出*/
	string str = "";
	int j;
	/* 增量缩进宏,每次进入语法树节点都进行增量缩进 */
	this->indentation += 4;
	while (treenode != NULL)
	{
		if ((int)(treenode->lineno == 0))
			str.append( "         "); //9个空格
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

		string space(this->indentation, ' ');	//打印相应的空格,进行缩进
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
	/* 减量缩进宏,每次退出语法树节点时减量缩进 */
	
	this->indentation -= 4;
	return str;
}

//产生式： <Program>  :: = ProgramHead  DeclarePart  ProgramBody
void Parser::process1()
{
	symbol.push(DOT);
	symbol.push(ProgramBody);
	symbol.push(DeclarePart);
	symbol.push(ProgramHead);

}

//产生式：<ProgramHead>  ::= PROGRAM ProgramName 
void Parser::process2()
{
	symbol.push(ProgramName);
	symbol.push(PROGRAM);
	TreeNode** t = tree.top();
	tree.pop();
	currentP = new TreeNode(this->lineno, PheadK);
	*(t) = currentP;
}

//产生式： <ProgramName> ::=  ID;   
void Parser::process3()
{
	symbol.push(ID);

	currentP->name[currentP->idnum] = currentToken.content;
	currentP->idnum++;
}

//产生式： <DeclarePart> ::= TypeDec  VarDec  FuncDec 
void Parser::process4()
{
	symbol.push(ProcDec);
	symbol.push(VarDec);
	symbol.push(TypeDec);
}

//产生式： <TypeDec> :: = ε
void Parser::process5()
{
	//空函数
}
//产生式： <TypeDec> ::= TypeDeclaration 
void Parser::process6()
{
	symbol.push(TypeDeclaration);
}

//产生式： <TypeDeclaration> :: = TYPE TypeDecList
void Parser::process7()
{
	symbol.push(TypeDecList);
	symbol.push(TYPE);


	TreeNode** t = tree.top();
	tree.pop();
	currentP = new TreeNode(this->lineno, TypeK); /*生成Type作为标志的结点，它的子结点都是类型声明*/
	(*t) = currentP;							 /*头结点的兄弟结点指针指向此结点*/
	tree.push(&((*currentP).sibling));			/* 压入指向变量声明节点的指针*/
	tree.push(&((*currentP).child[0]));			 /*压入指向第一个类型声明节点的指针*/
}
//产生式： <TypeDecList> ::= TypeId = TypeDef ; TypeDecMore 
void Parser::process8()
{
	symbol.push(TypeDecMore);
	symbol.push(SEMI);
	symbol.push(TypeName);
	symbol.push(EQ);
	symbol.push(TypeId);

	TreeNode** t = tree.top();
	tree.pop();
	currentP = new TreeNode(this->lineno, DecK); /*生成一个表示类型声明的结点，不添任何信息*/

	(*t) = currentP;			 /*若是第一个，则是Type类型的子结点指向当前结点， 否则，是上一个类型声明的兄弟结点*/

	tree.push(&((*currentP).sibling));
}
//产生式：<TypeDecMore> :: = ε
void Parser::process9()
{
	tree.pop();					/*没有其它的类型声明，这时语法树栈顶存放的是最后一个类型声明节点的兄弟节点，弹出*/
}
//产生式： <TypeDecMore> ::=  TypeDecList  
void Parser::process10()
{
	symbol.push(TypeDecList);
}

//产生式： <TypeId >  ::=  ID 
void Parser::process11()
{
	symbol.push(ID);

	currentP->name[currentP->idnum] = currentToken.content;
	currentP->idnum++;

}
//产生式： <TypeDef> ::=  BaseType 
void Parser::process12()
{
	symbol.push(BaseType);

	/*由于数组基类型的问题，这里不能直接用currentP->kind.dec=IntegerK; 而应该这么做，以适应所有情形*/
	this->dectemp = &(currentP->kind.dec);

}
//产生式： <TypeDef > ::=   StructureType 
void Parser::process13()
{
	symbol.push(StructureType);
}

//产生式： <TypeDef> ::=  ID 
void Parser::process14()
{
	symbol.push(ID);

	/*声明的类型部分为类型标识符*/
	(*currentP).kind.dec = IdK;
	currentP->type_name = currentToken.content;
}

//产生式：  <BaseType> :: = INTEGER
void Parser::process15()
{
	symbol.push(INTEGER);

	/*声明的类型部分为整数类型*/
	(*this->dectemp) = IntegerK;
}

//产生式： <BaseType> ::=   CHARR
void Parser::process16()
{
	symbol.push(CHARR);

	/*声明的类型部分为整数类型*/
	(*this->dectemp) = CharK;
}
//产生式： <StructureType> :: = ArrayType
void Parser::process17()
{
	symbol.push(ArrayType);
}
//产生式：  <StructureType> ::= RecType  
void Parser::process18()
{
	symbol.push(RecType);
}
//产生式： <ArrayType> ::= ARRAY [low..top ] OF BaseType 
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

	/*声明的类型为数组类型*/
	(*currentP).kind.dec = ArrayK;

	dectemp = &(currentP->attr.arrayAttr.childType);
}

//产生式： <Low>   ::=  INTC  
void Parser::process20()
{
	symbol.push(INTC);

	/*存储数组的下界*/
	(*currentP).attr.arrayAttr.low = std::stoi(currentToken.content);
}
//产生式： <Top>  ::=  INTC  
void Parser::process21()
{
	symbol.push(INTC);

	/*存储数组的上界*/
	(*currentP).attr.arrayAttr.up = std::stoi(currentToken.content);

}
//产生式： <RecType > ::=  RECORD  FieldDecList  END 
void Parser::process22()
{
	symbol.push(END);
	symbol.push(FieldDecList);
	symbol.push(RECORD);

	/*声明的类型部分为记录类型*/
	(*currentP).kind.dec = RecordK;

	saveP = currentP; /*压入当前节点，是为了处理完后回到当前节点，主要是为了变量声明部分标识符部分在后面考虑*/
	tree.push(&((*currentP).child[0]));
}
//产生式： <FieldDecList > ::= BaseType  IdList ; FieldDecMore 
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
	(*t) = currentP;		/*若是第一个，则是record类型的子结点指向当前结点，否则，是上一个纪录域声明的兄弟结点*/
	tree.push(&((*currentP).sibling));
}

//产生式： <FieldDecList>  ::=  ArrayType IdList ; FieldDecMore 
void Parser::process24()
{
	symbol.push(FieldDecMore);
	symbol.push(SEMI);
	symbol.push(IdList);
	symbol.push(ArrayType);


	TreeNode** t = tree.top();
	tree.pop();
	currentP = new TreeNode(this->lineno, DecK); /*生成记录类型的下一个域，不添任何信息*/
	(*t) = currentP;	/*若是第一个，则是record类型的子结点指向当前结点，否则，是上一个纪录域声明的兄弟结点*/
	tree.push(&((*currentP).sibling));
}

//产生式： <FieldDecMore >  ::=  ε 
void Parser::process25()
{
	/*后面没有记录类型的下一个域了，恢复当前纪录类型节点的指针*/
	tree.pop();
	currentP = saveP;
}

//产生式： <FieldDecMore> :: = FieldDecList
void Parser::process26()
{
	symbol.push(FieldDecList);
}
//产生式： <IdList >  ::=  id  IdMore 
void Parser::process27()
{
	symbol.push(IdMore);
	symbol.push(ID);

	/*纪录一个域中各个变量的语义信息*/
	currentP->name[currentP->idnum] = currentToken.content;
	currentP->idnum++;
}
//产生式： <IdMore > :: = ε
void Parser::process28()
{
	// 空函数 
}

//产生式： <IdMore > ::=  , IdList  
void Parser::process29()
{
	symbol.push(IdList);
	symbol.push(COMMA);
}

//产生式： <VarDec>  :: = ε
void Parser::process30()
{
	//空函数，不做任何动作。选择这个产生式，表示程序没有变量声明。 
}
//产生式： <VarDec > ::=   VarDeclaration 
void Parser::process31()
{
	symbol.push(VarDeclaration);
}
//产生式： <VarDeclaration> ::= VAR  VarDecList 
void Parser::process32()
{
	symbol.push(VarDecList);
	symbol.push(VAR);

	currentP = new TreeNode(this->lineno, VarK); //*生成一个标志变量声明的节点*/
	TreeNode** t = tree.top();
	tree.pop();
	(*t) = currentP;
	tree.push(&((*currentP).sibling));  /*压入指向函数声明的指针*/
	tree.push(&((*currentP).child[0])); /*压入指向第一个变量声明节点的指针*/
}
//产生式： <VarDecList > ::= TypeDef VarIdList ; VarDecMore 
void Parser::process33()
{
	symbol.push(VarDecMore);
	symbol.push(SEMI);
	symbol.push(VarIdList);
	symbol.push(TypeName);

	TreeNode** t = tree.top();
	tree.pop();
	currentP = new TreeNode(this->lineno, DecK);/*建立一个新的声明节点，这里表示变量声明*/
	(*t) = currentP;       /*若是第一个节点，则变量声明的头指针指向它，否则它是前一个变量声明的后继*/
	tree.push(&((*currentP).sibling));
}
//产生式： <VarDecMore > ::=  ε 
void Parser::process34()
{
	tree.pop();
}
//产生式： <VarDecMore > ::= VarDecList 
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

	/*条件语句的第二个儿子节点child[1]的地址压入语法树栈*/
	tree.push(&(currentP->child[1]));

	/*条件语句的第一个儿子节点child[0]的地址压入语法树栈*/
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

	/*将标识符名字存入输入语句节点中，作为输入变量名，此节点中的标
	识符个数加 1。*/
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

	/*当前写节点的儿子节点地址入语法树栈*/
	tree.push(&(currentP->child[0]));

	/*创建一个操作符节点t，内容是END*/
	TreeNode* t = new TreeNode(this->lineno, ExpK);
	t->kind.exp = OpK;
	t->attr.expAttr.op = END;
	t->attr.expAttr.varkind = IdV;
	t->attr.expAttr.type = Void;
	/*把t压入操作符栈，作为栈底标志*/
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

	/*压入函数调用语句的第一个儿子节点*/
	tree.push(&(currentP->child[1]));
}

//<ActParamList> ::= ε
void Parser::process77()
{
	tree.pop();
}

//<ActParamList> ::= Exp ActParamMore
void Parser::process78()
{
	symbol.push(ActParamMore);
	symbol.push(Exp);

	/*创建一个操作符节点t，内容是END*/
	TreeNode* t = new TreeNode(this->lineno, ExpK);
	t->kind.exp = OpK;
	t->attr.expAttr.op = END;
	t->attr.expAttr.varkind = IdV;
	t->attr.expAttr.type = Void;
	/*把t压入操作符栈，作为栈底标志*/
	opstack.push(t);
}

//<ActParamMore> ::= ε
void Parser::process79()
{
	;
}

//<ActParamMore> ::= , ActParamList
void Parser::process80()
{
	symbol.push(ActParamList);
	symbol.push(COMMA);

	/*压当前实参节点的兄弟节点入语法树栈。*/
	tree.push(&(currentP->sibling));
}

//<RelExp> ::= Exp OtherRelE
void Parser::process81()
{
	symbol.push(OtherRelE);
	symbol.push(Exp);

	/*创建一个操作符节点t，内容是END*/
	TreeNode* t = new TreeNode(this->lineno, ExpK);
	t->kind.exp = OpK;
	t->attr.expAttr.op = END;
	t->attr.expAttr.varkind = IdV;
	t->attr.expAttr.type = Void;
	/*把t压入操作符栈，作为栈底标志*/
	opstack.push(t);

	/*getExpResult赋值为假*/
	getExpResult = false;
}

//<OtherRelE> ::= CmpOp Exp
void Parser::process82()
{
	symbol.push(Exp);
	symbol.push(CmpOp);

	/*建立一个操作符类型表达式节点，记录这个关系运算符的内容。*/
	currentP = new TreeNode(this->lineno, ExpK);
	currentP->kind.exp = OpK;
	currentP->attr.expAttr.varkind = IdV;
	currentP->attr.expAttr.type = Void;
	currentP->attr.expAttr.op = currentToken.type;

	LexType  sTop = opstack.top()->attr.expAttr.op;
	while (Priosity(sTop) >= Priosity(currentToken.type))
		/*栈顶操作符sTop优先级高于或者等于当前运算符*/
	{
		/*弹操作符栈，得到操作符节点t*/
		TreeNode* t = opstack.top();
		opstack.pop();
		TreeNode* Rnum = numstack.top();
		/*弹操作数栈，得到右操作数节点Rnum和左操作数节点Lnum*/
		numstack.pop();
		TreeNode* Lnum = numstack.top();
		numstack.pop();
		/*t的左儿子节点child[0]赋值Lnum,右儿子节点child[1]赋值Rnum*/
		t->child[1] = Rnum;
		t->child[0] = Lnum;
		/*把t压入操作数栈。*/
		numstack.push(t);

		sTop = opstack.top()->attr.expAttr.op;
	}

	/*整个关系表达式也结束,得到表达式结果标识 getExpResult 为真。*/
	opstack.push(currentP);

	getExpResult = true;
}

//<Exp> ::= Term OtherTerm 
void Parser::process83()
{
	symbol.push(OtherTerm);
	symbol.push(Term);
}

//<OtherTerm> ::= ε
void Parser::process84()
{
	if ((currentToken.type == RPAREN) && (expflag != 0))
		/*当前token为右括号)而且expflag不为0*/
	{
		while (opstack.top()->attr.expAttr.op != LPAREN)
			/* 操作符栈顶不是左括号( */
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
		/*当前token不是右括号)或者expflag不是0*/
	{
		if ((getExpResult) || (getExpResult2))
			/*getExpResult或getExpResult2为真*/
		{
			while (opstack.top()->attr.expAttr.op != END)
				/*操作符栈顶不是栈底表示END*/
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

			/*弹出栈底标志*/
			opstack.pop();

			/*从操作数栈弹出表达式结果，送给currentP*/
			currentP = numstack.top();
			numstack.pop();

			/*弹语法树栈t，使相应指针(*t)赋值currentP*/
			TreeNode** t = tree.top();
			tree.pop();

			/*赋值指针指向表达式根节点*/
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


	/*创建一个操作符节点currentP，内容等于当前Token的词法信息，为＋或－*/
	currentP = new TreeNode(this->lineno, ExpK);
	currentP->kind.exp = OpK;
	currentP->attr.expAttr.op = currentToken.type;
	currentP->attr.expAttr.varkind = IdV;
	currentP->attr.expAttr.type = Void;
	LexType  sTop = opstack.top()->attr.expAttr.op;
	while (Priosity(sTop) >= Priosity(currentToken.type))
		/*栈顶操作符sTop优先级高于或等于当前操作符currentP*/
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
	/*当前操作符currentP压入操作符栈*/
	opstack.push(currentP);
}

//<Term> ::= Factor OtherFactor
void Parser::process86()
{
	symbol.push(OtherFactor);
	symbol.push(Factor);
}

//<OtherFactor> ::= ε
void Parser::process87()
{
	;
}

//<OtherFactor> ::= MultOp Term 
void Parser::process88()
{
	symbol.push(Term);
	symbol.push(MultOp);

	/*创建一个操作符节点cuttentP，内容等于当前token的词法信息为*或*/
	currentP = new TreeNode(this->lineno, ExpK);
	currentP->kind.exp = OpK;
	currentP->attr.expAttr.op = currentToken.type;
	currentP->attr.expAttr.varkind = IdV;
	currentP->attr.expAttr.type = Void;

	LexType  sTop = opstack.top()->attr.expAttr.op;
	while (Priosity(sTop) >= Priosity(currentToken.type))
		/*栈顶操作符sTop优先级高于或等于当前操作符currentP*/
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
	/*当前操作符currentP压入操作符栈*/
	opstack.push(currentP);
}

//<Factor> ::= ( Exp ) 
void Parser::process89()
{
	symbol.push(RPAREN);
	symbol.push(Exp);
	symbol.push(LPAREN);

	/*建立一个操作符节点 t*/
	TreeNode* t = new TreeNode(this->lineno, ExpK);
	t->kind.exp = OpK;
	t->attr.expAttr.op = currentToken.type;
	t->attr.expAttr.varkind = IdV;
	t->attr.expAttr.type = Void;

	/*左括号节点currentP入栈*/
	opstack.push(t);

	/*未配对左括号个数expflag加1*/
	expflag++;
}

//<Factor> ::= INTC
void Parser::process90()
{
	symbol.push(INTC);

	/*建立一个常量操作数节点 t*/
	TreeNode* t = new TreeNode(this->lineno, ExpK);
	t->kind.exp = ConstK;
	t->attr.expAttr.varkind = IdV;
	t->attr.expAttr.type = Void;
	t->attr.expAttr.val = std::stoi(currentToken.content);

	/*常数节点入操作数栈*/
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

	/*创建一个变量的表达式节点*/
	currentP = new TreeNode(this->lineno, ExpK);
	currentP->kind.exp = IdeK;
	currentP->attr.expAttr.varkind = IdV;
	currentP->attr.expAttr.type = Void;		/* 指定新语法树节点t成员: 类型检查类型type为Void */

	/*将标志符名字记入节点中*/
	currentP->name[currentP->idnum] = currentToken.content;

	/*标识符个数+1*/
	currentP->idnum++;

	numstack.push(currentP);
}

//<VariMore> ::= ε
void Parser::process93()
{
	/*标识符变量*/
	currentP->attr.expAttr.varkind = IdV;
}

//<VariMore> ::= [ Exp ]
void Parser::process94()
{
	symbol.push(RMIDPAREN);
	symbol.push(Exp);
	symbol.push(LMIDPAREN);

	/*变量的具体类型设置为数组成员变量*/
	currentP->attr.expAttr.varkind = ArrayMembV;
	tree.push(&currentP->child[0]);

	/*要进入表达式处理，压入操作符栈一个具有最低优先级的特殊的栈底标志*/
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

	/*当前变量节点的具体类型设置为域成员类型变量*/
	currentP->attr.expAttr.varkind = FieldMembV;

	/*压入域成员变量节点的儿子节点*/
	tree.push(&currentP->child[0]);
}

//<FieldVar> ::= ID FieldVarMore
void Parser::process96()
{
	symbol.push(FieldVarMore);
	symbol.push(ID);

	/*纪录域的成员*/

	currentP = new TreeNode(this->lineno, ExpK);
	currentP->kind.exp = IdeK;
	currentP->attr.expAttr.varkind = IdV;
	currentP->attr.expAttr.type = Void;		/* 指定新语法树节点t成员: 类型检查类型type为Void */

	/*将标志符名记入节点中*/
	currentP->name[currentP->idnum] = currentToken.content;

	currentP->idnum++;

	TreeNode** t = tree.top();
	tree.pop();

	(*t) = currentP;
}

//<FieldVarMore> ::= ε
void Parser::process97()
{
	/*域成员是标识符变量*/
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
	t->attr.expAttr.type = Void;		/* 指定新语法树节点t成员: 类型检查类型type为Void */
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
#pragma once
#include<stack>
#include"TreeNode.h"
#include "Token.h"
struct Symbol {
	VT vt;
	LexType lex;
	Symbol(VT vt) {
		this->lex = lex_uninit;
		this->vt = vt;
	}
	Symbol(LexType lex) {
		this->vt = vt_uninit;
		this->lex = lex;
	}
};

class Parser
{
public:
	/*Parse过程中使用到的数据结构*/
	TreeNode* root;					//语法树根
	stack<Symbol> symbol;			//符号栈
	stack<TreeNode**> tree;			//语法树栈
	stack<TreeNode*> opstack;		//操作符栈
	stack<TreeNode*> numstack;		//操作树栈
	//Parse过程中使用到的变量
	bool Error;					//是否发生错误
	int lineno;

	Token  currentToken;
	TreeNode* currentP;			//纪录当前语法树节点
	TreeNode* saveP;			//保存当前指针，以便修改后，将其恢复
	Dec* dectemp;				//指向某语法树节点Kind->dec域的指针

	int indentation = 0;

	/*纪录表达式中，未匹配的左括号数目*/

	int  expflag = 0;
	/*判断简单表达式处理结束，整个表达式是否处理结束标识*/
	/*当是条件表达式时，取假值，简单表达式时，取真值*/
	/*用于函数preocess84*/

	int  getExpResult = 1;
	/*仅用于数组变量，故初始化为假，遇到数组变量时，将其
	  改变为真，以便在函数process84中，即算术表达式结束时，
	  从语法树栈中弹出相应指针，将数组下标表达式的结构链入
	  节点中*/

	int  getExpResult2 = 0;

	Parser();
	//语法分析主要过程
	string Parse(vector<Token>& Tokenlist);
	string predict(int pnum);
	int Priosity(LexType op);

	//语法树打印
	string PrintTree(TreeNode* treenode);

	//产生式处理函数:
	void process1();
	void process2();
	void process3();
	void process4();
	void process5();
	void process6();
	void process7();
	void process8();
	void process9();
	void process10();
	void process11();
	void process12();
	void process13();
	void process14();
	void process15();
	void process16();
	void process17();
	void process18();
	void process19();
	void process20();
	void process21();
	void process22();
	void process23();
	void process24();
	void process25();
	void process26();
	void process27();
	void process28();
	void process29();
	void process30();
	void process31();
	void process32();
	void process33();
	void process34();
	void process35();
	void process36();
	void process37();
	void process38();
	void process39();
	void process40();
	void process41();
	void process42();
	void process43();
	void process44();
	void process45();
	void process46();
	void process47();
	void process48();
	void process49();
	void process50();
	void process51();
	void process52();
	void process53();
	void process54();
	void process55();
	void process56();
	void process57();
	void process58();
	void process59();
	void process60();
	void process61();
	void process62();
	void process63();
	void process64();
	void process65();
	void process66();
	void process67();
	void process68();
	void process69();
	void process70();
	void process71();
	void process72();
	void process73();
	void process74();
	void process75();
	void process76();
	void process77();
	void process78();
	void process79();
	void process80();
	void process81();
	void process82();
	void process83();
	void process84();
	void process85();
	void process86();
	void process87();
	void process88();
	void process89();
	void process90();
	void process91();
	void process92();
	void process93();
	void process94();
	void process95();
	void process96();
	void process97();
	void process98();
	void process99();
	void process100();
	void process101();
	void process102();
	void process103();
	void process104();
};


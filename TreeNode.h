#ifndef _TREENODE_H
#define _TREENODE_H
#include<iostream>
#pragma once
#include"LL1_table.h"
using namespace std;

struct symbtable {
	string name;
	symbtable* next;
};

/*语法树标志结点:程序入口，程序头，类型声明，变量声明，
过程声明,程序体，声明结点、语句结点、表达式结点*/
enum Nodekind { ProK, PheadK, TypeK, VarK, ProcDecK, StmLK, DecK, StmtK, ExpK };

//语法树具体结点--声明:数组，字符，整数，记录，标识符
enum Dec { ArrayK, CharK, IntegerK, RecordK, IdK };

//语法树具体结点--语句：if、while、赋值、read、write、调用、return
enum Stmt { IfK, WhileK, AssignK, ReadK, WriteK, CallK, ReturnK };

//语法树具体结点--运算分量：运算符、常数、标识符
enum ExpType { OpK, ConstK, IdeK };

//数字作参数还是标识符作参数
enum Paramt { valparamtype, varparamtype };

enum Varkind { IdV, ArrayMembV, FieldMembV };

enum Type { Void, Integer, Boolean };

//语法树具体结点的类型，三选一
struct Kind {
	Dec dec;
	Stmt stmt;
	ExpType exp;
};

//定义数组时记录额外信息
struct ArrayAttr {
	int low;//数组下界
	int up;//数组上界
	Dec childType;//数组元素类型
};

//过程声明时记录参数信息
struct ProcAttr {
	Paramt paramt;
};

//为表达式记录额外信息
struct ExpAttr {
	LexType op;
	int val;
	Varkind varkind;
	Type type;
};

//数组信息、过程参数列表、表达式信息三选一
struct Attr {
	ArrayAttr arrayAttr;
	ProcAttr procAttr;
	ExpAttr expAttr;
};

class TreeNode
{
public:
	TreeNode* child[3] = { NULL,NULL,NULL };//指向子节点语法树
	TreeNode* sibling = NULL;//指向兄弟结点（并列的多个语句）

	int lineno;//在源程序对应行号

	Nodekind nodekind;

	Kind kind;//语法树具体结点，包含了声明、语句、表达式三种

	int idnum = 0;//一个结点中标识符个数
	string name[10];//标识符名称
	symbtable* table[10];//标识符在标识符表中对应的数组下标

	string type_name;//如果是声明结点，记录声明的类型

	Attr attr;//当结点为数组声明、过程声明、表达式时用于记录额外信息

	TreeNode(int lineno, Nodekind nodekind);

};

#endif
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

/*�﷨����־���:������ڣ�����ͷ����������������������
��������,�����壬������㡢����㡢���ʽ���*/
enum Nodekind { ProK, PheadK, TypeK, VarK, ProcDecK, StmLK, DecK, StmtK, ExpK };

//�﷨��������--����:���飬�ַ�����������¼����ʶ��
enum Dec { ArrayK, CharK, IntegerK, RecordK, IdK };

//�﷨��������--��䣺if��while����ֵ��read��write�����á�return
enum Stmt { IfK, WhileK, AssignK, ReadK, WriteK, CallK, ReturnK };

//�﷨��������--������������������������ʶ��
enum ExpType { OpK, ConstK, IdeK };

//�������������Ǳ�ʶ��������
enum Paramt { valparamtype, varparamtype };

enum Varkind { IdV, ArrayMembV, FieldMembV };

enum Type { Void, Integer, Boolean };

//�﷨������������ͣ���ѡһ
struct Kind {
	Dec dec;
	Stmt stmt;
	ExpType exp;
};

//��������ʱ��¼������Ϣ
struct ArrayAttr {
	int low;//�����½�
	int up;//�����Ͻ�
	Dec childType;//����Ԫ������
};

//��������ʱ��¼������Ϣ
struct ProcAttr {
	Paramt paramt;
};

//Ϊ���ʽ��¼������Ϣ
struct ExpAttr {
	LexType op;
	int val;
	Varkind varkind;
	Type type;
};

//������Ϣ�����̲����б����ʽ��Ϣ��ѡһ
struct Attr {
	ArrayAttr arrayAttr;
	ProcAttr procAttr;
	ExpAttr expAttr;
};

class TreeNode
{
public:
	TreeNode* child[3] = { NULL,NULL,NULL };//ָ���ӽڵ��﷨��
	TreeNode* sibling = NULL;//ָ���ֵܽ�㣨���еĶ����䣩

	int lineno;//��Դ�����Ӧ�к�

	Nodekind nodekind;

	Kind kind;//�﷨�������㣬��������������䡢���ʽ����

	int idnum = 0;//һ������б�ʶ������
	string name[10];//��ʶ������
	symbtable* table[10];//��ʶ���ڱ�ʶ�����ж�Ӧ�������±�

	string type_name;//�����������㣬��¼����������

	Attr attr;//�����Ϊ�����������������������ʽʱ���ڼ�¼������Ϣ

	TreeNode(int lineno, Nodekind nodekind);

};

#endif
#pragma once
#ifndef _LL1_TABLE_H
#define _LL1_TABLE_H

enum VT {
	Program, ProgramHead, ProgramName, DeclarePart, TypeDec,
	TypeDeclaration, TypeDecList, TypeDecMore, TypeId, TypeName,
	BaseType, StructureType, ArrayType, Low, Top,
	RecType, FieldDecList, FieldDecMore, IdList, IdMore,
	VarDec, VarDeclaration, VarDecList, VarDecMore, VarIdList,
	VarIdMore, ProcDec, ProcDeclaration, ProcDecMore, ProcName,
	ParamList, ParamDecList, ParamMore, Param, FormList,
	FidMore, ProcDecPart, ProcBody, ProgramBody, StmList,
	StmMore, Stm, AssCall, AssignmentRest, ConditionalStm,
	LoopStm, InputStm, Invar, OutputStm, ReturnStm,
	CallStmRest, ActParamList, ActParamMore, RelExp, OtherRelE,
	Exp, OtherTerm, Term, OtherFactor, Factor,
	Variable, VariMore, FieldVar, FieldVarMore, CmpOp,
	AddOp, MultOp, vt_uninit
};

/********************** ���ʵĴʷ����� ********************/
typedef enum
{
	/* ���ǵ��ʷ��� */
	ENDFILE, ERRORR,
	/* ������ */
	PROGRAM, PROCEDURE, TYPE, VAR, IF,
	THEN, ELSE, FI, WHILE, DO,
	ENDWH, BEGIN, END, READ, WRITE,
	ARRAY, OF, RECORD, RETURN,

	INTEGER, CHARR,
	/* ���ַ����ʷ��� */
	ID, INTC, CHARC,
	/*������� */
	ASSIGN, EQ, LT, PLUS, MINUS,
	TIMES, OVER, LPAREN, RPAREN, DOT,
	COLON, SEMI, COMMA, LMIDPAREN, RMIDPAREN,
	UNDERANGE,

	/*δ��ʼ��*/
	lex_uninit
}LexType;

void LL1_init(int t[67][42]);

#endif

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

/********************** 单词的词法类型 ********************/
typedef enum
{
	/* 簿记单词符号 */
	ENDFILE, ERRORR,
	/* 保留字 */
	PROGRAM, PROCEDURE, TYPE, VAR, IF,
	THEN, ELSE, FI, WHILE, DO,
	ENDWH, BEGIN, END, READ, WRITE,
	ARRAY, OF, RECORD, RETURN,

	INTEGER, CHARR,
	/* 多字符单词符号 */
	ID, INTC, CHARC,
	/*特殊符号 */
	ASSIGN, EQ, LT, PLUS, MINUS,
	TIMES, OVER, LPAREN, RPAREN, DOT,
	COLON, SEMI, COMMA, LMIDPAREN, RMIDPAREN,
	UNDERANGE,

	/*未初始化*/
	lex_uninit
}LexType;

void LL1_init(int t[67][42]);

#endif

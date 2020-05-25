#include "stdafx.h"
#include"LL1_table.h"
#include<iostream>
#include<stack>


//LL1分析表的初始化
void LL1_init(int t[67][42]) {
	memset(t, -1, sizeof(int) * 2814);

	t[Program][PROGRAM] = 1;

	t[ProgramHead][PROGRAM] = 2;

	t[ProgramName][ID] = 3;

	t[DeclarePart][TYPE] = 4;
	t[DeclarePart][VAR] = 4;
	t[DeclarePart][PROCEDURE] = 4;
	t[DeclarePart][BEGIN] = 4;

	t[TypeDec][VAR] = 5;
	t[TypeDec][PROCEDURE] = 5;
	t[TypeDec][BEGIN] = 5;

	t[TypeDec][TYPE] = 6;

	t[TypeDeclaration][TYPE] = 7;

	t[TypeDecList][ID] = 8;

	t[TypeDecMore][VAR] = 9;
	t[TypeDecMore][PROCEDURE] = 9;
	t[TypeDecMore][BEGIN] = 9;

	t[TypeDecMore][ID] = 10;

	t[TypeId][ID] = 11;

	t[TypeName][INTEGER] = 12;
	t[TypeName][CHARR] = 12;

	t[TypeName][ARRAY] = 13;
	t[TypeName][RECORD] = 13;

	t[TypeName][ID] = 14;

	t[BaseType][INTEGER] = 15;

	t[BaseType][CHARR] = 16;

	t[StructureType][ARRAY] = 17;

	t[StructureType][RECORD] = 18;

	t[ArrayType][ARRAY] = 19;

	t[Low][INTC] = 20;

	t[Top][INTC] = 21;

	t[RecType][RECORD] = 22;

	t[FieldDecList][INTEGER] = 23;
	t[FieldDecList][CHARR] = 23;

	t[FieldDecList][ARRAY] = 24;

	t[FieldDecMore][END] = 25;

	t[FieldDecMore][INTEGER] = 26;
	t[FieldDecMore][CHARR] = 26;
	t[FieldDecMore][ARRAY] = 26;

	t[IdList][ID] = 27;

	t[IdMore][SEMI] = 28;

	t[IdMore][COMMA] = 29;

	t[VarDec][PROCEDURE] = 30;
	t[VarDec][BEGIN] = 30;

	t[VarDec][VAR] = 31;

	t[VarDeclaration][VAR] = 32;

	t[VarDecList][INTEGER] = 33;
	t[VarDecList][CHARR] = 33;
	t[VarDecList][ARRAY] = 33;
	t[VarDecList][RECORD] = 33;
	t[VarDecList][ID] = 33;

	t[VarDecMore][PROCEDURE] = 34;
	t[VarDecMore][BEGIN] = 34;

	t[VarDecMore][INTEGER] = 35;
	t[VarDecMore][CHARR] = 35;
	t[VarDecMore][ARRAY] = 35;
	t[VarDecMore][RECORD] = 35;
	t[VarDecMore][ID] = 35;

	t[VarIdList][ID] = 36;

	t[VarIdMore][SEMI] = 37;

	t[VarIdMore][COMMA] = 38;

	t[ProcDec][BEGIN] = 39;

	t[ProcDec][PROCEDURE] = 40;

	t[ProcDeclaration][PROCEDURE] = 41;

	t[ProcDecMore][BEGIN] = 42;

	t[ProcDecMore][PROCEDURE] = 43;

	t[ProcName][ID] = 44;

	t[ParamList][RPAREN] = 45;

	t[ParamList][INTEGER] = 46;
	t[ParamList][CHARR] = 46;
	t[ParamList][ARRAY] = 46;
	t[ParamList][RECORD] = 46;
	t[ParamList][ID] = 46;
	t[ParamList][VAR] = 46;

	t[ParamDecList][INTEGER] = 47;
	t[ParamDecList][CHARR] = 47;
	t[ParamDecList][ARRAY] = 47;
	t[ParamDecList][RECORD] = 47;
	t[ParamDecList][ID] = 47;
	t[ParamDecList][VAR] = 47;

	t[ParamMore][RPAREN] = 48;//原文为左括号

	t[ParamMore][SEMI] = 49;

	t[Param][INTEGER] = 50;
	t[Param][CHARR] = 50;
	t[Param][ARRAY] = 50;
	t[Param][RECORD] = 50;
	t[Param][ID] = 50;

	t[Param][VAR] = 51;

	t[FormList][ID] = 52;

	t[FidMore][SEMI] = 53;
	t[FidMore][RPAREN] = 53;

	t[FidMore][COMMA] = 54;

	t[ProcDecPart][TYPE] = 55;
	t[ProcDecPart][VAR] = 55;
	t[ProcDecPart][PROCEDURE] = 55;
	t[ProcDecPart][BEGIN] = 55;

	t[ProcBody][BEGIN] = 56;

	t[ProgramBody][BEGIN] = 57;

	t[StmList][ID] = 58;
	t[StmList][IF] = 58;
	t[StmList][WHILE] = 58;
	t[StmList][RETURN] = 58;
	t[StmList][READ] = 58;
	t[StmList][WRITE] = 58;

	t[StmMore][ELSE] = 59;
	t[StmMore][FI] = 59;
	t[StmMore][END] = 59;
	t[StmMore][ENDWH] = 59;

	t[StmMore][SEMI] = 60;

	t[Stm][IF] = 61;

	t[Stm][WHILE] = 62;

	t[Stm][READ] = 63;

	t[Stm][WRITE] = 64;

	t[Stm][RETURN] = 65;

	t[Stm][ID] = 66;

	t[AssCall][ASSIGN] = 67;//原文只有assign
	t[AssCall][LMIDPAREN] = 67;
	t[AssCall][DOT] = 67;

	t[AssCall][LPAREN] = 68;

	t[AssignmentRest][ASSIGN] = 69;
	t[AssignmentRest][LMIDPAREN] = 69;
	t[AssignmentRest][DOT] = 69;

	t[ConditionalStm][IF] = 70;

	t[LoopStm][WHILE] = 71;

	t[InputStm][READ] = 72;

	t[Invar][ID] = 73;

	t[OutputStm][WRITE] = 74;

	t[ReturnStm][RETURN] = 75;

	t[CallStmRest][LPAREN] = 76;

	t[ActParamList][RPAREN] = 77;

	t[ActParamList][LPAREN] = 78;
	t[ActParamList][INTC] = 78;
	t[ActParamList][ID] = 78;

	t[ActParamMore][RPAREN] = 79;

	t[ActParamMore][COMMA] = 80;

	t[RelExp][LPAREN] = 81;
	t[RelExp][INTC] = 81;
	t[RelExp][ID] = 81;

	t[OtherRelE][LT] = 82;
	t[OtherRelE][EQ] = 82;

	t[Exp][LPAREN] = 83;
	t[Exp][INTC] = 83;
	t[Exp][ID] = 83;

	t[OtherTerm][LT] = 84;
	t[OtherTerm][EQ] = 84;
	t[OtherTerm][RMIDPAREN] = 84;
	t[OtherTerm][THEN] = 84;
	t[OtherTerm][ELSE] = 84;
	t[OtherTerm][FI] = 84;
	t[OtherTerm][DO] = 84;
	t[OtherTerm][ENDWH] = 84;
	t[OtherTerm][RPAREN] = 84;
	t[OtherTerm][END] = 84;
	t[OtherTerm][SEMI] = 84;
	t[OtherTerm][COMMA] = 84;

	t[OtherTerm][PLUS] = 85;
	t[OtherTerm][MINUS] = 85;

	t[Term][LPAREN] = 86;
	t[Term][INTC] = 86;
	t[Term][ID] = 86;

	t[OtherFactor][PLUS] = 87;
	t[OtherFactor][MINUS] = 87;
	t[OtherFactor][LT] = 87;
	t[OtherFactor][EQ] = 87;
	t[OtherFactor][RMIDPAREN] = 87;
	t[OtherFactor][THEN] = 87;
	t[OtherFactor][ELSE] = 87;
	t[OtherFactor][FI] = 87;
	t[OtherFactor][DO] = 87;
	t[OtherFactor][ENDWH] = 87;
	t[OtherFactor][RPAREN] = 87;
	t[OtherFactor][END] = 87;
	t[OtherFactor][SEMI] = 87;
	t[OtherFactor][COMMA] = 87;

	t[OtherFactor][TIMES] = 88;
	t[OtherFactor][OVER] = 88;

	t[Factor][LPAREN] = 89;

	t[Factor][INTC] = 90;

	t[Factor][ID] = 91;

	t[Variable][ID] = 92;

	t[VariMore][ASSIGN] = 93;
	t[VariMore][PLUS] = 93;
	t[VariMore][OVER] = 93;
	t[VariMore][PLUS] = 93;
	t[VariMore][MINUS] = 93;
	t[VariMore][LT] = 93;
	t[VariMore][EQ] = 93;
	t[VariMore][THEN] = 93;
	t[VariMore][ELSE] = 93;
	t[VariMore][FI] = 93;
	t[VariMore][DO] = 93;
	t[VariMore][ENDWH] = 93;
	t[VariMore][RPAREN] = 93;
	t[VariMore][END] = 93;
	t[VariMore][SEMI] = 93;
	t[VariMore][COMMA] = 93;
	t[VariMore][RMIDPAREN] = 93;

	t[VariMore][LMIDPAREN] = 94;

	t[VariMore][DOT] = 95;

	t[FieldVar][ID] = 96;

	t[FieldVarMore][ASSIGN] = 97;
	t[FieldVarMore][PLUS] = 97;
	t[FieldVarMore][OVER] = 97;
	t[FieldVarMore][PLUS] = 97;
	t[FieldVarMore][MINUS] = 97;
	t[FieldVarMore][LT] = 97;
	t[FieldVarMore][EQ] = 97;
	t[FieldVarMore][THEN] = 97;
	t[FieldVarMore][ELSE] = 97;
	t[FieldVarMore][FI] = 97;
	t[FieldVarMore][DO] = 97;
	t[FieldVarMore][ENDWH] = 97;
	t[FieldVarMore][RPAREN] = 97;
	t[FieldVarMore][END] = 97;
	t[FieldVarMore][SEMI] = 97;
	t[FieldVarMore][COMMA] = 97;

	t[FieldVarMore][LMIDPAREN] = 98;

	t[CmpOp][LT] = 99;

	t[CmpOp][EQ] = 100;

	t[AddOp][PLUS] = 101;

	t[AddOp][MINUS] = 102;

	t[MultOp][TIMES] = 103;

	t[MultOp][OVER] = 104;
}

#pragma once
#ifndef _TOKENSCANNER_H
#define _TOKENSCANNER_H
#include "Token.h"

static struct
{
	string str;
	LexType tok;
} reservedWords[21]
= { { "program",PROGRAM },{ "type",TYPE },{ "var",VAR },{ "procedure",PROCEDURE }
,{ "begin",BEGIN },{ "end",END },{ "array",ARRAY },{ "of",OF },{ "record",RECORD }
,{ "if",IF },{ "then",THEN },{ "else",ELSE },{ "fi",FI },{ "while",WHILE }
,{ "do",DO },{ "endwh",ENDWH },{ "read",READ },{ "write",WRITE },{ "return",RETURN }
,{ "integer",INTEGER },{ "char",CHARR } };


typedef enum
{
	START, INASSIGN, INRANGE, INCOMMENT, INNUM, INID, INCHAR, DONE
}
StateType;


class TokenScanner
{
public:
	Token* Scan(FILE* f);
	LexType ReservedLookup(string str);			//判断是是否为保留字

	int Line = 1;
	//标识符表和常量表，用于保存一个程序的所有标识符和常量
	vector<string> identifier;
	vector<string> constant;
	bool Error = false;
};

#endif

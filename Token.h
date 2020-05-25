#pragma once
#ifndef _TOKEN_H
#define _TOKEN_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include "LL1_table.h"
using namespace std;

class Token
{
public:
	~Token() {};
	int line;
	LexType type;
	string content;
};
#endif

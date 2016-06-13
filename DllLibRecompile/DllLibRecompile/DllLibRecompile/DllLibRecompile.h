#include "stdafx.h"
#include<iostream>
using namespace std;
class CMYClass
{
	long m_cRef;
	int m_i;
public:
	__declspec(dllexport) void Print(const char* msg);
};


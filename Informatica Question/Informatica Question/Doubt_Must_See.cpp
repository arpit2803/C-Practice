// Informatica Question.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;
void CheckForDataSize();
void CheckForDataSize1();
void try_things();
void CheckForPointerAsParameter(int*);
int Informatica_CheckDataType_PointerPassing()
{
	cout << "check for knowing the size of datatype"<<'\n';
	CheckForDataSize();
	CheckForDataSize1();
	try_things();
	cout <<'\n'<< "check for pointer passed to different function"<<'\n';
	int a = 10;
	int* p = &a;	
	cout << "value of p before :" << *p<<'\n';
	CheckForPointerAsParameter(p);
	cout << "value of p after :" << *p<<'\n';	

	system("pause");
	exit(0);
	return 0;
}

void CheckForDataSize()
{
	int nm;
	char* c = (char *)0;//this is possible since pointer can point at any location, reading it might cause problem
						//*c = 50;					//or dereferencing will result in crash
	int* i = (int *)0;
	//nm = *i; //Even this will casue crash

	c = (char *)0;

	int fgh = 0x3453;
	cout << "Decimal Equivalent of '0x3453' is " << fgh << '\n';//this will print decimal quivalent of 0x3453
	//cout << c; //Even this will result in crash, this basically means you are dereferencing c to print in value.
	//for refreshment : https://www.quora.com/How-assignment-work-in-C-language
	//cout << nm;
	double* d = (double *)0;

	int f, g, h;

	f = (int)(c + 1);
	g = (int)(i + 1);
	h = (int)(d + 1);	

	std::cout << f << " " << g << " " << h <<'\n';

	std::cout << &f << " " << &g << " " << &h;//this will print size of datatypes

	
	int y, t, lk;
	cout <<'\n'<< "-------";
	//not sure why this gives ouput as 6
	cout << (&lk - &y)<<'\n'<<'\n';
}

void CheckForDataSize1()
{
	cout << "Another method for knowing size of data type" << '\n';
	double* ptr = new double[3];
	double* v = ptr + 1;
	cout << v;
	cout << '\n' << ptr;
	int sdf = ((char*)v - (char*)ptr); //(char*) is done because we need to convert pointer to char* then calculate the difference
									   //char occupies one bit so difference gives number of bit.
	int hgf = ((int)v - (int)ptr);

	int gfd = ((size_t)v - (size_t)ptr); //size_t is an unsigned type. So, it cannot represent any negative values(<0). 
										//You use it when you are counting something, and are sure that it cannot be negative
										//strlen() returns a size_t because the length of a string has to be at least 0
										//void *memcpy(void *s1, void const *s2, unsigned int n); --- so that more number of object can be copied
										//It make sense to use size_t whenver you know that output can never be negative
										//you also get to send twice the size as of int.

	cout << "size of 'double' " << hgf << '\n';
	cout << "size of 'double'" << gfd<<'\n';
	cout << "size of 'double'" << sdf;

	//Not sure why this is returning -12
	//int c, j;
	//cout /*<< &c << '\n' << &j*/ << ((int)&j - (int)&c);

}

void CheckForPointerAsParameter(int* h)
{
	*h = 345;
}


void try_things()
{
	int n;
	int x[2] = { 45, 65 };
	int m = 34;
	cout <<"jdlijdlisajdlisa"<< x[2];
}

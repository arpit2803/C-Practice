// C++ Practice.cpp : Defines the entry point for the console application.
//

#include"stdafx.h"
#include<iostream>
#include<stdio.h>
#include<list>
char* Reverse(char* sent);
void swapLH(char* sent, int lo, int hi);
using namespace std;
//this is program to reverse word in a sentence input "I am great" to "great am I"
int main1()
{
	char sentence[] = "I am arpit jain";

	char* p = Reverse(sentence);

    return 0;
}

char* Reverse(char* sent)
{
	int len = 0;
	char* bn = sent;
	while (*bn != '\0')
	{
		len++;
		bn++;
	}

	for (int k = 0, l = len-1; k < (len/2) + 1; k++, l--)
	{
		char h = *(sent + k);
		*(sent + k) = *(sent + l);
		*(sent + l) = h;
	}
	sent[len] = '\0';
	std::cout << sent;

	int lower = 0;
	int high = 0;
	for (int h = 0; h < len; h++)
	{		
		char c = *(sent + h);
		high++;
		if (isspace(c))
		{
			swapLH(sent, lower, high-1);
			lower = high;

		}
	}
	return sent;
}

void swapLH(char* sent, int lo, int hi)
{
	for (int k = lo, p = hi - 1; k < ((hi + lo) / 2); k++, p--)
	{
		char h = *(sent + k);
		*(sent + k) = *(sent + p);
		*(sent + p) = h;
	}
}
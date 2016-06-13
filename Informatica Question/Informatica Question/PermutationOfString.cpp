// C program to print all permutations with duplicates allowed
#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;
/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
static int u = 0;
/* Function to print permutations of string
This function takes three parameters:
1. String
2. Starting index of the string
3. Ending index of the string. */
void permute(char *a, int l, int r)
{
	int i;
	if (l == r)
	{
		printf("%s\n", a);
		u++;
	}
	else
	{
		for (i = l; i <= r; i++)
		{
			swap((a + l), (a + i));
			permute(a, l + 1, r);
			swap((a + l), (a + i)); //backtrack, means if above swap has made string as "ARPTI" this will make again "ARPIT"
		}
	}
}

/* Driver program to test above functions */
int PermutationOfString()
{
	char str[] = "ARPIT";
	int n = strlen(str);
	permute(str, 0, n - 1);
	std::cout << u;
	system("pause");
	return 0;
}
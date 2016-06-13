#include"stdafx.h"
#include<iostream>
#include<stdio.h>
#include<list>

class ABC
{
public:
	int a, b, c, d;
	ABC(int a, int b, int c, int d)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}
};
void functiontomodify(ABC& abc);

int main()
{
	ABC* abc = new ABC(5, 8, 9, 14);

	functiontomodify(*abc);

	system("pause");
}

void functiontomodify(ABC& abc)
{
	abc.a = 30;
	abc.b = 50;
	abc.c = 70;
	abc.d = 100;

}
#include"stdafx.h"
#include<iostream>
#include<conio.h>
#include<list>
class TB
{
public:
	int number;
	TB* lnode;
	TB* rnode;
	TB(int number)
	{
		this->number = number;
		lnode = NULL;
		rnode = NULL;
	}

};

void PerformBFS(TB* hN)
{
	std::list<TB*> lPointerAdd;
	if (hN != NULL)
	{
		lPointerAdd.push_front(hN);
	}

	while (!lPointerAdd.empty())
	{
		TB* p = lPointerAdd.back();
		std::cout << p->number;
		if (p->lnode != NULL)
		{			
			lPointerAdd.push_front(p->lnode);			
		}
		if (p->rnode != NULL)
		{
			lPointerAdd.push_front(p->rnode);
		}
		lPointerAdd.pop_back();
	}
}
int BreadthFirstSearch_Trees()
{
	TB* root = new TB(1);

	root->lnode = new TB(2);
	root->rnode = new TB(3);
	root->lnode->lnode = new TB(4);
	root->lnode->rnode = new TB(5);
	root->rnode->lnode = new TB(6);
	root->rnode->rnode = new TB(7);
	root->lnode->lnode->lnode = new TB(8);
	root->lnode->lnode->rnode = new TB(9);
	root->lnode->rnode->lnode = new TB(10);
	root->lnode->rnode->rnode = new TB(11);
	root->rnode->lnode->lnode = new TB(12);
	root->rnode->lnode->rnode = new TB(13);
	root->rnode->rnode->lnode = new TB(14);
	root->rnode->rnode->rnode = new TB(15);
	PerformBFS(root);
	return 0;
}
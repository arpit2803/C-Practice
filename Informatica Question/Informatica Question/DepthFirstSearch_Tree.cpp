#include"stdafx.h"
#include<iostream>
#include<conio.h>
#include<list>
class TD
{
public:
	int number;
	TD* lnode;
	TD* rnode;
	TD(int number)
	{
		this->number = number;
		lnode = NULL;
		rnode = NULL;
	}

};
//Pre-Order, In-Order, Post-Order all are Depth First Search
void PerformDFS(TD* hN)
{
	std::list<TD*> lPointerAdd;
	if (hN != NULL)
	{
		lPointerAdd.push_front(hN);
	}

	while (!lPointerAdd.empty())
	{
		TD* p = lPointerAdd.front();
		lPointerAdd.pop_front();
		std::cout << p->number;
		if (p->lnode != NULL)
		{
			lPointerAdd.push_front(p->lnode);
		}
		if (p->rnode != NULL)
		{
			lPointerAdd.push_front(p->rnode);
		}
	}
}
int DepthFirstSearch_Trees()
{
	TD* root = new TD(1);

	root->lnode = new TD(2);
	root->rnode = new TD(3);
	root->lnode->lnode = new TD(4);
	root->lnode->rnode = new TD(5);
	root->rnode->lnode = new TD(6);
	root->rnode->rnode = new TD(7);
	root->lnode->lnode->lnode = new TD(8);
	root->lnode->lnode->rnode = new TD(9);
	root->lnode->rnode->lnode = new TD(10);
	root->lnode->rnode->rnode = new TD(11);
	root->rnode->lnode->lnode = new TD(12);
	root->rnode->lnode->rnode = new TD(13);
	root->rnode->rnode->lnode = new TD(14);
	root->rnode->rnode->rnode = new TD(15);
	PerformDFS(root);
	return 0;
}
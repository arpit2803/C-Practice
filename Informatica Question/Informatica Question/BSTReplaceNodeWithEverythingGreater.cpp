#include"stdafx.h"
#include<iostream>
#include<conio.h>

class BST
{
public:
	int value;
	BST* lNode;
	BST* rNode;
    BST(int value)
	{
		this->value = value;
		lNode = NULL;
		rNode = NULL;
	}
};

void printInOrderTraversal(BST* root)
{
	if (root == NULL)
	{
		return;
	}
	printInOrderTraversal(root->lNode);
	std::cout << root->value <<"\n";
	printInOrderTraversal(root->rNode);
}

void ChangeValueToSum(BST* root)
{
	static int sum = 0;
	if (root == NULL)
	{
		return;
	}
	ChangeValueToSum(root->rNode);
	sum += root->value;
	root->value = sum;
	ChangeValueToSum(root->lNode);
}

void ReplaceNodeValueWithAllTheGreaterNode(BST* root)
{
	printInOrderTraversal(root);
	std::cout << "\n"<<"-------";
	ChangeValueToSum(root);

	printInOrderTraversal(root);
	system("pause");
}

int BSTReplaceNodeWithEverythingGreater()
{
	BST* root = new BST(27);
	root->lNode = new BST(14);
	root->rNode = new BST(35);
	root->lNode->lNode = new BST(10);
	root->lNode->lNode->rNode = new BST(12);
	root->lNode->rNode = new BST(19);
	root->rNode->lNode = new BST(31);
	root->rNode->rNode = new BST(42);
	ReplaceNodeValueWithAllTheGreaterNode(root);
	return 0;
}
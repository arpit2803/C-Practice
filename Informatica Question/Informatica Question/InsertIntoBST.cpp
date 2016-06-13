#include"stdafx.h"
#include<iostream>
#include<conio.h>



class Node
{
public :
	int key;
	Node* lLink;
	Node* rLink;
};
Node* FindSmalledNode(Node* node);
Node* GetNewNode(int key)
{
	Node* newNode = new Node();
	newNode->key = key;
	newNode->lLink = newNode->rLink = NULL;
	return newNode;
}

Node* insertNode(Node* root, int key)
{
	if (root == NULL)
		return GetNewNode(key);

	if (root->key > key)
		root->lLink = insertNode(root->lLink, key);
	if (root->key < key)
		root->rLink = insertNode(root->rLink, key);

	return root;

}

void inOrder(Node* root)
{
	if (root == NULL)
		return;

	inOrder(root->lLink);
	std::cout << root->key;
	inOrder(root->rLink);
}

Node* deleteBSTNode(Node* root, int key)
{
	if (root == NULL)
		return NULL;

	if (root->key > key)
		root->lLink = deleteBSTNode(root->lLink, key);
	else if (root->key < key)
		root->rLink = deleteBSTNode(root->rLink, key);
	else
	{
		if (root->lLink == NULL && root->rLink == NULL)
		{
			return NULL;
			delete root;
		}
		else if (root->lLink == NULL)
		{
			Node* ptr = root->rLink;
			delete root;
			return ptr;
		}
		else if (root->rLink == NULL)
		{
			Node* ptr = root->lLink;
			delete root;
			return ptr;
		}
		else
		{
			Node* node = FindSmalledNode(root->rLink);
			root->key = node->key;
			root->rLink = deleteBSTNode(root->rLink, node->key);
			delete node;
		}
	}
	return root;
}

Node* FindSmalledNode(Node* node)
{
	if (node->lLink == NULL)
		return node;
	
	return FindSmalledNode(node->lLink);
}

int InsertIntoBST()
{
	Node *root = GetNewNode(50);
	root->lLink = GetNewNode(30);
	root->rLink = GetNewNode(70);
	root->lLink->lLink = GetNewNode(20);
	root->lLink->rLink = GetNewNode(40);
	root->rLink->lLink = GetNewNode(60);
	root->rLink->rLink = GetNewNode(80);
	insertNode(root, 35);

	inOrder(root);

	Node* ptr = deleteBSTNode(root, 30);
	std::cout << "After Deleting:" << '\n';
	inOrder(ptr);

	return 0;
}
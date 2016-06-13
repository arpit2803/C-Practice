#include"stdafx.h"
#include<iostream>
#include<stdio.h>
#include<list>


using namespace std;

class Graph
{
	int V;
	list<int>* ptr;
public:
	Graph(int V);
	void AddEdge(int v, int w);
	void DFS(int v);
	void DFSTraversal(int v, bool* pVisited_node);
};

Graph::Graph(int V)
{
	this->V = V;
	ptr = new list<int>[V];
}

void Graph::AddEdge(int v, int w)
{
	ptr[v].push_back(w);
}

void Graph::DFSTraversal(int starting_node, bool* pVisited_node)
{
	pVisited_node[starting_node] = true;
	cout << starting_node << " ";
	list<int>::iterator i;
	for (i = ptr[starting_node].begin(); i != ptr[starting_node].end(); ++i)
	{
		if (!pVisited_node[*i])
		{
			DFSTraversal(*i, pVisited_node);
		}
	}
}

void Graph::DFS(int starting_node)
{
	bool* pVisited_node = new bool[V];
	for (int i = 0; i < V; i++)
	{
		pVisited_node[i] = false;
	}

	DFSTraversal(starting_node, pVisited_node);
}

int DFS_Traversal()
{
	Graph g(4);
	g.AddEdge(0, 1);
	g.AddEdge(0, 2);
	g.AddEdge(1, 2);
	g.AddEdge(2, 0);
	g.AddEdge(2, 3);
	g.AddEdge(3, 3);

	cout << "DFS starting from node 2"<<'\n';
	g.DFS(2);

	return 0;
}
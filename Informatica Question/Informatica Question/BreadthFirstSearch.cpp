#include"stdafx.h"
#include<iostream>
#include<stdio.h>
#include<list>
#include<queue>

using namespace std;

class GraphBFS
{
	int V;
	list<int>* ptr;
public:
	GraphBFS(int V)
	{
		this->V = V;
		ptr = new list<int>[V];
	}

	void AddEdge(int v, int w)
	{
		ptr[v].push_back(w);
	}

	void BFS(int startingNode)
	{
		bool* visitedNodes = new bool[V];
		for (int i = 0; i < V; i++)
		{
			visitedNodes[i] = false;
		}
		list<int> queue;
		queue.push_back(startingNode);
		visitedNodes[startingNode] = true;

		while (!queue.empty())
		{
			startingNode = queue.front();
			cout << startingNode;
			queue.pop_front();

			list<int>::iterator i;
			for (i = ptr[startingNode].begin(); i != ptr[startingNode].end(); i++)
			{
				if (!visitedNodes[*i])
				{
					queue.push_back(*i);
					visitedNodes[*i] = true;
				}
			}
		}
	}
};

int BFS_Traversal()
{
	GraphBFS g(4);
	g.AddEdge(0, 1);
	g.AddEdge(0, 2);
	g.AddEdge(1, 2);
	g.AddEdge(2, 0);
	g.AddEdge(2, 3);
	g.AddEdge(3, 3);

	cout << "BFS starting from node 2:" << '\n';
	g.BFS(2);
	return 0;
}

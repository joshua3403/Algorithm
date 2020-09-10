#include "GraphTraversal.h"

void DFS(Vertex* v)
{
	Edge* E;

	printf("%d ", v->Data);

	v->Visited = Visited;

	E = v->AdjacencyList;

	while (E->Next != NULL)
	{
		if (E->Target != NULL && E->Target->Visited == NotVisited)
		{
			DFS(E->Target);
		}

		E = E->Next;
	}
}

void BFS(Vertex* v, std::queue<Vertex*> Queue)
{
	Edge* E = NULL;

	printf("%d ", v->Data);

	Queue.push(v);

	while (!Queue.empty())
	{
		Vertex* Popped = Queue.front();
		Queue.pop();
		v = Popped;
		E = v->AdjacencyList;

		while (E != NULL)
		{
			v = E->Target;
			if (v != NULL && v->Visited == NotVisited)
			{
				printf("%d ", v->Data);
				v->Visited = Visited;
				Queue.push(v);
			}

			E = E->Next;
		}
	}

}

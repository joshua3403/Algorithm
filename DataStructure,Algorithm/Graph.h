#pragma once
#include "stdafx.h"

// 1. 그래프란??
// 그래프는 '정점의 모음'과 이 정점을 잇는 '간선의 모음'과의 결합이다.
// 즉 "정점의 집합을 V, 간선의 집합을 E, 그리고 그래프를 G라고 했을 때, G = (V,E)이다.
// 정점 몇 개 자체로는 아무것도 아니지만 이들이 간선으로 인해 서로 연결될 때는 '관계'가 형성되고 이로 인해 그래프가 형성된다.
// 간선으로 연결되어 있는 두 정점을 가리켜 서로 '인접' 또는 이웃 관계에 있다고 말한다.
// 간선을 통해 서로 이웃이 된 각 정점은 그래프 안에서의 길을 형성하기도 한다.
// 길은 길이를 가지는데, 길이는 정점과 정점 사이에 있는 간선의 수로 나타낸다.
// 어느 경로가 정점 하나를 두 번 이상 거치도록 되어 있다면 그 경로를 일컬어 '사이클'이라고 한다.
// 간선이 방향을 가지면 그래프는 방향성 그래프(Directed Graph)가 되고 방향성이 없으면 무방향성 그래프(Undirected Graph)가 된다.
// 무방향성 그래프 내의 두 정점 사이에 경로가 존재하면 이 두 정점이 연결되어 있다고 한다.
// 그리고 그래프내의 각 정점들이 다른 모든 정점들과 연결되어 있으면 이 그래프는 연결되었다고 한다.

// 2. 그래프를 어떻게 표현 할 것인가?
// 그래프는 정점 집합과 간선 집합의 결합이기 때문에, 이를 표현하는 문제는 '정점의 집합'과 '간선의 집합'의 표현 문제로 생각할 수 있다.
// 정점의 집합은 어떤 자료구조를 사용하더라도 쉽게 표현이 가능하다.
// 정점 사이의 인접 관계를 나타내는 방법에는 크게 두 가지가 있다.
// 하나는 행렬을 이용하는 것이고, 또 다른 하나는 리스트를 이용하는 것이다.
// 행렬을 이용하는 방식은 인접 행렬(Adjacency Matrix)이라 하고 리스트를 이용하는 방식은 인접 리스트(Adjacency List)라고 한다.

// 인접 행렬
// 정점끼리의 인접 관계를 나타내는 행렬.
// 사용 방법은, 그래프의 정점의 수를 N이라고 한다면, NXN크기의 행렬을 만들어 행렬의 각 원소를 한 정점과 또 다른 정점이 인접해 있는 경우(즉, 정점 사이에 간선이 존재하는 경우)에는 1로 표시하고, 인접해 있지 않은 경우에는 0으로 표시하는 것
// 무방향성 그래프의 인접 행렬은 대각선으로 대칭
// 방향성 그래프의 인접 행렬은 비대칭

// 인접 리스트
// 각 정점을 자신과 인접해 있는 모든 정점의 목록을 리스트로 관리하는 것.

// 인접 행렬 VS 인접 리스트
// 인접 행렬을 이용하면 정잠 간의 인접 여부를 빠르게 알 수 있지만 인접 관계를 행렬 형태로 저장하기 위해 사용하는 메모리의 양이 '정점의 크기 X N X N'에 이른다.
// 인접 리스트는 정점 간의 인접 여부를 알아내기 위해 인접 리스트를 타고 순차 탐색을 해야 한다는 단점이 있는 반면에, 정점과 간선의 삽입이 빠르고 인접 관계를 표시하는 리스트에 사용되는 메모리의 양이 적다는 장점이 있다.

enum VisitMode{Visited, NotVisited};

typedef int ElementType;
typedef struct tagVertex
{
	ElementType Data;
	int			Visited;
	int			Index;

	struct tagVertex* Next;
	struct tagEdge* AdjacencyList;
} Vertex;

typedef struct tagEdge
{
	int Weight;
	struct tagEdge* Next;
	Vertex* From;
	Vertex* Target;
} Edge;

typedef struct tagGragh
{
	Vertex* Vertices;
	int VetexCount;
}Graph;

Graph* CreateGraph();
void DestroyGraph(Graph* G);
Vertex* CreateVertex(ElementType Data);
void DestroyVertex(Vertex* V);

Edge* CreateEdge(Vertex* From, Vertex* Target, int Weight);
void DestroyEdge(Edge* E);

void AddVertex(Graph* G, Vertex* V);
void AddEdge(Vertex* V, Edge* E);
void PrintGraph(Graph* G);
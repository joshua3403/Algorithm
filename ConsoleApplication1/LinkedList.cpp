#include "stdafx.h"
#include "LinkedList.h"
// 노드 생성
void SLL_CreateNode(int newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = newData;
	newNode->NextNode = nullptr;
}

void SLL_DestroyNode(Node* NewNode)
{
	free(NewNode);
}

void SLL_AppendNode(Node** Head, Node* NewNode)
{
	if ((*Head) == nullptr)
	{
		*Head = NewNode;
	}
	else
	{
		Node* tail = (*Head);
		while (tail->NextNode != nullptr)
		{
			tail = tail->NextNode;
		}
		tail->NextNode = NewNode;
	}
}

void SLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

void SLL_InsertHead(Node** Head, Node* NewHead)
{
	if ((*Head) == nullptr)
	{
		(*Head) = NewHead;
	}
	else
	{
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}

void SLL_InsertBefore(Node** Head, Node* Current, Node* NewNode)
{
	if ((*Head) == nullptr || Current == (*Head))
	{
		SLL_InsertHead(Head, NewNode);
	}
	else
	{
		Node* temp = (*Head);
		while (temp != nullptr && temp->NextNode == Current)
		{
			temp = temp->NextNode;
		}
		temp->NextNode = NewNode;
		NewNode->NextNode = Current;
	}
}

void SLL_RemoveNode(Node** Head, Node* Remove)
{
	if ((*Head) == Remove)
	{
		(*Head) = Remove->NextNode;
	}
	else
	{
		Node* Current = (*Head);
		while (Current != NULL && Current->NextNode != Remove)
		{
			Current = Current->NextNode;
		}

		if (Current != NULL)
			Current->NextNode = Remove->NextNode;
	}
}

Node* SLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;
	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

int SLL_GetNodeCount(Node* Head)
{
	Node* Current = Head;
	int count = 0;
	while (Current != nullptr)
	{
		count++;
		Current = Current->NextNode;
	}
	return count;
}

void SLL_DestroyAllNodes(Node** List)
{
	Node* Head = *List;
	Node* temp;
	while (Head != nullptr)
	{
		temp = Head;
		Head = Head->NextNode;
		SLL_RemoveNode(List, temp);
		SLL_DestroyNode(temp);
	}
}

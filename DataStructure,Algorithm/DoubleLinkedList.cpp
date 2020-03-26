#include "DoubleLinkedList.h"

Node* DLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = NewData;

	NewNode->NextNode = nullptr;
	NewNode->PrevNode = nullptr;
	return NewNode;
}

void DLL_AppendNode(Node** Head, Node* NewNode)
{
	if ((*Head) == nullptr)
	{
		(*Head) = NewNode;
	}
	else
	{
		// 테일을 찾아 NewNode를 연결한다.
		Node* Tail = (*Head);
		while (Tail->NextNode != nullptr)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
		// 기존의 테일을 새로운 테일의 PrevNode가 가리킨다.
		NewNode->PrevNode = Tail;
	}
}

Node* DLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;
	while (Current != nullptr && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}
	return Current;
}

void DLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;
		if ((*Head) != nullptr)
			(*Head)->PrevNode = nullptr;

		Remove->PrevNode = nullptr;
		Remove->NextNode = nullptr;
	}
	else
	{
		Node* temp = Remove;

		temp->PrevNode->NextNode = temp->NextNode;

		if (Remove->NextNode != nullptr)
			Remove->NextNode->PrevNode = temp->PrevNode;

		Remove->PrevNode = nullptr;
		Remove->NextNode = nullptr;
	}
}

void DLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != nullptr)
	{
		Current->NextNode->PrevNode = NewNode;
	}

	Current->NextNode = NewNode;
}

int DLL_GetNodeCount(Node* Head)
{
	unsigned int count = 0;
	Node* Current = Head;
	while (Current->NextNode != nullptr)
	{
		Current = Current->NextNode;
		count++;
	}
	return count;
}

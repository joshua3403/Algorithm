#include "LinkedListStack.h"

#define _CRT_SECURE_NO_WARNINGS

void LLS_CreateStack(LinkedListStack** stack)
{
	(*stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*stack)->List = nullptr;
	(*stack)->Top = nullptr;
}

void LLS_DestroyStack(LinkedListStack* stack)
{
	while (!LLS_IsEmpty(stack))
	{
		Node* Popped = LLS_Pop(stack);

		LLS_DestroyNode(Popped);
	}
	free(stack);
}

Node* LLS_CreateNode(char* newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->Data = (char*)malloc(strlen(newData) + 1);

	strcpy_s(newNode->Data, strlen(newData) + 1,newData);

	newNode->NextNode = nullptr;
	return newNode;
}

void LLS_DestroyNode(Node* _Node)
{
	free(_Node->Data);
	free(_Node);
}

void LLS_Push(LinkedListStack* stack, Node* newNode)
{
	if (stack->List == nullptr)
	{
		stack->List = newNode;
	}
	else
	{
		Node* OldTop = stack->List;
		while (OldTop->NextNode != nullptr)
		{
			OldTop = OldTop->NextNode;
		}

		OldTop->NextNode = newNode;
	}

	stack->Top = newNode;
}

Node* LLS_Pop(LinkedListStack* stack)
{
	Node* TopNode = stack->Top;

	if (stack->List == stack->Top)
	{
		stack->List = nullptr;
		stack->Top = nullptr;
	}
	else
	{
		Node* CurrentTop = stack->List;
		while (CurrentTop != nullptr && CurrentTop->NextNode != stack->Top)
		{
			CurrentTop = CurrentTop->NextNode;
		}

		stack->Top = CurrentTop;
		CurrentTop->NextNode = nullptr;
	}

	return TopNode;
}

Node* LLS_Top(LinkedListStack* stack)
{
	return stack->Top;
}

int LLS_GetSize(LinkedListStack* stack)
{
	int size = 0;
	Node* Current = stack->List;

	while (Current != nullptr)
	{
		Current = Current->NextNode;
		size++;
	}
	return size;
}

bool LLS_IsEmpty(LinkedListStack* stack)
{
	return ((stack)->List == nullptr);
}


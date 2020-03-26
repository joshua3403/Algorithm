#pragma once

#include "stdafx.h"

typedef struct tagNode
{
	char* Data;
	struct tagNode* NextNode;
} Node;

typedef struct tagLinkedListStack
{
	Node* List;
	Node* Top;
} LinkedListStack;

void LLS_CreateStack(LinkedListStack** stack);

void LLS_DestroyStack(LinkedListStack* stack);

Node* LLS_CreateNode(char* newData);

void LLS_DestroyNode(Node* _Node);

void LLS_Push(LinkedListStack* stack, Node* newNode);

Node* LLS_Pop(LinkedListStack* stack);

Node* LLS_Top(LinkedListStack* stack);

int LLS_GetSize(LinkedListStack* stack);

bool LLS_IsEmpty(LinkedListStack* stack);

#pragma once

#include "stdafx.h"

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
} Node;

typedef struct tagArrayStack
{
	// �뷮
	int Capacity;
	// �ֻ��� ����� ��ġ
	int Top;
	// ��� �迭
	Node* Nodes;
}ArrayStack;

void AS_CreateStack(ArrayStack** Stack, int Capacity);

void AS_PushStack(ArrayStack* Stack, ElementType Data);

ElementType AS_PopStack(ArrayStack* Stack);

ElementType AS_Top(ArrayStack* Stack);

bool AS_IsEmpty(ArrayStack* Stack);

int AS_GetSize(ArrayStack* Stack);

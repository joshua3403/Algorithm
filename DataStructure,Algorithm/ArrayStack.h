#pragma once

#include "stdafx.h"

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
} Node;

typedef struct tagArrayStack
{
	// 용량
	int Capacity;
	// 최상위 노드의 위치
	int Top;
	// 노드 배열
	Node* Nodes;
}ArrayStack;

void AS_CreateStack(ArrayStack** Stack, int Capacity);

void AS_PushStack(ArrayStack* Stack, ElementType Data);

ElementType AS_PopStack(ArrayStack* Stack);

ElementType AS_Top(ArrayStack* Stack);

bool AS_IsEmpty(ArrayStack* Stack);

int AS_GetSize(ArrayStack* Stack);

#pragma once

#include "stdafx.h"

typedef struct tagNode
{
	int data;
	struct tagNode* NextNode;
} Node;

// 함수 원형 선언

void SLL_CreateNode(int newData);
void SLL_DestroyNode(Node* NewNode);
void SLL_AppendNode(Node** Head, Node* NewNode);
void SLL_InsertAfter(Node* Current, Node* NewNode);
void SLL_InsertHead(Node** Head, Node* NewHead);
void SLL_InsertBefore(Node** Head, Node* Current, Node* NewNode);
void SLL_RemoveNode(Node** Head, Node* Remove);
Node* SLL_GetNodeAt(Node* Head, int Location);
int SLL_GetNodeCount(Node* Head);
void SLL_DestroyAllNodes(Node** List);
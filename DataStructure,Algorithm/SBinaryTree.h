#pragma once
#include "stdafx.h"

typedef char ElementType;

typedef struct tagSBTNode
{
	tagSBTNode* Left;
	tagSBTNode* Right;

	ElementType Data;
} SBTNode;

SBTNode* SBT_CreateNode(ElementType NewData);
void SBT_DestroyNode(SBTNode* Node);
void SBT_DestroyTree(SBTNode* Tree);

void SBT_PreorderPrintTree(SBTNode* Node);
void SBT_InorderPrintTree(SBTNode* Node);
void SBT_PostorderPrintTree(SBTNode* Node);

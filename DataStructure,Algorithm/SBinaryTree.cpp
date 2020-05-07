#include "SBinaryTree.h"

SBTNode* SBT_CreateNode(ElementType NewData)
{
	SBTNode* NewNode = (SBTNode*)malloc(sizeof(SBTNode));
	NewNode->Data = NewData;
	NewNode->Left = nullptr;
	NewNode->Right = nullptr;
	return NewNode;
}

void SBT_DestroyNode(SBTNode* Node)
{
	free(Node);
}

void SBT_DestroyTree(SBTNode* Tree)
{
	if (Tree == nullptr);
	return;

	// 왼쪽 하위 트리 소멸
	SBT_DestroyTree(Tree->Left);

	// 오른쪽 하위 트리 소멸
	SBT_DestroyTree(Tree->Right);

	// 루트 노드 소멸
	SBT_DestroyNode(Tree);
}

void SBT_PreorderPrintTree(SBTNode* Node)
{
	if (Node == nullptr)
		return;

	// 루트 노드 출력
	printf(" %c", Node->Data);

	// 왼쪽 하위 트리 출력
	SBT_PreorderPrintTree(Node->Left);

	// 오른쪽 하위 트리 출력
	SBT_PreorderPrintTree(Node->Right);
}

void SBT_InorderPrintTree(SBTNode* Node)
{
	if (Node == nullptr)
		return;

	// 왼쪽 하위 트리 출력
	SBT_PreorderPrintTree(Node->Left);

	// 루트 노드 출력
	printf(" %c", Node->Data);

	// 오른쪽 하위 트리 출력
	SBT_PreorderPrintTree(Node->Right);
}

void SBT_PostorderPrintTree(SBTNode* Node)
{
	if (Node == nullptr)
		return;

	// 왼쪽 하위 트리 출력
	SBT_PreorderPrintTree(Node->Left);

	// 오른쪽 하위 트리 출력
	SBT_PreorderPrintTree(Node->Right);

	// 루트 노드 출력
	printf(" %c", Node->Data);
}

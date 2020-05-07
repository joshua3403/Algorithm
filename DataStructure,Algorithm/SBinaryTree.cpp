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

	// ���� ���� Ʈ�� �Ҹ�
	SBT_DestroyTree(Tree->Left);

	// ������ ���� Ʈ�� �Ҹ�
	SBT_DestroyTree(Tree->Right);

	// ��Ʈ ��� �Ҹ�
	SBT_DestroyNode(Tree);
}

void SBT_PreorderPrintTree(SBTNode* Node)
{
	if (Node == nullptr)
		return;

	// ��Ʈ ��� ���
	printf(" %c", Node->Data);

	// ���� ���� Ʈ�� ���
	SBT_PreorderPrintTree(Node->Left);

	// ������ ���� Ʈ�� ���
	SBT_PreorderPrintTree(Node->Right);
}

void SBT_InorderPrintTree(SBTNode* Node)
{
	if (Node == nullptr)
		return;

	// ���� ���� Ʈ�� ���
	SBT_PreorderPrintTree(Node->Left);

	// ��Ʈ ��� ���
	printf(" %c", Node->Data);

	// ������ ���� Ʈ�� ���
	SBT_PreorderPrintTree(Node->Right);
}

void SBT_PostorderPrintTree(SBTNode* Node)
{
	if (Node == nullptr)
		return;

	// ���� ���� Ʈ�� ���
	SBT_PreorderPrintTree(Node->Left);

	// ������ ���� Ʈ�� ���
	SBT_PreorderPrintTree(Node->Right);

	// ��Ʈ ��� ���
	printf(" %c", Node->Data);
}

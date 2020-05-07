#include "LCRSTree.h"

LCRSNode* LCRS_CreateNode(ElementType NewData)
{
	LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
	NewNode->data = NewData;
	NewNode->LeftChild = nullptr;
	NewNode->RightSibling = nullptr;
	return nullptr;
}

void LCRS_DestroyNode(LCRSNode* Node)
{
	free(Node);
}

void LCRS_DestroyTree(LCRSNode* Root)
{
	if (Root->RightSibling != nullptr)
		LCRS_DestroyTree(Root->RightSibling);

	if (Root->LeftChild != nullptr)
		LCRS_DestroyTree(Root->LeftChild);

	Root->LeftChild = nullptr;
	Root->RightSibling = nullptr;

	LCRS_DestroyNode(Root);
}

void LCRS_AddChildNode(LCRSNode* ParentNode, LCRSNode* ChildNode)
{
	if (ParentNode->LeftChild == nullptr)
		ParentNode->LeftChild = ChildNode;
	else
	{
		LCRSNode* TempNode = ParentNode->LeftChild;
		while (TempNode->RightSibling != nullptr)
			TempNode = TempNode->RightSibling;

		TempNode->RightSibling = ChildNode;
	}
}

void LCRS_PrintTree(LCRSNode* Node, int Depth)
{
	int i = 0;
	for (i = 0; i < Depth; i++)
		printf(" ");

	printf("%c\n", Node->data);

	if (Node->LeftChild != nullptr)
		LCRS_PrintTree(Node->LeftChild, Depth + 1);

	if (Node->RightSibling != nullptr)
		LCRS_PrintTree(Node->RightSibling, Depth);
}

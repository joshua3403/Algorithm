#include "ArrayStack.h"

void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	// 스택을 생성
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = 0;
}

void AS_PushStack(ArrayStack* Stack, ElementType Data)
{
	int Position = Stack->Top;

	Stack->Nodes[Position].Data = Data;
	Stack->Top++;
}

ElementType AS_PopStack(ArrayStack* Stack)
{
	int Position = --(Stack->Top);

	return Stack->Nodes[Position].Data;
}

ElementType AS_Top(ArrayStack* Stack)
{
	return Stack->Nodes[Stack->Top - 1].Data;
}

bool AS_IsEmpty(ArrayStack* Stack)
{
	if (Stack->Top == 0)
		return true;
	else
		return false;
}

int AS_GetSize(ArrayStack* Stack)
{
	return Stack->Top;
}

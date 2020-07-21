#include "Chaining.h"

HashTable* CHT_CreateHashTable(int TableSize)
{
	HashTable* HT = (HashTable*)malloc(sizeof(HashTable));
	HT->Table = (List*)malloc(sizeof(List) * TableSize);
	HT->TableSize = TableSize;	return nullptr;

	memset(HT->Table, 0, sizeof(List) * TableSize);

	HT->TableSize = TableSize;
	
	return HT;
}

void CHT_DestroyHashTable(HashTable* HT)
{
	// 1. �� ��ũ�� ����Ʈ�� ���� ����ҿ��� �����ϱ�
	int i = 0;
	for (i = 0; i < HT->TableSize; i++)
	{
		List L = HT->Table[i];
		CHT_DestroyNode(L);
	}

	// 2. �ؽ� ���̺��� ���� ����ҿ��� �����ϱ�
	free(HT->Table);
	free(HT);
}

Node* CHT_CreateNode(KeyType Key, ValueType Value)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Key = (char*)malloc(sizeof(char) * (strlen(Key) + 1));
	strcpy(NewNode->Key, Key);

	NewNode->Value = (char*)malloc(sizeof(char) * (strlen(Value) + 1));
	strcpy(NewNode->Value, Value);
	NewNode->Next = nullptr;
	return NewNode;
}

void CHT_DestroyNode(Node* TheNode)
{
	free(TheNode->Key);
	free(TheNode->Value);
	free(TheNode);
}

void CHT_Set(HashTable* HT, KeyType Key, ValueType Value)
{
	int Address = CHT_Hash(Key, strlen(Key), HT->TableSize);
	Node* newNode = CHT_CreateNode(Key, Value);

	// �ش� �ּҰ� ����ִ� ���
	if (HT->Table[Address] == NULL)
	{
		HT->Table[Address] = newNode;
	}
	else
	{
		List L = HT->Table[Address];
		newNode->Next = L;
		HT->Table[Address] = newNode;
	}

	printf("Collision occured : Key(%s), Address(%d)\n", Key, Address);
}

ValueType CHT_Get(HashTable* HT, KeyType Key)
{
	// �ּҸ� �ؽ��Ѵ�
	int Address = CHT_Hash(Key, strlen(Key), HT->TableSize);

	// �ؽ��� �ּҿ� �ִ� ��ũ�� ����Ʈ�� �����´�
	List TheList = HT->Table[Address];

	List Target = NULL;
	if (TheList == NULL)
		return NULL;

	// ���ϴ� ���� ã�� �� ���� ���� Ž��
	while (true)
	{
		if (strcmp(TheList->Key, Key) == 0)
		{
			Target = TheList;
			break;
		}

		if (TheList->Next == NULL)
			return NULL;
		else
			TheList = TheList->Next;
	}


	return Target->Value;
}

int CHT_Hash(KeyType Key, int KeyLength, int TableSize)
{
	int i = 0;
	int HashValue = 0;
	for (i = 0; i < KeyLength; i++)
	{
		HashValue = (HashValue << 3) + Key[i];
	}

	HashValue = HashValue % TableSize;
	return HashValue;
}

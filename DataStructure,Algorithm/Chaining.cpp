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
	// 1. 각 링크드 리스트를 자유 저장소에서 제거하기
	int i = 0;
	for (i = 0; i < HT->TableSize; i++)
	{
		List L = HT->Table[i];
		CHT_DestroyNode(L);
	}

	// 2. 해시 테이블을 자유 저장소에서 제거하기
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

	// 해당 주소가 비어있는 경우
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
	// 주소를 해싱한다
	int Address = CHT_Hash(Key, strlen(Key), HT->TableSize);

	// 해싱한 주소에 있는 링크드 리스트를 가져온다
	List TheList = HT->Table[Address];

	List Target = NULL;
	if (TheList == NULL)
		return NULL;

	// 원하는 값을 찾을 때 까지 순차 탐색
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

#pragma once
#include "stdafx.h"

typedef char* KeyType;
typedef char* ValueType;

enum ElementStatus
{
	EMPTY = 0,
	OCCUPIED = 1
};

typedef struct tagElementType
{
	KeyType Key;
	ValueType Value;

	enum ElementStatus Status;
} ElementType;

typedef struct tagHashTable
{
	int OccupiedCount;
	int TableSize;

	ElementType* Table;
}HashTable;

HashTable*	OAHT_CreateHashTable(int TableSize);
void		OAHT_DestroyHashTable(HashTable* HT);
void		OAHT_ClearElement(ElementType* Element);
void		OAHT_Set(HashTable* HT, KeyType Key, ValueType Value);
ValueType	OAHT_Get(HashTable* HT, KeyType Key);
int			OAHT_Hash(KeyType Key, int KeyLength, int TableSize);
int			OAHT_Hash2(KeyType Key, int KeyLength, int TableSize);

void		OAHT_ReHash(HashTable** HT);

// 개방 주소법(Open Addressing)
// 충돌이 일어날 때 해시 함수에 의해 얻어진 주소가 아니더라도 얼마든지 다른 주소를 사용할 수 있다록 허용하는 충돌 해결 알고리즘
// 충돌이 일어나면 해시 테이블 내의 새로운 주소를 탐사하여 충돌된 데이터를 입력하는 방식으로 작동
// 선형 탐사
// 해시 함수로부터 얻어낸 주소에 이미 다른 데이터가 입력되어 있음을 발견하면, 현재 주소에서 고정 폭으로 다음 주소로 이동한다.
// 그 주소에서도 다른 데이터가 있어 충돌이 발생하면 또 그 다음 주소로 이동한다. 이렇게 해서 비어 있는 주소를 발견하면 그곳에 데이터를 입력한다.
// 제곱 탐사
// 선형탐사와 비슷하지만 고정된 폭만큼 이동 할 때 이동폭이 제곱수로 늘어날 뿐이다.
// 이중 해싱
// 해시 함수에 키를 입력하여 얻어낸 주소에서 충돌이 일어나면 새로운 주소를 향해 이동한다. 이때 이동폭을 제 2의 해시 함수로 계산하자.
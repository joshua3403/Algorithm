#pragma once
#include "stdafx.h"

typedef char* KeyType;
typedef char* ValueType;


typedef struct tagNode
{
	KeyType Key;
	ValueType Value;

	struct tagNode* Next;
}Node;

typedef Node* List;

typedef struct tagHashTable
{
	int TableSize;
	List* Table;
}HashTable;

HashTable* CHT_CreateHashTable(int TableSize);
void CHT_DestroyHashTable(HashTable* HT);
Node* CHT_CreateNode(KeyType Key, ValueType Value);
void CHT_DestroyNode(Node* TheNode);
void CHT_Set(HashTable* HT, KeyType Key, ValueType Value);
ValueType CHT_Get(HashTable* HT, KeyType Key);
int CHT_Hash(KeyType Key, int KeyLength, int TableSize);

// 충돌 해결하기
// 충돌을 해결하는 방법에는 2가지가 있다.
// 1. 해시 테이블의 주소 바깥에 새롱누 공간을 할당하여 문제를 수습하는 것이다.(개방 해싱)
// 2. 처음에 주어진 해시 테이블의 공간 안에서 문제를 해결하는 것이다.(폐쇄 해싱)

// 개방 해싱 기반의 충돌해결 기법인 체이닝
// 해시 함수가 서로 다른 키에 대해 같은 주소값을 반환해서 충돌이 발생하면 각 데이터를 해당 주소에 있는 링크드 리스트에 삽입하여 문제를 해결하는 기법이다.
// 체이닝 기반의 해시 테이블은 데이터 대신 링크드 리스트에 대한 포인터를 관리한다. 데이터들은 해시 테이블의 각 요소가 가리키고 있는 이 링크드 리스트에 저장이 된다.
// 체이닝 기반의 해시 테이블은 다음과 같은 순서로 탐색을 수행한다.
// 1. 찾고자 하는 목표값을 해싱하여 링크드 리스트가 저장되어있는 주소를 찾는다.
// 2. 이 주소를 이용하여 해시 테이블에 저장되어 있는 링크드 리스트에 대한 포인터를 생성한다.
// 3. 링크드 리스트의 앞에서부터 뒤까지 차례대로 이동하며 목표값이 저장되어 있는지 비교한다. 목표값과 링크드 리스트 내의 노드 값이 일치하면 해당 노드의 주소를 반환한다.

// 체이닝 기반 해시 테이블의 삽입도 탐색과 비슷한 원리로 동작한다.
// 해시 함수를 이용해서 데이터가 삽입될 링크드 리스트의 주소를 얻어낸 후에, 링크드 리스트가 비어있으면 데이터를 바로 삽입하고, 그렇지 않은 경우는 링크드 리스트 헤드 앞에 삽입한다.
// 테일 뒤가 아닌 헤드 앞인 이유는 순차 탐색을 찾아 테일을 찾게하지 않기 위해서 이다.

// 체이닝의 성능을 더 끌어 올리고자 한다면
// 해시 테이블 + 레드블랙트리 형태로 만들자.
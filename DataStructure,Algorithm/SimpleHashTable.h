#pragma once
#include "stdafx.h"

typedef int KeyType;
typedef int ValueType;

typedef struct tagNode
{
	KeyType Key;
	ValueType Value;

} Node;

typedef struct tagHashTable
{
	int TableSize;
	Node* Table;
} HashTable;

HashTable* SHT_CreateHashTable(int TableSize);
void SHT_Set(HashTable* HT, KeyType Key, ValueType Value);
ValueType SHT_Get(HashTable* HT, KeyType Key);
void SHT_DestroyHashTable(HashTable* HT);
int SHT_Hash(KeyType Key, int TableSize);

// 자릿수 접기(Digits Folding)
// 해시 테이블 내의 동일한 주소를 반환할 가능성(Collision).
// 해시 테이블 내의 일부 지역의 주소들을 집중적으로 반환하는 결과로 데이터들이 한 곳에 모이는 문제(클러스터(Cluster)).
// 문자열을 키로 사용할 경우 ASCII코드로 변환하여 각 자리수를 더해서 Hash 실행
// 해시 테이블의 전체를 사용하지 못하는 문제가 발생
// 이때는 Shift연산으로 모든 주소를 사용할 수 있게 만든다.

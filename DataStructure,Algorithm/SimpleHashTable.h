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

// �ڸ��� ����(Digits Folding)
// �ؽ� ���̺� ���� ������ �ּҸ� ��ȯ�� ���ɼ�(Collision).
// �ؽ� ���̺� ���� �Ϻ� ������ �ּҵ��� ���������� ��ȯ�ϴ� ����� �����͵��� �� ���� ���̴� ����(Ŭ������(Cluster)).
// ���ڿ��� Ű�� ����� ��� ASCII�ڵ�� ��ȯ�Ͽ� �� �ڸ����� ���ؼ� Hash ����
// �ؽ� ���̺��� ��ü�� ������� ���ϴ� ������ �߻�
// �̶��� Shift�������� ��� �ּҸ� ����� �� �ְ� �����.

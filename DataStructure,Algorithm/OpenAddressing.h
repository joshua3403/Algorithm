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

// ���� �ּҹ�(Open Addressing)
// �浹�� �Ͼ �� �ؽ� �Լ��� ���� ����� �ּҰ� �ƴϴ��� �󸶵��� �ٸ� �ּҸ� ����� �� �ִٷ� ����ϴ� �浹 �ذ� �˰���
// �浹�� �Ͼ�� �ؽ� ���̺� ���� ���ο� �ּҸ� Ž���Ͽ� �浹�� �����͸� �Է��ϴ� ������� �۵�
// ���� Ž��
// �ؽ� �Լ��κ��� �� �ּҿ� �̹� �ٸ� �����Ͱ� �ԷµǾ� ������ �߰��ϸ�, ���� �ּҿ��� ���� ������ ���� �ּҷ� �̵��Ѵ�.
// �� �ּҿ����� �ٸ� �����Ͱ� �־� �浹�� �߻��ϸ� �� �� ���� �ּҷ� �̵��Ѵ�. �̷��� �ؼ� ��� �ִ� �ּҸ� �߰��ϸ� �װ��� �����͸� �Է��Ѵ�.
// ���� Ž��
// ����Ž��� ��������� ������ ����ŭ �̵� �� �� �̵����� �������� �þ ���̴�.
// ���� �ؽ�
// �ؽ� �Լ��� Ű�� �Է��Ͽ� �� �ּҿ��� �浹�� �Ͼ�� ���ο� �ּҸ� ���� �̵��Ѵ�. �̶� �̵����� �� 2�� �ؽ� �Լ��� �������.
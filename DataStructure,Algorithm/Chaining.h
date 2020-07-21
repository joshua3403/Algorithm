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

// �浹 �ذ��ϱ�
// �浹�� �ذ��ϴ� ������� 2������ �ִ�.
// 1. �ؽ� ���̺��� �ּ� �ٱ��� ���մ� ������ �Ҵ��Ͽ� ������ �����ϴ� ���̴�.(���� �ؽ�)
// 2. ó���� �־��� �ؽ� ���̺��� ���� �ȿ��� ������ �ذ��ϴ� ���̴�.(��� �ؽ�)

// ���� �ؽ� ����� �浹�ذ� ����� ü�̴�
// �ؽ� �Լ��� ���� �ٸ� Ű�� ���� ���� �ּҰ��� ��ȯ�ؼ� �浹�� �߻��ϸ� �� �����͸� �ش� �ּҿ� �ִ� ��ũ�� ����Ʈ�� �����Ͽ� ������ �ذ��ϴ� ����̴�.
// ü�̴� ����� �ؽ� ���̺��� ������ ��� ��ũ�� ����Ʈ�� ���� �����͸� �����Ѵ�. �����͵��� �ؽ� ���̺��� �� ��Ұ� ����Ű�� �ִ� �� ��ũ�� ����Ʈ�� ������ �ȴ�.
// ü�̴� ����� �ؽ� ���̺��� ������ ���� ������ Ž���� �����Ѵ�.
// 1. ã���� �ϴ� ��ǥ���� �ؽ��Ͽ� ��ũ�� ����Ʈ�� ����Ǿ��ִ� �ּҸ� ã�´�.
// 2. �� �ּҸ� �̿��Ͽ� �ؽ� ���̺� ����Ǿ� �ִ� ��ũ�� ����Ʈ�� ���� �����͸� �����Ѵ�.
// 3. ��ũ�� ����Ʈ�� �տ������� �ڱ��� ���ʴ�� �̵��ϸ� ��ǥ���� ����Ǿ� �ִ��� ���Ѵ�. ��ǥ���� ��ũ�� ����Ʈ ���� ��� ���� ��ġ�ϸ� �ش� ����� �ּҸ� ��ȯ�Ѵ�.

// ü�̴� ��� �ؽ� ���̺��� ���Ե� Ž���� ����� ������ �����Ѵ�.
// �ؽ� �Լ��� �̿��ؼ� �����Ͱ� ���Ե� ��ũ�� ����Ʈ�� �ּҸ� �� �Ŀ�, ��ũ�� ����Ʈ�� ��������� �����͸� �ٷ� �����ϰ�, �׷��� ���� ���� ��ũ�� ����Ʈ ��� �տ� �����Ѵ�.
// ���� �ڰ� �ƴ� ��� ���� ������ ���� Ž���� ã�� ������ ã������ �ʱ� ���ؼ� �̴�.

// ü�̴��� ������ �� ���� �ø����� �Ѵٸ�
// �ؽ� ���̺� + �����Ʈ�� ���·� ������.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
	char* word;
	int count;
	Node* next; //��������� �� ��������� �������
};

typedef  Node *PNode; // ��� ������: ��������� �� ����

PNode CreateNode(char NewWord[]);

void AddFirst(PNode &Head, PNode NewNode);

void AddAfter(PNode p, PNode NewNode);

void AddLast(PNode &Head, PNode NewNode);

void AddBefore(PNode &Head, PNode p, PNode NewNode);

PNode Find(PNode Head, char NewWord[]);

PNode FindPlace(PNode Head, char NewWord[]);

void DeleteNode(PNode &Head, PNode OldNode);

void DeletePNode(PNode &Head);

void PrintNode(PNode &Head);
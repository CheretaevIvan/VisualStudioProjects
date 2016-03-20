#include <stdio.h>
#include <inttypes.h>
#include <malloc.h>

struct Data{
	int data;
};

struct Node{
	Data data;
	Node *left, *right, *parent;
};

typedef Node *PNode;

int CompareData(Data, Data);

void PrintData(Data);

void MakeTree(PNode *, Data);

void AddNode(PNode *, Data);

void DelNode(PNode *, PNode);

PNode FindTree(PNode *, Data);

PNode Max(PNode *);

PNode Min(PNode *);

PNode Next(PNode);

PNode Prev(PNode);

PNode Find(PNode *, Data);

void PrintNode(PNode *);
#include <stdio.h>
#include <malloc.h>

#define ADDITION -1
#define SUBSTRACTION -2
#define MULTIPLICATION -3
#define DIVISION -4
#define OPENING_BRACKET  -5
#define CLOSING_BRACKET -6
#define ERROR -8
#define OPERAND -9
#define DATA -10

struct Data
{
	double data;
	int type;
};

struct Node{
	Data data;
	Node *next, *prev;
};

typedef Node *PNode;

struct Stack
{
	PNode Head, Tail;
};

void Push(Stack *, Data);

Data Pop(Stack *);

Data Peek(Stack *);

void PrintNode(Stack);
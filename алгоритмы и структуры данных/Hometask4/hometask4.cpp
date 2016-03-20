#include <stdio.h>
#include <time.h>
#include <inttypes.h>
#include <stdlib.h>

int a1 = 0;
int a2 = 0;
int a3 = 0;
int a4 = 0;
int n = 0;
int count = 0;
int p = 2147483647;

int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

struct Node{
	int a, b, c, d;
	struct Node *next;
};

typedef struct Node *PNode;

PNode CreateNode(int a, int b, int c, int d)
{
	PNode NewNode = (PNode)malloc(sizeof(struct Node));
	NewNode->a = a;
	NewNode->b = b;
	NewNode->c = c;
	NewNode->d = d;
	NewNode->next = NULL;
	return NewNode;
}

void AddFirst(PNode *Head, PNode NewNode)
{
	NewNode->next = *Head;
	*Head = NewNode;
}

void AddClass(PNode *Head, int a, int b, int c, int d){
	PNode p = *Head;
	while (p){
		if (p->a == a && p->b == b && p->c == c && p->d == d)
			return;
		p = p->next;
	}
	AddFirst(Head, CreateNode(a, b, c, d));
	count++;
}

void DelNode(PNode *Head){
	PNode p = *Head;
	while (*Head){
		p = (*Head)->next;
		free(*Head);
		Head = &p;
	}
}

int gcd(int a, int b) {
	while (a != b) {
		if (a > b) a -= b;
		else b -= a;
	}
	return a;
}

int hash(int a, int b, int c, int d){
	return (a1*a + a2*b + a3*c + a4*d) %p % n;
}

int main(int argv, char** argc){
	FILE *fin, *fout;
	if (argv > 1){
		fin = fopen(argc[1], "r");
		fout = fopen(argc[2], "w");
	}
	else
	{
		fin = stdin;
		fout = stdout;
	}
	srand(time(NULL));
	
	fscanf(fin, "%"SCNi32, &n);
	a1 = rand() % n;
	a2 = rand() % n;
	a3 = rand() % n;
	a4 = rand() % n;
	int gcd_ab = 0, gcd_ac = 0, h = 0;
	int * side = (int*)malloc(3 * sizeof(int));
	if (!side)
		return 1;
	PNode *hashmap = (PNode*)malloc(n*sizeof(PNode));
	if (!hashmap)
		return 1;
	for (size_t i = 0; i < n; i++)
		hashmap[i] = NULL;
	for (size_t i = 0; i < n; i++){
		fscanf(fin, "%"SCNi32" %"SCNi32" %"SCNi32, &side[0], &side[1], &side[2]);
		qsort(side, 3, sizeof(int), compare);
		gcd_ab = gcd(side[0], side[1]);
		gcd_ac = gcd(side[0], side[2]);
		h = hash(side[1] / gcd_ab, side[1] % gcd_ab, side[2] / gcd_ac, side[2] % gcd_ac);
		AddClass(&hashmap[h], side[1] / gcd_ab, side[1] % gcd_ab, side[2] / gcd_ac, side[2] % gcd_ac);
	}
	fprintf(fout, "%"PRIi32, count);
	for (int i = 0; i < n; i++){
		DelNode(&hashmap[i]);
	}
	free(hashmap);
	free(side);
	system("pause");
	return 0;
}
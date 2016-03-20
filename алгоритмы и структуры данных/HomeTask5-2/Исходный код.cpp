#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int count = 0, count_i = 0;

struct Data
{
	int left_x, left_y, right_x, right_y;
};

struct Node{
	struct Data data;
	struct Node *left, *right, *parent;
};

typedef struct Node *PNode;

int CompareData(const void* param1, const void* param2){
	struct Data *a = (struct Data *)param1;
	struct Data *b = (struct Data *)param2;
	return ((a->left_y - b->left_y) == 0 ? (a->left_x - b->left_x) : (a->left_y - b->left_y));
}

void AddNode(PNode *Head, struct Data *data){
	PNode newNode = (PNode)malloc(sizeof(struct Node));
	newNode->data = *data;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	PNode parentNode = NULL;
	PNode p = *Head;
	while (p){
		parentNode = p;
		if (parentNode->data.left_x<data->left_x && parentNode->data.right_x > data->right_x && parentNode->data.left_y<data->left_y && parentNode->data.right_y > data->right_y)
			return;
		if (data->left_x <= p->data.left_x)
			p = p->left;
		else
			p = p->right;
	}
	if (!parentNode){
		*Head = newNode;
		count++;
	}
	else{
		count++;
		newNode->parent = parentNode;
		if (data->left_x < parentNode->data.left_x){
			newNode->left = parentNode->left;
			parentNode->left = newNode;
		}
		else{
			newNode->right = parentNode->right;
			parentNode->right = newNode;
		}
	}
}

PNode Max(PNode *Tree){
	if (!Tree) return NULL;
	PNode p = *Tree;
	while (p->right) p = p->right;
	return p;
}

PNode Min(PNode *Tree){
	if (!Tree) return NULL;
	PNode p = *Tree;
	while (p->left) p = p->left;
	return p;
}

PNode Next(PNode node){
	return Min(&node->right);
}

PNode Prev(PNode node){
	return Max(&node->left);
}

void DelNode(PNode *Head, PNode node){
	if (!node || !Head)
		return;
	PNode y = NULL;
	PNode x = NULL;
	if (!node->left || !node->right)
		y = node;
	else
		y = Next(node);
	if (y->left)
		x = y->left;
	else
		x = y->right;
	if (x)
		x->parent = y->parent;
	if (y->parent)
		if (y == y->parent->left){
			y->parent->left = x;
		}
		else
			y->parent->right = x;
	else *Head = x;
	if (y != node){
		node->data = y->data;
		DelNode(Head, y);
	}
}



PNode Find(PNode *Tree, struct Data data){
	if (!*Tree)
		return NULL;
	if (CompareData(&data, &(*Tree)->data) == 0)
		return *Tree;
	else if (CompareData(&data, &(*Tree)->data) < 0)
		return Find(&(*Tree)->left, data);
	else return Find(&(*Tree)->right, data);
}

PNode FindLt(PNode *Tree, struct Data data){
	if (!*Tree)
		return NULL;
	if ((*Tree)->data.right_y<data.left_y)
		return *Tree;
	PNode result = FindLt(&(*Tree)->left, data);
	if (!result)
		return FindLt(&(*Tree)->right, data);
	return result;
}

int main(){
	int n = 0;

	//FILE *f = fopen("task.txt", "r");
	//PNode Tree = NULL;
	//PNode cur_to_del = NULL;
	//fscanf(f, "%"SCNi32, &n);
	//struct Data *p = (struct Data  *)malloc(n*sizeof(struct Data));
	//for (size_t i = 0; i < n; i++){
	//	fscanf(f, "%"SCNi32" %"SCNi32" %"SCNi32" %"SCNi32, &p[i].left_x, &p[i].left_y, &p[i].right_x, &p[i].right_y);
	//}

	PNode Tree = NULL;
	PNode cur_to_del = NULL;
	scanf("%"SCNi32, &n);
	struct Data *p = (struct Data  *)malloc(n*sizeof(struct Data));
	for (size_t i = 0; i < n; i++){
		scanf("%"SCNi32" %"SCNi32" %"SCNi32" %"SCNi32, &p[i].left_x, &p[i].left_y, &p[i].right_x, &p[i].right_y);
	}
	qsort(p, n, sizeof(struct Data), CompareData);
	for (size_t i = 0; i < n; i++){
		AddNode(&Tree, &p[i]);
		cur_to_del = FindLt(&Tree, p[i]);
		while (cur_to_del){
			DelNode(&Tree, cur_to_del);
			cur_to_del = FindLt(&Tree, p[i]);
		}
	}
	//while (Tree){
	//	DelNode(&Tree, Tree);
	//	count++;
	//}
	printf("%"PRIi32, count);
	system("pause");
	return 0;
}
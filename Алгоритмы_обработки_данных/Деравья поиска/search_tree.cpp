#include "search_tree.h"

int CompareData(Data a, Data b){
	return a.data - b.data;
}

void PrintData(Data* data){
	printf("%"PRIi32, (*data).data);
}

void MakeTree(PNode *Head, Data data){
	AddNode(Head, data);
}

void AddNode(PNode *Head, Data data){
	PNode newNode = (PNode)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	PNode parentNode = NULL;
	PNode p = *Head;
	while (p){
		parentNode = p;
		if (CompareData(data, p->data) < 0)
			p = p->left;
		else
			p = p->right;
	}
	if (!parentNode){
		*Head = newNode;
	}
	else{
		newNode->parent = parentNode;
		if (CompareData(data, parentNode->data) < 0){
			parentNode->left = newNode;
		}
		else{
			parentNode->right = newNode;
		}
	}
}

void PrintNode(PNode *Tree){
	if (*Tree){
		printf("Элемент: ");
		PrintData(&(*Tree)->data);
		if ((*Tree)->left){
			printf(" Л: ");
			PrintData(&(*Tree)->left->data);
		}
		else
			printf(" Л: *");
		
		if ((*Tree)->right){
			printf(" П: ");
			PrintData(&(*Tree)->right->data);
		}
		else 
			printf(" П: *");
		printf("\n");
		if ((*Tree)->left){
			PrintNode(&(*Tree)->left);
		}
		if ((*Tree)->right){
			PrintNode(&((*Tree)->right));
		}
	}
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
	if (y == y->parent->left){
		y->parent->left = x;
	}
	else
		y->parent->right = x;
	if (y != node){
		node->data = y->data;
		DelNode(Head, y);
	}
	free(y);
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

PNode Find(PNode *Tree, Data data){
	if (!*Tree)
		return NULL;
	if (CompareData(data, (*Tree)->data) == 0)
		return *Tree;
	else if (CompareData(data, (*Tree)->data) < 0)
		return Find(&(*Tree)->left, data);
	else return Find(&(*Tree)->right, data);
}
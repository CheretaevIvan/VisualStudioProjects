#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int count = 0;

struct Retangle{
	int left_x, left_y, right_x, right_y;
};

typedef enum { DOWN, UP } sideType;

struct Side
{
	int left, right, y;
	sideType type;
};


int CompareData(const void* param1, const void* param2){
	struct Side *a = (struct Side *)param1;
	struct Side *b = (struct Side *)param2;
	return ((a->y - b->y) == 0 ? (a->left - b->left) : (a->y - b->y));
}

typedef struct Side T;                  /* type of item to be stored */
#define compLT(a,b) (a.left < b.left)
#define compEQ(a,b) ((a.left == b.left) && (a.right == b.right))

/* Red-Black tree description */
typedef enum { BLACK, RED } nodeColor;

typedef struct Node_ {
	struct Node_ *left;         /* left child */
	struct Node_ *right;        /* right child */
	struct Node_ *parent;       /* parent */
	nodeColor color;            /* node color (BLACK, RED) */
	T data;                     /* data stored in node */
} Node;

#define NIL &sentinel           /* all leafs are sentinels */
Node sentinel = { NIL, NIL, 0, BLACK, 0 };

Node *root = NIL;               /* root of Red-Black tree */

void rotateLeft(Node *x) {

	/**************************
	*  rotate node x to left *
	**************************/

	Node *y = x->right;

	/* establish x->right link */
	x->right = y->left;
	if (y->left != NIL) y->left->parent = x;

	/* establish y->parent link */
	if (y != NIL) y->parent = x->parent;
	if (x->parent) {
		if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
	}
	else {
		root = y;
	}

	/* link x and y */
	y->left = x;
	if (x != NIL) x->parent = y;
}

void rotateRight(Node *x) {

	/****************************
	*  rotate node x to right  *
	****************************/

	Node *y = x->left;

	/* establish x->left link */
	x->left = y->right;
	if (y->right != NIL) y->right->parent = x;

	/* establish y->parent link */
	if (y != NIL) y->parent = x->parent;
	if (x->parent) {
		if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;
	}
	else {
		root = y;
	}

	/* link x and y */
	y->right = x;
	if (x != NIL) x->parent = y;
}

void insertFixup(Node *x) {

	/*************************************
	*  maintain Red-Black tree balance  *
	*  after inserting node x           *
	*************************************/

	/* check Red-Black properties */
	while (x != root && x->parent->color == RED) {
		/* we have a violation */
		if (x->parent == x->parent->parent->left) {
			Node *y = x->parent->parent->right;
			if (y->color == RED) {

				/* uncle is RED */
				x->parent->color = BLACK;
				y->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
			}
			else {

				/* uncle is BLACK */
				if (x == x->parent->right) {
					/* make x a left child */
					x = x->parent;
					rotateLeft(x);
				}

				/* recolor and rotate */
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				rotateRight(x->parent->parent);
			}
		}
		else {

			/* mirror image of above code */
			Node *y = x->parent->parent->left;
			if (y->color == RED) {

				/* uncle is RED */
				x->parent->color = BLACK;
				y->color = BLACK;
				x->parent->parent->color = RED;
				x = x->parent->parent;
			}
			else {

				/* uncle is BLACK */
				if (x == x->parent->left) {
					x = x->parent;
					rotateRight(x);
				}
				x->parent->color = BLACK;
				x->parent->parent->color = RED;
				rotateLeft(x->parent->parent);
			}
		}
	}
	root->color = BLACK;
}

Node *insertNode(T data) {
	Node *current, *parent, *x;

	/***********************************************
	*  allocate node for data and insert in tree  *
	***********************************************/

	/* find where node belongs */
	current = root;
	parent = 0;
	while (current != NIL) {
		if ((data.left >= current->data.left) && (data.right <= current->data.right)) return (current);
		parent = current;
		current = compLT(data, current->data) ?
			current->left : current->right;
	}

	/* setup new node */
	if ((x = (Node*)malloc(sizeof(*x))) == 0) {
		printf("insufficient memory (insertNode)\n");
		exit(1);
	}
	x->data = data;
	x->parent = parent;
	x->left = NIL;
	x->right = NIL;
	x->color = RED;

	/* insert node in tree */
	if (parent) {
		if (compLT(data, parent->data))
			parent->left = x;
		else
			parent->right = x;
	}
	else {
		root = x;
	}

	insertFixup(x);
	return(x);
}

void deleteFixup(Node *x) {

	/*************************************
	*  maintain Red-Black tree balance  *
	*  after deleting node x            *
	*************************************/

	while (x != root && x->color == BLACK) {
		if (x == x->parent->left) {
			Node *w = x->parent->right;
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				rotateLeft(x->parent);
				w = x->parent->right;
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->parent;
			}
			else {
				if (w->right->color == BLACK) {
					w->left->color = BLACK;
					w->color = RED;
					rotateRight(w);
					w = x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				rotateLeft(x->parent);
				x = root;
			}
		}
		else {
			Node *w = x->parent->left;
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				rotateRight(x->parent);
				w = x->parent->left;
			}
			if (w->right->color == BLACK && w->left->color == BLACK) {
				w->color = RED;
				x = x->parent;
			}
			else {
				if (w->left->color == BLACK) {
					w->right->color = BLACK;
					w->color = RED;
					rotateLeft(w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				rotateRight(x->parent);
				x = root;
			}
		}
	}
	x->color = BLACK;
}

void deleteNode(Node *z) {
	Node *x, *y;

	if (!z || z == NIL) return;

	count++;

	if (z->left == NIL || z->right == NIL) {
		/* y has a NIL node as a child */
		y = z;
	}
	else {
		/* find tree successor with a NIL node as a child */
		y = z->right;
		while (y->left != NIL) y = y->left;
	}

	/* x is y's only child */
	if (y->left != NIL)
		x = y->left;
	else
		x = y->right;

	/* remove y from the parent chain */
	x->parent = y->parent;
	if (y->parent)
		if (y == y->parent->left)
			y->parent->left = x;
		else
			y->parent->right = x;
	else
		root = x;

	if (y != z) z->data = y->data;


	if (y->color == BLACK)
		deleteFixup(x);

	free(y);
}

Node *findNode(T data) {
	Node *current = root;
	while (current != NIL)
		if (compEQ(data, current->data))
			return (current);
		else
			current = compLT(data, current->data) ?
			current->left : current->right;
	return(0);
}

int main(){
	int n = 0;
	FILE *f = fopen("task.txt", "r");
	//scanf("%"SCNi32, &n);
	fscanf(f, "%"SCNi32, &n);
	struct Side *sides = (struct Side  *)malloc(n * 2 * sizeof(struct Side));
	struct Retangle *retangles = (struct Retangle *)malloc(n * sizeof(struct Retangle));
	for (size_t i = 0; i < n; i++){
		//scanf("%"SCNi32" %"SCNi32" %"SCNi32" %"SCNi32, &retangles[i].left_x, &retangles[i].left_y, &retangles[i].right_x, &retangles[i].right_y);
		fscanf(f, "%"SCNi32" %"SCNi32" %"SCNi32" %"SCNi32, &retangles[i].left_x, &retangles[i].left_y, &retangles[i].right_x, &retangles[i].right_y);
		sides[2 * i].left = retangles[i].left_x;
		sides[2 * i].right = retangles[i].right_x;
		sides[2 * i].y = retangles[i].left_y;
		sides[2 * i].type = DOWN;
		sides[2 * i + 1].left = retangles[i].left_x;
		sides[2 * i + 1].right = retangles[i].right_x;
		sides[2 * i + 1].y = retangles[i].right_y;
		sides[2 * i + 1].type = UP;
	}
	qsort(sides, n*2, sizeof(struct Side), CompareData);
	for (size_t i = 0; i < n * 2; i++){
		switch (sides[i].type)
		{
		case DOWN:
			insertNode(sides[i]);
			break;
		case UP:
			deleteNode(findNode(sides[i]));
			break;
		}
	}
	printf("%"PRIi32, count);
	system("pause");
	return 0;
}


#include "stack.h"

void Push(Stack *S, Data new_data)
{
	PNode NewNode = (PNode)malloc(sizeof(Node));
	NewNode->data = new_data;
	NewNode->next = (S->Head);
	NewNode->prev = NULL;

	if (S->Head) S->Head->prev = NewNode;
	S->Head = NewNode;

	if (!S->Tail) S->Tail = S->Head;
}

Data Pop(Stack *S)
{
	PNode TopNode = S->Head;
	Data pop_data;

	if (!TopNode) return{0, ERROR};
	pop_data = TopNode->data;

	S->Head = TopNode->next;

	if (S->Head) S->Head->prev = NULL;
	else S->Tail = NULL;
	return pop_data;
}

Data Peek(Stack *S)
{
	if (!S->Head) return{ 0, ERROR };
	return S->Head->data;
}

void PrintNode(Stack Head)
{
	Stack cur = Head;
	while (cur.Head)
	{
		switch (cur.Head->data.type)
		{
		case DATA:
			printf("������: %.0f\n", cur.Head->data.data);
			break;
		case OPERAND:
			switch ((int)cur.Head->data.data)
			{
			case ADDITION:
				printf("�������: +\n");
				break;
			case SUBSTRACTION:
				printf("�������: -\n");
				break;
			case MULTIPLICATION:
				printf("�������: *\n");
				break;
			case DIVISION:
				printf("�������: /\n");
				break;
			default:
				break;
			}
			break;
		}
		cur.Head = cur.Head->next;
	}
};
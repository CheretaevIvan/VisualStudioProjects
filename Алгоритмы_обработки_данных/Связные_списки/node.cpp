#include "node.h"

PNode CreateNode(char NewWord[])
{
	PNode NewNode = (Node*)malloc(sizeof(Node));
	NewNode->word = (char*)malloc(strlen(NewWord)*sizeof(char));
	strcpy(NewNode->word, NewWord);
	NewNode->count = 1;
	NewNode->next = NULL;
	return NewNode;
}

void AddFirst(PNode &Head, PNode NewNode)
{
	NewNode->next = Head;
	Head = NewNode;
}

void AddBefore(PNode &Head, PNode p, PNode	NewNode)
{
	PNode q = Head;
	if (Head == p) {
		AddFirst(Head, NewNode); // вставка перед первым узлом
			return;
	}
	while (q && q->next != p) // ищем узел, за которым следует p
		q = q->next;
	if (q) // если нашли такой узел,
		AddAfter(q, NewNode); // добавить новый после него
}

void AddAfter(PNode p, PNode NewNode)
{
	NewNode->next = p->next;
	p->next = NewNode;
}

void AddLast(PNode &Head, PNode NewNode)
{
	PNode q = Head;
	while (q->next)
		q = q->next;
	AddAfter(q, NewNode); 
}

PNode Find(PNode Head, char NewWord[])
{
	PNode q = Head;
	while (q && strcmp(q->word, NewWord))
		q = q->next;
	return q;
}

PNode FindPlace(PNode Head, char NewWord[])
{
	PNode q = Head;
	while (q && (strcmp(q->word, NewWord) < 0))
		q = q->next;
	return q;
}

void DeleteNode(PNode &Head, PNode OldNode)
{
	PNode q = Head;
	
	while (q && q->next != OldNode) // ищем элемент
		q = q->next;
	if (q!=NULL)
		q->next = OldNode->next;
	if (Head == OldNode){	
		Head = OldNode->next; // удаляем первый элемент
	}	

	delete OldNode; // освобождаем память	
}

void DeletePNode(PNode &Head){
	while (Head->next && Head->next != Head)
		DeleteNode(Head, Head);
	Head = NULL;
	delete Head;
}

void PrintNode(PNode &Head)
{
	PNode cur = Head;
	while (1)
	{
		printf("%s ", cur->word);
		cur = cur->next;
		if (cur == NULL)
			break;					
		if (cur == Head)
		{
			if (cur!=Head)
				printf("%s ", cur->word);
			break;
		}
			
	}
};
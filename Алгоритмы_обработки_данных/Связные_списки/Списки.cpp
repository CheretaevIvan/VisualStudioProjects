#include <locale.h>
#include <inttypes.h>
#include "node.h"

using namespace std;


long int GetChoise(void){
	char string[80] = "\n";
	int result = 0;
	while (result == 0)
	{
		printf("�������� ��������:\n 1. ������� ������ \n 2. �������� � ������ ������� \n 3. ������� �������� � ��������, �������� n\n 4. ��������� ������ \n 5. ������ ������ (�������� ���������, � �������� �������� 5)\n 6. ������ ������ (������ ������, n=5)\n 7. ������ �� ���������\n");
		gets(string);
		result = atoi(string);
		if ((result != 0) && (result != 1) && (result != 2) && (result != 3) && (result != 4) && (result != 5) && (result != 6) && (result != 7)) {
			printf("Uncorrect input. Please repeat your choose\n");
			result = 0;
		}
		else if (result == 0) printf("Uncorrect input. Please repeat your choose\n");
	};
	return result;
};


void DelWithNumber(PNode &head, int step)
{
	PNode cur = head, next_cur = head;
	int i = 0;
	while (1)//|| cur->next!=cur
	{		
		if (cur->next == cur)
			break;
		next_cur = cur->next;
		if ((i + 1) % step == 0)			
			DeleteNode(head, cur);
		i++;
		if (next_cur == NULL)
			break;
		cur = next_cur;		
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	PNode cur = NULL;
	PNode head = NULL;
	int number_to_del = 0;
	int count_node = 30;
	char* s = (char*)malloc(10 * sizeof(char));
	char* s1 = (char*)malloc(10 * sizeof(char));
	while (true)
	{
		int ch_menu = GetChoise();
		switch (ch_menu)
		{
		case 1: // ������� ������
			if (head != NULL)
				DeletePNode(head);
			printf("������� ������ ��� ���������� ������: ");
			scanf("%s", s);
			head = CreateNode(s);
			break;
		case 2: // �������� ������� � ������
			if (head == NULL){
				printf("������ ������\n");
			}
			else{
				printf("������� ������ ��� ���������� ������: ");
				scanf("%s", s1);
				cur = CreateNode(s1);
				AddLast(head, cur);
			}
			break;
		case 3: // ������� �������� �� ������
			if (head == NULL){
				printf("������ ������\n");
			}
			else{
				printf("������� n: ");
				scanf("%"PRIi32, &number_to_del);
				DelWithNumber(head, number_to_del);
			}
			break;
		case 4: // ��������� ������
			if (head == NULL){
				printf("������ ������\n");
			}
			else{
				cur = head;
				while (cur->next && cur->next != head)
					cur = cur->next;
				cur->next = head;
			}
			break;
		case 5: // ������ �������� ������
			if (head != NULL){
				cur = head;
				while (cur->next && cur->next != head)
					cur = cur->next;
				cur->next = NULL;
				PNode last = cur->next;
				printf("��������� ������\n");
				PrintNode(head);
				DelWithNumber(head, 5);
				cur = head;
				while (cur->next && cur->next != head)
					cur = cur->next;
				cur->next = last;
			}
			else
				printf("������ ������\n");
			break;

		case 6: // ����� (n=5)
			if (head != NULL){
				cur = head;
				while (cur->next && cur->next != head)
					cur = cur->next;
				PNode last = cur->next;
				cur->next = head;
				printf("��������� ������\n");
				PrintNode(head);
				DelWithNumber(head, 5);
				cur = head;
				while (cur->next && cur->next != head)
					cur = cur->next;
				cur->next = last;
			}
			else
				printf("������ ������\n");
			break;
		case 7:
			if (head != NULL)
				DeletePNode(head);
			number_to_del = 5;
			_itoa(1, s, 10);
			head = CreateNode(s);
			for (int i = 2; i < count_node + 1; i++)
			{
				_itoa(i, s1, 10);
				cur = CreateNode(s1);
				AddLast(head, cur);
			}
		}
		
		printf("\n������� ������:\n");
		if (head!=NULL) 
			PrintNode(head);
		else 
			printf("������ ������");

		printf("\n��� ����������� ������� Enter\n");
		gets(s);
	}
}
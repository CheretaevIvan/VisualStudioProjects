#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include "search_tree.h"

long int GetChoise(void){
	char string[80] = "\n";
	int result = 0;
	while (result == 0)
	{
		printf("�������� ��������:\n 1. ������� ������\n 2. �������� �������\n 3. ������� �������\n 4. ����� �������\n");
		gets(string);
		result = atoi(string);
		if ((result != 0) && (result != 1) && (result != 2) && (result != 3) && (result != 4)) {
			printf("Uncorrect input. Please repeat your choose\n");
			result = 0;
		}
		else if (result == 0) printf("Uncorrect input. Please repeat your choose\n");
	};
	return result;
};

int main()
{
	setlocale(LC_ALL, "ru");
	int data = 0, n = 0;
	char *str = (char*)malloc(81 * sizeof(char));
	PNode Tree = NULL, find_node = NULL;
	int i = 0, count_number = 0;
	double result = 0;
	while (1)
	{
		int choice = GetChoise();
		switch (choice)
		{
		case 1:
			printf("������� ���������� ���������: ");
			scanf("%"PRIi32, &n);
			printf("������� ��������: ");
			for (size_t i = 0; i < n; i++){
				scanf("%"PRIi32, &data);
				AddNode(&Tree, Data{ data });
			}
			PrintNode(&Tree);
			gets(str);
			break;
		case 2:
			printf("������� ������: ");
			scanf("%"PRIi32, &data);
			AddNode(&Tree, Data{ data });
			PrintNode(&Tree);
			gets(str);
			break;
		case 3:
			printf("������� ������: ");
			scanf("%"PRIi32, &data);
			DelNode(&Tree, Find(&Tree, Data{ data }));
			PrintNode(&Tree);
			gets(str);
			break;
		case 4:
			printf("������� ������: ");
			scanf("%"PRIi32, &data);
			find_node = Find(&Tree, Data{ data });
			if (find_node)
				printf("������� ������\n");
			else 
				printf("������� �� ������\n");
			gets(str);
			break;
		default:
			break;
		}
		printf("\n");
	}
	free(str);
	return 0;
}
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include "stack.h"

double result_from_inv_pol(Stack *inv_pol){
	Stack stack = Stack{ NULL, NULL };
	Data symbol = Data{ 0, DATA };
	Data left = {0, 0}, right = {0, 0};
	while (inv_pol->Head)
	{
		symbol = Pop(inv_pol);
		switch (symbol.type)
		{
		case DATA:
			Push(&stack, symbol);
			break;
		case OPERAND:
			switch ((int)symbol.data)
			{
			case ADDITION:
				right = Pop(&stack);
				left = Pop(&stack);
				Push(&stack, Data{ left.data + right.data, DATA });
				break;
			case SUBSTRACTION:
				right = Pop(&stack);
				left = Pop(&stack);
				Push(&stack, Data{ left.data - right.data, DATA });
				break;
			case MULTIPLICATION:
				right = Pop(&stack);
				left = Pop(&stack);
				Push(&stack, Data{ left.data * right.data, DATA });
				break;
			case DIVISION:
				right = Pop(&stack);
				left = Pop(&stack);
				Push(&stack, Data{ left.data / right.data, DATA });
				break;
			default:
				break;
			}
		default:
			break;
		}
	}
	return Pop(&stack).data;
}


bool is_rigth_assoc(int this_operator){
	switch (this_operator)
	{
	case SUBSTRACTION:
	case DIVISION:
	case ADDITION:
	case MULTIPLICATION:
	default:
		return 0;
		break;
	}
}

int priority(int oper){
	switch (oper)
	{
	case ADDITION:
	case SUBSTRACTION:
		return 1;
	case DIVISION:
	case MULTIPLICATION:
		return 2;
	case OPENING_BRACKET:
		return INT_MAX;
	default:
		return 0;
		break;
	}
}


void to_inv_pol(Stack *stack, char *str, bool is_inv)
{
	Stack stack_oper = Stack{ NULL, NULL };
	char *number = (char*)malloc(81 * sizeof(char));
	int i = 0, count_number = 0, oper = 0;
	Data operand = Data{ 0, DATA };
	number[count_number] = '\0';
	while (str[i])
	{
		if (isdigit(str[i]))
		{
			number[count_number++] = str[i];
			number[count_number] = '\0';
		}
		else
		{
			if (number[0]){
				Push(stack, Data{ atof(number), DATA });
				count_number = 0;
				number[count_number] = '\0';
			}
			switch (str[i])
			{
			case '.':
				number[count_number++] = str[i];
				number[count_number] = '\0';
				break;
			case '-':
				oper = SUBSTRACTION;
				break;
			case '+':
				oper = ADDITION;
				break;
			case '/':
				oper = DIVISION;
				break;
			case '*':
				oper = MULTIPLICATION;
				break;
			case '(':
				Push(&stack_oper, Data{ OPENING_BRACKET, OPERAND });
				break;
			case ')':
				operand = Pop(&stack_oper);
				while (operand.data != OPENING_BRACKET && stack_oper.Head){
					Push(stack, operand);
					operand = Pop(&stack_oper);
				}
				operand = Pop(&stack_oper);
				if (&operand)
					Push(stack, operand);
				break;
			default:
				break;
			}
			if (oper){
				if (is_rigth_assoc(oper)){
					while (priority(oper)<priority(Peek(&stack_oper).data) && stack_oper.Head)
						Push(stack, Pop(&stack_oper));
				}
				else{
					while (priority(oper) <= priority(Peek(&stack_oper).data) && stack_oper.Head)
					{
						Push(stack, Pop(&stack_oper));
					}
				}
				if (!is_inv)
					Push(&stack_oper, Data{ oper, OPERAND });
				else
					Push(stack, Data{ oper, OPERAND });
				oper = 0;
			}
		}
		i++;
	}
	if (number[0])
		Push(stack, Data{ atof(number), DATA });
	while (stack_oper.Head)
		Push(stack, Pop(&stack_oper));
	free(number);
	Stack stack_buf = Stack{ NULL, NULL };
	Stack stack_buf2 = Stack{ NULL, NULL };
	while (stack->Head)
		Push(&stack_buf, Pop(stack));
	while (stack_buf.Head)
		Push(&stack_buf2, Pop(&stack_buf));
	while (stack_buf2.Head)
		Push(stack, Pop(&stack_buf2));
}

void brackets(char *str)
{
	Stack stack_oper = Stack{ NULL, NULL };
	Data operand = Data{ 0, DATA };
	int i = 0, count_bracket = 0;
	while (str[i])
	{
		switch (str[i])
		{
		case '(':
			Push(&stack_oper, Data{ ++count_bracket, OPENING_BRACKET });
			printf("%d( ", count_bracket);
			break;
		case ')':
			operand = Pop(&stack_oper);
			printf("%d) ", (int)operand.data);
			break;
		default:
			break;
		}
		i++;
	}
}



long int GetChoise(void){
	char string[80] = "\n";
	int result = 0;
	while (result == 0)
	{
		printf("Выберите действие:\n 1. ввести арифметическое выражение\n 2. Ввести выражение в постфикной форме\n 3. Ввести правильную скобочную последовательность\n");
		gets(string);
		result = atoi(string);
		if ((result != 0) && (result != 1) && (result != 2) && (result != 3)) {
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
	Stack stack = Stack{ NULL, NULL };
	char *str = (char*)malloc(81 * sizeof(char));
	int i = 0, count_number = 0;
	double result = 0;
	while (1)
	{
		int choice = GetChoise();
		switch (choice)
		{
		case 1:
			printf("Введите арифметическое выражение: ");
			gets(str);
			to_inv_pol(&stack, str, false);
			PrintNode(stack);
			result = result_from_inv_pol(&stack);
			printf("Результат выражения: %f\n", result);
			break;
		case 2:
			printf("Введите арифметическое выражение в постфиксной форме: ");
			gets(str);
			to_inv_pol(&stack, str, true);
			result = result_from_inv_pol(&stack);
			printf("Результат выражения: %f\n", result);
			break;
		case 3:
			printf("Введите правильную скобочную последовательность: ");
			gets(str);
			printf("Номера позиций пар скобок: ");
			brackets(str);
		default:
			break;
		}
	}
	free(str);
	return 0;
}
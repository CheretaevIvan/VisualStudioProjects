#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	int x[] = { 1, 3, 0, 7, 0, 0, 4, 6, 8, 0, 9, 5, 0, 2, 1 };
	int i = 0, j = 0;
	for (; i < 15; i++){
		if (!x[i])
			j++;
	}
	j = 15 - j;
	int* memory = (int*)malloc(j * sizeof(int));
	for (j = 0; i; i--)
		if (x[i-1])
			memory[j++] = x[i-1];
	for (; i < 15; i++)
		printf("%d ", x[i]);
	printf("\n");
	for (; j; j--)
		printf("%d ", memory[j-1]);
	system("pause");
	return 0;
}
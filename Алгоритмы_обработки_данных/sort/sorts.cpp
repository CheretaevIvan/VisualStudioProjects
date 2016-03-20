#include <time.h>
#include <stdio.h>
#include <locale.h>
#include <inttypes.h>
#include "all_sort.h"
#include <stdlib.h>

double test_qsort(BaseType **a, size_t m, size_t n){
	for (size_t i = 0; i < m; i++)
		for (size_t j = 0; j < n; j++){
		a[i][j] = rand() % 255;
		}
	clock_t start = clock();
	for (size_t i = 0; i < m; i++)
		qs(a[i], 0, n-1);
	clock_t end = clock();
	return 1000*(end - start)/CLOCKS_PER_SEC/m;
}

double test_shellsort(BaseType **a, size_t m, size_t n){
	for (size_t i = 0; i < m; i++)
		for (size_t j = 0; j < n; j++){
		a[i][j] = rand() % 255;
		}
	clock_t start = clock();
	for (size_t i = 0; i < m; i++)
		ShellsSort(a[i], n - 1);
	clock_t end = clock();
	return 1000 * (end - start) / CLOCKS_PER_SEC / m;
}

double test_radix(BaseType **a, size_t m, size_t n){
	for (size_t i = 0; i < m; i++)
		for (size_t j = 0; j < n; j++){
			a[i][j] = rand() % 255;
		}
	clock_t start = clock();
	for (size_t i = 0; i < m; i++)
		radixsort(a[i], n - 1);
	clock_t end = clock();
	return 1000 * (end - start) / CLOCKS_PER_SEC / m;
}


int main(){
	setlocale(LC_ALL, "ru");
	BaseType **array;
	int n = 0, m = 4;
	printf("Введите количество элементов: ");
	scanf("%"SCNi32, &n);
	array = (BaseType **)malloc(m*sizeof(BaseType *));
	for (size_t i = 0; i < m;i++)
		array[i] = (BaseType *)malloc(n*sizeof(BaseType));
	printf("Количество тестов для каждого алгортима сортировки: %"PRIi32"\n", m);
	printf("Среднее время сортировки алгоритмом быстрой сортировки : %f ms\n", test_qsort(array, m, n));
	printf("Среднее время сортировки алгоритмом сортировки Шелла : %f ms\n", test_shellsort(array, m, n));
	printf("Среднее время сортировки алгоритмом поразрядной сортировки : %f ms\n", test_radix(array, m, n));
	system("pause");
	return 0;
}
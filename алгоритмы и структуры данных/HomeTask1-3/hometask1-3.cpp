#include<stdio.h>
#include<inttypes.h>
#include<stdint.h>

#include<iostream>

int bin_find(int *ea, int *eb, int*ec, int n, int xa, int xb, int xc){
	/* Номер первого элемента в массиве */
	size_t first = 0;
	/* Номер элемента в массиве, СЛЕДУЮЩЕГО ЗА последним */
	size_t last = n;
	if (ea[n] < xa && eb[n] < xb && ec[n] < xc) {
		return n+1;
	}
	while (first < last) {
		/* Номер элемента из "середины" массива*/
		size_t mid = first + (last - first) / 2;

		if (xa < ea[mid] && xb < eb[mid] && xc < ec[mid])
			last = mid;
		else
			first = mid + 1;
	}
	if (last && ea[last - 1] < xa && ea[last] > xa && eb[last - 1] < xb && eb[last] > xb && ec[last - 1] < xc &&  ec[last] > xc) {
		return last;
	}
	else {
		return -1;
	}
}

int main()
{
	/* Считываем количество кубиков */
	int n = 0;	
	scanf("%"SCNi32, &n);
	/* выделяем память под хранение данных */
	int *a = new int[n];
	int *b = new int[n];
	int *c = new int[n];
	int *ea = new int[n+1];
	int *eb = new int[n+1];
	int *ec = new int[n+1];
	/* Проводим иниализацию массивов, хранящих окончания подпоследовательностей*/
	ea[0] = INT32_MIN;
	eb[0] = INT32_MIN;
	ec[0] = INT32_MIN;
	for (int i = 1; i < n + 1; i++)
	{
		ea[i] = INT32_MAX;
		eb[i] = INT32_MAX;
		ec[i] = INT32_MAX;
	}
	/* Считываем параметры кубиков: a, b, c*/
	for (int i = 0; i < n; i++)
		scanf("%"SCNi32" %"SCNi32" %"SCNi32, &a[i], &b[i], &c[i]);
	int dmax = 1;
	for (int i = 0; i < n; i++)
	{
		int j = bin_find(ea, eb, ec, dmax, a[i], b[i], c[i]);
		dmax = j>dmax ? j : dmax;
		if (j != -1){
			ea[j] = a[i];
			eb[j] = b[i];
			ec[j] = c[i];
		}
	}
	printf("%"PRIi32, dmax);
	delete[] a, b, c, ea, eb, ec;
	system("pause");
	return 0;
}
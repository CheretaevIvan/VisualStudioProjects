#include "all_sort.h"

void swap(BaseType *a, BaseType *b){
	BaseType tmp = *a;
	*a = *b;
	*b = tmp;
}

void qs(BaseType* s_arr, BaseType first, BaseType last)
{
	BaseType i = first, j = last, x = s_arr[(first + last) / 2];

	do {
		while (s_arr[i] < x) i++;
		while (s_arr[j] > x) j--;

		if (i <= j) {
			if (s_arr[i] > s_arr[j]) swap(&s_arr[i], &s_arr[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		qs(s_arr, i, last);
	if (first < j)
		qs(s_arr, first, j);
}
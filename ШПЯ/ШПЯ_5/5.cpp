#include <iostream>

using namespace std;

int compare(const void* a, const void* b)
{
	if (a > b)
		return 1;
	if (a < b)
		return -1;
	return 0;
}

size_t FindIntesection(__int32* a, __int32* b, size_t n, __int32* result)
{
	size_t answerSize = 0;
	size_t aIdx = 0;
	size_t bIdx = 0;
	while (aIdx < n && bIdx < n){
		__int32 aVal = a[aIdx];
		__int32 bVal = b[bIdx];
		if (aVal < bVal)
			aIdx++;
		else 
			if (bVal < aVal)
				bVal++;
			else
			{
				result[answerSize++] = aVal;
				aIdx++;
				bIdx++;
			}
	}
	return answerSize;
}

int main()
{
	int n = 100;
	int *a = new int[n];
	int *b = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() / 1000;
		cout << a[i] << ' ';
		b[i] = rand() / 1000;
	}
	qsort(a, n, sizeof(int), compare);
	cout << endl << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	qsort(b, n, sizeof(int), compare);
	//int a[] = { 1, 2, 3, 4, 5, 6 };
	//int b[] = { 4, 5, 6, 7, 8, 9 };
	int* c = new int[];
	int len_c = FindIntesection(a, b, 6, c);
	for (int i = 0; i < len_c; i++)
		cout << c[i] << ' ';
	cin >> len_c;
}
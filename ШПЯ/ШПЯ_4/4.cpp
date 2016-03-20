#include <iostream>

using namespace std;

int main()
{
	int* a = new int[6]{1, 2, 10, 9, 5, 7};
	int size = 6;
	int count = 0;
	int i = 1;
	int j = 2;
	while (i < size)
		if (a[i - 1] > a[i])
		{
		i = j++;
		}
		else
		{
			int b = a[i];
			a[i] = a[i - 1];
			a[i - 1] = b;
			count++;
			i--;
			if (i == 0)
			{
				i = j++;
			}
		}
	for (int i = 0; i < size; i++)
		cout << a[i] << ' ';
	cout << endl << count;


	int b;
	cin >> b;
}
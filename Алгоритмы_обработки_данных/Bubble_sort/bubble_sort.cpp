#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void swap(int *a, int *b)
{
	int* c = a;
	a = b;
	b = c;
}

void bubble_sort(int *array, int length)
{
	for (int i = 0; i < length; i++)
		for (int j = 0; j < length - i - 1; j++)
			if (array[j] > array[j + 1])
				swap(array[j], array[j + 1]);
}


int main(int argc, char* argv[])
{
	streambuf *back_out = cout.rdbuf();
	streambuf *back_in = cin.rdbuf();
	ofstream output;
	ifstream input;
	if (argc >= 3)
	{
		input.open(argv[1]);
		output.open(argv[2]);
		cin.rdbuf(input.rdbuf());
		cout.rdbuf(output.rdbuf());
	}
	for (int i = 500; i < 10001; i += 500)
	{
		int *array = new int[i];
		for (int j = 0; j < i; j++)
			array[j] = rand() / 1000;
		clock_t t0 = clock();
		bubble_sort(array, i);
		clock_t t1 = clock();
		cout << (double)(t1 - t0) << ' ';		
	}
	cout.rdbuf(back_out);
	cin.rdbuf(back_in);
	input.close();
	output.close();
	return 0;
}
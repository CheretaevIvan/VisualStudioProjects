#include <iostream>
#include <fstream>
#include <ctime>
#include "C:\Users\Иван\documents\visual studio 2013\Projects\Алгоритмы_обработки_данных\allsort.hpp"
using namespace std;


void insert_sort(int *array, int length)
{
	if (length < 2) return;
	int count = 1;
	for (int i = 1; i < length; i++)
	{
		if (array[i] < array[i - 1])
		{
			int j = i;
			int temp = array[i];
			for (; j && array[j - 1] > temp; j--)
				array[j] = array[j - 1];
			array[j] = temp;
			cout << count++ << ". ";
			for (j = 0; j < length; j++)
				cout << array[j] << ' ';
			cout << endl;
		}		
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "RUS");
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

	//
	//for (int i = 1000; i < 50001; i += 2000)
	//{
	//	int *array = new int[i];
	//	for (int j = 0; j < i; j++)
	//	{
	//		array[j] = i - j;
	//	}
	//	cout << endl;
	//	double t0 = clock();
	//	insert_sort(array, i);
	//	double t1 = clock();
	//	cout << (double)(t1 - t0) << ' ';
	//}
	//cout << endl << endl;;

	//for (int k = 0; k < 5; k++)
	//{
	//	for (int i = 1000; i < 50001; i += 2000)
	//	{
	//		int *array = new int[i];
	//		for (int j = 0; j < i; j++)
	//		{
	//			array[j] = rand();
	//		}
	//		cout << endl;
	//		double t0 = clock();
	//		insert_sort(array, i);
	//		double t1 = clock();
	//		cout << (double)(t1 - t0) << ' ';
	//	}
	//	cout << endl;
	//}
	//cout << endl;

	for (int i = 10; i < 500; i += 2000)
	{
		int *array = new int[i];
		cout << "Исходный массив: ";
		for (int j = 0; j < i; j++)
		{
			array[j] = rand()%100;
			cout << array[j] << ' ';
		}
		cout << endl;
		cout << "Промежуточные результаты: " << endl;
		double t0 = clock();
		insert_sort(array, i);
		double t1 = clock();
		cout << "Конечный массив: " << endl;
		for (int j = 0; j < i; j++)
			cout << array[j] << ' ';
		cout << endl << "Время сортировки: " << (double)(t1 - t0) << "мс" << endl;
	}
	cout << endl;
	cout.rdbuf(back_out);
	cin.rdbuf(back_in);
	input.close();
	output.close();
	system("pause");
	return 0;
}
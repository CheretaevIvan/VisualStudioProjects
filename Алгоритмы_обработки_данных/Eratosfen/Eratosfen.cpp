#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int eratosfen(int n)
{
	int count = 0;
	char* mask = new char[8];
	for (int i = 0; i < 8; i++)
		mask[i] = 1 << (7 - i);
	int length = n % 8 == 0 ? n / 8 : n / 8 + 1;
	char* array = new char[length];
	for (int i = 0; i < length; i++)
		array[i] = 0xFF;
	cout << endl;
	for (int i = 2; i*i <= n; i++){
		cout << "Битовая маска после прохода по числу p = " << i << endl;
		for (int j = 2 * i - 1; j < n; j += i)
			array[j / 8] = array[j / 8] & (array[j / 8] ^ mask[j % 8]);
		for (int j = 0; j < n; j++){
			int a = (array[j / 8] & mask[j % 8]) ? 1 : 0;
			if (a) count++;
			cout << a;
		}

		cout << endl;
	}
	cout << "Итоговая битовая маска:\n";
	for (int j = 0; j < n; j++){
		int a = (array[j / 8] & mask[j % 8]) ? 1 : 0;
		if (a) count++;
		cout << a;
	}	
	cout << endl;
	cout << "Простые числа до " << n << endl;
	for (int j = 0; j < n; j++){
		int a = (array[j / 8] & mask[j % 8]) ? 1 : 0;
		if (a) cout << j+1 << " ";
	}
	return count;
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
	int n;
	cout << "Введите число n: ";
	cin >> n;
		double t0 = clock();
		eratosfen(n);
		double t1 = clock();
		cout << endl << "Время выполнения: " << (double)(t1 - t0) << "мс" << endl;
	cout << endl;
	cout.rdbuf(back_out);
	cin.rdbuf(back_in);
	input.close();
	output.close();
	system("pause");
	return 0;
}
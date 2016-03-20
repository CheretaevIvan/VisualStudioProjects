#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int binom_coef(int n, int k)
{
	if (k == 0 || k == n)
		return 1;
	return binom_coef(n - 1, k - 1) + binom_coef(n - 1, k);
	//int result = 1;
	//for (int i = n - k +1; i < n + 1; i++)
	//	result *= i;
	//for (int i = 1; i < k + 1; i++)
	//	result /= i;
	//return result;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");
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
	cout << "Введите номер строки: ";
	int N;
	cin >> N;
	int k;
	cout << "Введите номер коэффициента: ";
	cin >> k;
	int* last_str = new int{ 1 };
	int* cur_str = new int[2];
	for (int i = 0; i < N; i++)
	{
		cur_str = new int[i + 1];
		cur_str[0] = 1; 
		cur_str[i] = 1;
		for (int j = 1; j < i; j++)
			cur_str[j] = last_str[j - 1] + last_str[j];
		for (int j = 0; j < (N - i - ((N-i-1) % 2))/2 ; j++)
			cout << '\t';		
		for (int j = 0; j <= i; j++)
			if ((N - i - 1) % 2) cout << "    " << cur_str[j] << "\t";
			else cout << binom_coef(i, j) << "\t";
			//if ((N-i-1)%2) cout << "    " << cur_str[j] << "\t";
			//else cout << cur_str[j] << "\t";
		last_str = cur_str;
		cout << endl;
	} 	
	cout << endl << "Значение коээфициента: " << cur_str[k-1] << endl;	
	cout.rdbuf(back_out);
	cin.rdbuf(back_in);
	input.close();
	output.close();
	system("pause");
	return 0;
}
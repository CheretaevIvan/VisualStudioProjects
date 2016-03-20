#include <stdio.h>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int main(int argc, char* argv[]){
	streambuf *back_out = cout.rdbuf();
	streambuf *back_in = cin.rdbuf();
	ofstream output;
	ifstream input;
	// если есть агрументы командной строки, то перенаправляем в файл
	if (argc >= 3)
	{
		input.open(argv[1]);
		output.open(argv[2]);

		cin.rdbuf(input.rdbuf());
		cout.rdbuf(output.rdbuf());
	}

	// то что надо сделать
	queue<long long> myQuee;

	int x = 0, y = 0;
	scanf("%d / %d", &x, &y);
	int N = 0;
	cin >> N;
	long long cur_time = 0;
	cin >> cur_time;	
	if (x == 1){
		long long next_time = cur_time + (long long)y * 1000000000;
		cout << cur_time << ' ';
		for (size_t i = 1; i < N; i++)
		{
			cin >> cur_time;
			if (cur_time < next_time){
				cout << next_time << ' ';
				next_time += (long long)y * 1000000000;
			}
			else {
				cout << cur_time << ' ';
				next_time = cur_time + (long long)y * 1000000000;
			}
		}
	}	
	else {
		long long next_time = cur_time + 1000000000;
		cout << cur_time << ' ';
		myQuee.push(cur_time + 1000000000);

		for (size_t i = 1; i < N; i++)
		{
			cin >> cur_time;
			if (cur_time < next_time){
				myQuee.push(cur_time + 1000000000);
				if (myQuee.size() > x){
					cout << myQuee.front() << ' ';
					myQuee.pop();
				}
				else
					cout << cur_time << ' ';
			}
			else{
				while (myQuee.size()>0)
					myQuee.pop();
				myQuee.push(cur_time + 1000000000);
				cout << cur_time << ' ';
			}
		}
	}
	cin.rdbuf(back_in); // восстанавливаем исходные потоки
	cout.rdbuf(back_out);
}
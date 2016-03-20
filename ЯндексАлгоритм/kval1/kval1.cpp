
#include <iostream>
#include <fstream>

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

	cin.rdbuf(back_in); // восстанавливаем исходные потоки
	cout.rdbuf(back_out);
}
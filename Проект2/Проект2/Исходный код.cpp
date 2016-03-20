#include <cstring>
#include <ctype.h>
#include <locale>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

bool isGoodPassword(char* password){
	if (strlen(password) < 8)
		return false;
	bool hasUpperCase = false, hasLowerCase = false, hasDigit = false;
	for (size_t i = 0; i < strlen(password); i++){
		if (password[i] == toupper(password[i]))
			hasUpperCase = true;
		if (password[i] == tolower(password[i]))
			hasLowerCase = true;
		if (isdigit(password[i]))
			hasDigit = true;
	}
	return hasLowerCase && hasUpperCase && hasDigit;
}

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

	char* pass = (char*)malloc(100 * sizeof(char));
	cin >> pass;
	if (isGoodPassword(pass))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;

	cin.rdbuf(back_in); // восстанавливаем исходные потоки
	cout.rdbuf(back_out);
}
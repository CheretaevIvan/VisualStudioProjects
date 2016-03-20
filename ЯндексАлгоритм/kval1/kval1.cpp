
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
	streambuf *back_out = cout.rdbuf();
	streambuf *back_in = cin.rdbuf();
	ofstream output;
	ifstream input;
	// ���� ���� ��������� ��������� ������, �� �������������� � ����
	if (argc >= 3)
	{
		input.open(argv[1]);
		output.open(argv[2]);

		cin.rdbuf(input.rdbuf());
		cout.rdbuf(output.rdbuf());
	}

	// �� ��� ���� �������

	cin.rdbuf(back_in); // ��������������� �������� ������
	cout.rdbuf(back_out);
}
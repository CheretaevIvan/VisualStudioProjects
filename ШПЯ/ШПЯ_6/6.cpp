#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
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

	int N; 
	cin >> N; // ��������� ����������� �������
	int** matrix = new int*[N];
	for (int i = 0; i < N; i++)
		matrix[i] = new int[N];
	int N2 = N*N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> matrix[i][j]; //��������� �������
	
	int* diag_matrix = new int[N*N];
	for (int i = 0; i < N2; i++)
		diag_matrix[i] = 0;
	int count = 0;
	for (int i = 0; i < N-1; i++)
		for (int j = 0; j <= i; j++)
		{			
			diag_matrix[N2 - count - 1] = matrix[N + j - i - 1][N - 1 - j];
			diag_matrix[count++] = matrix[i - j][j];
		}
	for (int i = 0; i < N; i++)
		diag_matrix[count++] = matrix[N - i - 1][i];
	for (int i = 0; i < N*N; i++)
		cout << diag_matrix[i] << ' ';
	for (int i = 1; i < N; i++)
		delete matrix[i];
	delete[] matrix;

	cin.rdbuf(back_in); // ��������������� �������� ������
	cout.rdbuf(back_out); 
}
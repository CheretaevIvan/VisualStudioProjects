#include <iostream>

using namespace std;

int OK(int **A, int m, int n){
	if (m <= 0) return 0;
	if (n <= 0) return 0;
	for (int i = 0; i < n; i++)
		if (A[0][i])
			return 0;
	for (int i = 1; i < m; i++)
		if (A[i][n-1])
			return 0;
	for (int i = 0; i < n -1; i++)
		if (A[m-1][i])
			return 0;
	for (int i = 1; i < m - 1; i++)
		if (A[i][0])
			return 0;
	return 1;
}


void test(){
	int **array = (int**)malloc(4 * sizeof(int*));
	for (int i = 0; i < 4; i++)
		array[i] = (int*)malloc(4 * sizeof(int));
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			array[i][j] = 0;
	int result = OK(array, 4, 4);
	if (result != 1) cout << "Неправильно определено, окаймлена ли матрица" << endl;
}

int main(){
	test();
	system("pause");
	return 0;
}
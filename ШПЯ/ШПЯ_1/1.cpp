#include <iostream>

using namespace std;

int main()
{
	int min_lamp = INT_MAX;
	/*int* matrix = new int[25];
	for (int i = 0; i < 5; i++)
	matrix[i] = 0;*/
	int** matrix = new int*[5];
	for (int i = 0; i < 5; i++)
		matrix[i] = new int[5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			matrix[i][j] = 0;
	int max_soch_lamp = pow(2, 26);
	int count = 0;
	//int max_soch_lamp = 30;
	for (int i = 0; i < max_soch_lamp; i++)
	{
		bool istrue = true;
		for (int j = 0; j < 25; j++)
		{
			int power = pow(2, j);
			matrix[j / 5][j % 5] = (i & power) / power;
			//matrix[j]= (i & power) / power;
		}
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				count = matrix[j][k] + matrix[j][k + 1] + matrix[j][k + 2] + matrix[j + 1][k] + matrix[j + 1][k + 1] + matrix[j + 1][k + 2] + matrix[j + 2][k] + matrix[j + 2][k + 1] + matrix[j + 2][k + 2];
				if(!(count == 4 && istrue))
					istrue = false;
			}
		}
	    if (istrue)
		{
			int sum = 0;
			for (int j = 0; j < 5; j++)
				for (int k = 0; k < 5; k++)
					sum += matrix[j][k];
			if (sum < min_lamp)
			{
				min_lamp = sum;
				for (int j = 0; j < 5; j++)
				{
					for (int k = 0; k < 5; k++)
						cout << matrix[j][k] << ' ';
					cout << endl;
				}
				cout << endl;
			}
			
			
		}

		for (int j = 0; j < 25; j++)
			matrix[j / 5][j / 5 + j % 5] = 0;
		if (i%10000000==0)
			cout << i << endl;
	}
	cin >> max_soch_lamp;
}
#include <iostream>
using namespace std;

int amountBit(int number){
	int result = 0;
	while (number){
		if (number % 2 == 1)
			result++;
		number = number >> 1;
	}
	return result;
}

int main(){
	int amount = 0;
	for (size_t i = 0; i < 256; i++)
	{
		if (amountBit(i) == 4)
			amount++;
	}
	cout << amount << endl;
	system("pause");
	return 0;
}
#include <iostream>

using namespace std;

bool isgroupped_by_7(int number)
{
	bool has7 = false;
	int digit[6] = { 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i < 6; i++)
	{
		digit[i] = (number % (int)pow(10, i + 1)) / (int)pow(10, i);
	}
	for (int i = 0; i < 6; i++)
	{
		if (digit[i] == 7)
		{
			has7 = true;
			if (i < 5 && i>0)
				if (!(digit[i - 1] == 7 || digit[i + 1] == 7))  return false;
			if (i == 5) if (digit[4] != 7)  return false;
			if (i == 0) if (digit[1] != 7)  return false;
		}
	}
	if (!has7) return false;
	return true;
}

int main()
{
	int digit[6] = { 0, 0, 0, 0, 0, 0 };
	int count = 0;
	int nums[] = { 700777, 777777, 707070, 712347, 778777, 777737, 778787, 777772, 465215, 0, 172770 };
	for (int number = 100000; number < 1000000; number++)
	{ 	
		//int number = nums[number1];
		if (isgroupped_by_7(number))
		{
			++count;
			//cout << number << endl;
		}
	}
	cout << count;
	int a;
	cin >> a;
}
#include <iostream>

using namespace std;

int main()
{
	int* children = new int[50];
	for (int i = 0; i < 50; i++)
		children[i] = 0;
	int* mens = new int[50];
	for (int i = 0; i < 50; i++)
		mens[i] = 0;
	children[0] = 1;
	children[1] = 0;
	children[2] = 1;
	mens[0] = 0;
	mens[1] = 1;
	mens[2] = 1;
	for (int i = 3; i < 50; i++)
	{
		children[i] = mens[i - 1];
		mens[i] = children[i - 1] + mens[i - 1] - children[i - 3];
	}
	for (int i = 0; i < 50; i++)
		cout << children[i] << ' ' << mens[i] << endl;
	int a;
	cout << endl << children[49] + mens[49];
	cin >> a;
}
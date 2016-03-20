#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, S = 0, d = 100, a = 16;
	for (i = 0; i < 10; i++)
		S += i;
	S <<= 3;
	printf("End of 1st loop\n");

	do {
		d -= a;
		a >>= 1;
	} while (a != 1);
	printf("End of 2nd loop\n");

	printf("Result: %d\n", S*d);
	system("pause");
}
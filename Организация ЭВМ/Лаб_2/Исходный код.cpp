#include <math.h>
#include <stdio.h>
#include <Windows.h>

double f(double x){
	return x*x*x + 2.1*x*x + 3.1*x + 2.2;
}

int main(){
	double x1 = -3.4, x2 = 1.7, x3, x4, x5, x6;
	while (x2 - x1 > 1e-8){
		x3 = x1 + x2;
		x4 = x3 / 2;
		x5 = f(x2);
		x6 = f(x4)*x5;
		if (x6 > 0)
			x2 = x4;
		else
			x1 = x4;
	}
	double x7 = (x1 + x2)/2;
	printf("The Real root of f(x)=0 is %lf\n", x7);
	system("pause");
	return 0;
}
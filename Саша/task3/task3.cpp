#include <iostream>

using namespace std;

float Myfunc(float x){
	return x;
}

float root(float(*f)(float ), float a, float b, float eps){
	float avr = (a + b) / 2;
	if (a - b < eps)
		return avr;
	if (f(a)*f(avr) < 0)
		return root(f, a, avr, eps);
	else
		return root(f, avr, b, eps);
}


void test(){
	float rootF = root(Myfunc, -2, 2, 0.1);
	if (!(rootF<0.1 && rootF>-0.1)) cout << "Неправильно определен корень функции" << endl;
}

int main(){
	test();
	system("pause");
	return 0;
}
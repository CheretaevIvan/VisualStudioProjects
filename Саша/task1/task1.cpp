#include <iostream>

using namespace std;

void find(float x[], float y[], int N, int *Cmin, int *Cmax){
	if (N <= 0) return;
	float max = y[0], min = y[0];
	*Cmax = 0;
	*Cmin = 0;
	for (int i = 1; i < N - 1; i++){
		if (y[i]>y[i - 1] && y[i] > y[i + 1])
			if (y[i] > max){
			max = y[i];
			*Cmax = 1;
			}
			else {
				if (y[i] == max)
					(*Cmax)++;
			}
		if (y[i] < y[i - 1] && y[i] < y[i + 1])
			if (y[i] < min){
				min = y[i];
				*Cmin = 1;
			}
			else if (y[i] == min)
				(*Cmin)++;
		if (y[i] > max)
			max = y[i];
		if (y[i] < min)
			min = y[i];
	}
	if (N >= 2){
		if (y[N - 1] > y[N - 2] && y[N - 1] > max)
			*Cmax = 1;
		if (y[N - 1] < y[N - 2] && y[N - 1] < min)
			*Cmin = 1;
	}
	if (max == y[0] && *Cmax == 0)
		*Cmax = 1;
	if (min == y[0] && *Cmin == 0)
		*Cmin = 1;
}

void test(){
	float x[] = { 0, 1, 2, 3, 4 };
	float y[] = { 4, 3, 6, 6, 1 };
	int countMin = 0;
	int countMax = 0;
	find(x, y, 5, &countMin, &countMax);
	//cout << countMin << " " << countMax;
	if (countMin != 1) cout << "Ќеправильно вычислено уоличество точек строгого локального минимума";
	if (countMax != 0) cout << "Ќеправильно вычислено уоличество точек строгого локального максимума";
}

int main(){
	test();
	system("pause");
	return 0;
}
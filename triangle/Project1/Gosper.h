#include <cliext/vector>
#pragma once

//#include <cstdlib>
//using namespace std;

template<typename T> ref class Gosper
{
public:
	Gosper(T(*f)(T, T, T, T), T a, T b, T c)
	{
		A = a;
		B = b;
		C = c;
		M = gcnew  cliext::vector<T>();
		func = f;
	}
	

	int LengthCicle(const T a0){
		T a = a0;
		int n = 1, t = 1;
		M.insert(a0);
		while (true){
			a = func(a);
			for (int i = 0; i < t; i++){
				if (M[i] == a)
					return n - pow(2, i)*(1 + 2 * ((int)(n - pow(2, i) + 1)) / ((int)pow(2, i + 1))) + 1;
			}
			n++;
			k = v2(n);
			if (k == t)
				t++;
			M[k] = a;
		}
	}

private:
	cliext::vector<T> M;
	T A, B, C;
	T(*func)(const T, T, T, T);

	int v2(int n){
		int result = 0;
		while (n % 2 == 0){
			n /= 2;
			result++;
		}
		return result;
	}
};


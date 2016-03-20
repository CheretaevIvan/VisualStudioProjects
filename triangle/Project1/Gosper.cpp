#include "Gosper.h"


//template<typename T> Gosper::Gosper(T(*f)(T))
//{
//	M = new std::vector<T>();
//	func = f;
//}
//
//template<typename T> int Gosper::LengthCicle(const T a0){
//	T a = a0;
//	int n = 1, t = 1;
//	T.insert(a0);
//	while (true){
//		a = func(a);
//		for (int i = 0; i < t; i++){
//			if (M[i] == a)
//				return n - pow(2, i)*(1 + 2 * ((int)(n - pow(2, i) + 1)) / ((int)pow(2, i + 1))) + 1;
//		}
//		n++;
//		k = v2(n);
//		if (k == t)
//			t++;
//		T[k] = a;
//	}	
//}
//
//template<typename T> int Gosper::v2(int n){
//	int result = 0;
//	while (n % 2 == 0){
//		n /= 2;
//		result++;
//	}
//	return result;
//}

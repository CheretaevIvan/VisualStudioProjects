//#include <stdio.h>
//#include <iostream>
//
//void swap(int &a, int &b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//int main(){
//	/*int x[] = { 10, 1, 5 };
//	int *px = &x[0];
//	int *px2 = &x[2];
//	int a = 6, b = 8;
//	swap(a, b);*/
//	//int  a = px2 - px;
//	//printf("%d %d", a, b);
//	char buffer[10];
//	system("pause");
//	return 0;
//}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <deque>
#include <complex>

#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define PB push_back
#define MP make_pair

#define DEBUG(x) cout << #x << " = "; cout << x << endl;
#define PR(a,n) cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl;
#define PR0(a,n) cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl;
using namespace std;

//Buffer reading
int INP, AM;
#define BUFSIZE (1<<12)
char BUF[BUFSIZE + 1], *inp = BUF;
#define GETCHAR(INP) { \
    if(!*inp) { \
        if (feof(stdin)) memset(BUF, 0, sizeof BUF); else fread(BUF,1,BUFSIZE,stdin); \
        inp=BUF; \
	    } \
    INP=*inp++; \
}
#define DIG(a) (((a)>='0')&&((a)<='9'))
#define GN(j) { \
    AM=0;\
    GETCHAR(INP); while(!DIG(INP) && INP!='-') GETCHAR(INP);\
    if (INP=='-') {AM=1;GETCHAR(INP);} \
    j=INP-'0'; GETCHAR(INP); \
	    while(DIG(INP)){j=10*j+(INP-'0');GETCHAR(INP);} \
    if (AM) j=-j;\
}
//End of buffer reading

const long double PI = acos((long double)-1.0);
const int MN = 10111;
const int oo = 1000111;

int n, st, ts;
int d[MN], c[MN];
int kq;

int check(int tt, int v) {
	int s = v, l = 1, r = n;
	while (l < r) {
		if (tt == 1) {
			int rr = r;
			while (l < r && s - d[rr] + d[r] < c[r]) --r;
			s = s - d[rr] + d[l];

			if (s < 0) return 2;
			if (r == rr) return 1;
		}
		else {
			int ll = l;
			while (l < r && s - d[l] + d[ll] < c[l]) ++l;
			s = s - d[r] + d[ll];
			if (s < 0) return 2;
			if (l == ll) return 1;
		}
		tt = 1 - tt;
	}
	return 0;
}

void solve() {
	int l = 1, r = c[n], mid;
	while (l < r) {
		mid = (l + r) >> 1;
		int cc = check(1, mid);
		if (cc == 0) r = mid;
		else if (cc == 1) r = mid - 1;
		else l = mid + 1;
	}
	if (check(1, l) == 0) kq = min(kq, l);

	l = 1, r = c[1];
	while (l < r) {
		mid = (l + r) >> 1;
		int cc = check(0, mid);
		if (cc == 0) r = mid;
		else if (cc == 1) r = mid - 1;
		else l = mid + 1;
	}
	if (check(0, l) == 0) kq = min(kq, l);
}

int main() {
	while (scanf("%d", &n) == 1) {
		FOR(i, 1, n) scanf("%d%d", &d[i], &c[i]);
		kq = oo;
		solve();
		if (kq == oo) puts("No solution");
		else printf("%d\n", kq);
	}
	return 0;
}
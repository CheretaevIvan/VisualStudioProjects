#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

struct Point{
	int x, y;
};

int cmpPoint(const void * p1, const void * p2){
	struct Point *point1 = (struct Point*)p1;
	struct Point *point2 = (struct Point*)p2;
	return (point1->x)*(point1->x) + (point1->y)*(point1->y) - (point2->x)*(point2->x) - (point2->y)*(point2->y);
}

int main(int argc, char* argv[]){
	streambuf *back_out = cout.rdbuf();
	streambuf *back_in = cin.rdbuf();
	ofstream output;
	ifstream input;
	// если есть агрументы командной строки, то перенаправляем в файл
	if (argc >= 3)
	{
		input.open(argv[1]);
		output.open(argv[2]);

		cin.rdbuf(input.rdbuf());
		cout.rdbuf(output.rdbuf());
	}

	int n = 0;
	cin >> n;
	struct Point *points = static_cast<struct Point*>(calloc(n, sizeof(struct Point)));
	for (size_t i = 0; i < n; i++){
		cin >> points[i].x >> points[i].y;
	}
	qsort(points, n, sizeof(struct Point), cmpPoint);
	for (size_t i = 0; i < n; i++){
		cout << points[i].x << ' ' << points[i].y << endl;
	}

	cin.rdbuf(back_in); // восстанавливаем исходные потоки
	cout.rdbuf(back_out);
}
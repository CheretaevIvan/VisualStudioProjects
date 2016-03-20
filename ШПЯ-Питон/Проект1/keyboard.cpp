#include <iostream>
#include <stdlib.h>
#include <map>
#include <fstream>
#include <string.h>
#include <locale.h>

using namespace std;

double fine(char *file, char *fbut, char *fpenalties)
{
	map<char, pair<pair<int, int>, pair<int, int>>>buttons = map<char, pair<pair<int, int>, pair<int, int>>>();
	map<pair<int, int>, pair<double, double>>penalties_for_fingers = map<pair<int, int>, pair<double, double>>();
	map<pair<char, char>, double>digram = map<pair<char, char>, double>();
	map<pair<char, char>, double>penalties_for_digrams = map<pair<char, char>, double>();
	map<pair<char, char>, double>::iterator cur3;
	ifstream in, in_but, in_pen;
	char c1 = '\0';
	char c2 = '\0';
	int count = 0;

	char c = '\0';
	int finger, hand, line, column;
	double pressing, movement;
	in_but.open(fbut);
	while (!in_but.eof()){
		in_but >> c >> hand >> finger >> line >> column;
		buttons[c] = pair<pair<int, int>, pair<int, int>>(pair<int, int>(hand, finger), pair<int, int>(line, column));
		buttons[toupper(c)] = pair<pair<int, int>, pair<int, int>>(pair<int, int>(hand, finger), pair<int, int>(line, column));
	}
	buttons['\n'] = pair<pair<int, int>, pair<int, int>>(pair<int, int>(2, 5), pair<int, int>(2, 7));
	buttons[' '] = pair<pair<int, int>, pair<int, int>>(pair<int, int>(1, 1), pair<int, int>(0, 1));
	in_but.close();
	in_pen.open(fpenalties);
	while (!in_pen.eof()){
		in_pen >> hand >> finger >> pressing >> movement;
		penalties_for_fingers[pair<int, int>(hand, finger)] = pair<double, double>(pressing, movement);
	}
	in_pen.close();

	in.open(file);
	in.get(c1);
	while (!in.eof()){
		in.get(c2);
		digram[pair<char, char>(c1, c2)]++;
		c1 = c2;
		count++;
	}
	for (cur3 = digram.begin(); cur3 != digram.end(); cur3++){
		if (buttons[(*cur3).first.first] != pair<pair<int, int>, pair<int, int>>(pair<int, int>(0, 0), pair<int, int>(0, 0)) &&
			buttons[(*cur3).first.second] != pair<pair<int, int>, pair<int, int>>(pair<int, int>(0, 0), pair<int, int>(0, 0))){
			penalties_for_digrams[(*cur3).first] = penalties_for_fingers[buttons[(*cur3).first.first].first].first +
				penalties_for_fingers[buttons[(*cur3).first.second].first].first +
				penalties_for_fingers[buttons[(*cur3).first.second].first].second*sqrt(
				pow(abs(buttons[(*cur3).first.second].second.first - buttons[(*cur3).first.first].second.first), 2) +
				pow(abs(buttons[(*cur3).first.second].second.second - buttons[(*cur3).first.first].second.second), 2)
				);
			if (buttons[(*cur3).first.first].first.first != buttons[(*cur3).first.second].first.first) penalties_for_digrams[(*cur3).first] -= 0.6*penalties_for_fingers[buttons[(*cur3).first.second].first].second*sqrt(
				pow(abs(buttons[(*cur3).first.second].second.first - buttons[(*cur3).first.first].second.first), 2) +
				pow(abs(buttons[(*cur3).first.second].second.second - buttons[(*cur3).first.first].second.second), 2)
				);
			if ((*cur3).first.first == (*cur3).first.second) penalties_for_digrams[(*cur3).first] += 0.2*penalties_for_fingers[buttons[(*cur3).first.second].first].first;
			if ((*cur3).first.first != (*cur3).first.second &&
				buttons[(*cur3).first.first].first == buttons[(*cur3).first.second].first)
				penalties_for_digrams[(*cur3).first] += 0.3*penalties_for_fingers[buttons[(*cur3).first.first].first].first +
				0.3*penalties_for_fingers[buttons[(*cur3).first.second].first].first +
				0.3*penalties_for_fingers[buttons[(*cur3).first.second].first].second*sqrt(
				pow(abs(buttons[(*cur3).first.second].second.first - buttons[(*cur3).first.first].second.first), 2) +
				pow(abs(buttons[(*cur3).first.second].second.second - buttons[(*cur3).first.first].second.second), 2)
				);
			if (buttons[(*cur3).first.second].second.first == 1)
				penalties_for_digrams[(*cur3).first] += 0.25*penalties_for_fingers[buttons[(*cur3).first.first].first].first +
				0.25*penalties_for_fingers[buttons[(*cur3).first.second].first].first +
				0.25*penalties_for_fingers[buttons[(*cur3).first.second].first].second*sqrt(
				pow(abs(buttons[(*cur3).first.second].second.first - buttons[(*cur3).first.first].second.first), 2) +
				pow(abs(buttons[(*cur3).first.second].second.second - buttons[(*cur3).first.first].second.second), 2)
				);
		}
	}
	double sum = 0;
	for (cur3 = digram.begin(); cur3 != digram.end(); cur3++)
		sum += (double)(*cur3).second / count * 100 * penalties_for_digrams[(*cur3).first];
	in.close();
	return sum;
}

int main(){
	setlocale(LC_ALL, "ru");
	char* fileeng = "book2.txt", *filerus = "book1.txt", *fbutrus = "buttons Ч русска€ раскладка.txt", *fpenalties = "penalties.txt", *fbutdvor = "buttons Ч ƒворак.txt", *fbutqwer = "buttons - QWERTY.txt", *fbutcol = "buttons Ч Colemak.txt";
	cout << "–усска€ раскладка: " <<  fine(filerus, fbutrus, fpenalties) << " баллов" << endl;
	cout << "QWERTY: " << fine(fileeng, fbutqwer, fpenalties) << " баллов" << endl;
	cout << "Dvorak: " << fine(fileeng, fbutdvor, fpenalties) << " баллов" << endl;
	cout << "Colemak: " << fine(fileeng, fbutcol, fpenalties) << " баллов" << endl;
	system("pause");
	return 0;
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <string>
#include "node.h"
using namespace std;


int alphabet()
{
	char* s = new char[81]{' '};
	char* new_s = new char[1]{'\0'};
	cin >> s; 
	int i = 0;
	while (isalpha(tolower(s[i])))
	{
		//new_s = strcpy(new_s, (char*)s[i]);
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	PNode head = CreateNode(new_s);
	while (!cin.eof()){			
		cin >> s;
		i = 0;
		while (isalpha(tolower(s[i])))		{
			new_s[i] = s[i];
			i++;
		}
		new_s[i] = '\0';
		PNode pn = Find(head, new_s);
		if (pn == NULL){
			PNode node_after = FindPlace(head, new_s);
			AddBefore(head, node_after, CreateNode(new_s));
		}
		else
			pn->count++;
	};
	PNode q = head;
	while (q){		
		cout << q->word << ": " << q->count << endl;		
		q = q->next;
	}
	return 0;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "ru");
	streambuf *back_out = cout.rdbuf();
	streambuf *back_in = cin.rdbuf();
	ofstream output;
	ifstream input;
	if (argc >= 3)
	{
		input.open(argv[1]);
		output.open(argv[2]);
		cin.rdbuf(input.rdbuf());
		cout.rdbuf(output.rdbuf());
	}
	double t0 = clock();
	alphabet();
	double t1 = clock();
	
	cout << endl << "Время выполнения: " << (double)(t1 - t0) << "мс" << endl;
	cout << endl;
	cout.rdbuf(back_out);
	cin.rdbuf(back_in);
	input.close();
	output.close();
	system("pause");
	return 0;
}
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool matrix[16][16] = {
//  1, 2, 3, 4, 5, 6 ,7, 8, 9,10,11,12,13,14,15,16
	0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//1
	1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,//2
	0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,//3
	0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,//4
	1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,//5
	0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0,//6
	0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0,//7
	0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0,//8
	0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0,//9
	0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0,//10
	0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0,//11
	0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1,//12
	0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0,//13
	0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0,//14
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1,//15
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0//16
};
char* dictionary = new char[16];

bool path(char* word, int start, int length)
{
	bool isvisited[16] = { false };
	bool isvisited_cur[16] = { false };
	int count = 0;
	int cur_letter = start;
	int last_letter[16] = {0};
	for (int i = 0; i < 16; i++)
		last_letter[i] = -1;
	while (count >= 0 && count < length-1)
	{
		int i;
		for (i = 0; i < 16; i++)
			if (matrix[cur_letter][i] && word[count + 1] == dictionary[i] && !isvisited[cur_letter] && !isvisited_cur[i])
			{
				isvisited[cur_letter] = true;
				isvisited_cur[i] = true;
				last_letter[count] = cur_letter;
				cur_letter = i;
				count++;
				break;
			}
		if (i == 16)
		{			
			count--;
			for (int j = 0; j < 16; j++)
				ispassed[cur_letter][j] = false;
			if (count < 0) return false;
			cur_letter = last_letter[count];	
			isvisited[cur_letter] = false;
		}
	}	
	return true;
}

bool has_word(char* word)
{
	int length = strlen(word);
	for (int i = 0; i < 16; i++)
		if (dictionary[i] == word[0])
			if (path(word, i, length)) return true;
	return false;
}

int main(int argc, char* argv[])
{
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
	for (int i = 0; i < 16; i++)
		cin >> dictionary[i];
	int N;
	cin >> N;	
	cin.getline(new char[1], 1);
	char** word = new char*[N];
	for (int i = 0; i < N;i++)
		word[i] = new char[17]{' '};
	for (int i = 0; i < N; i++)	{
		cin.getline(word[i], 17);		
	}
	for (int i = 0; i < N; i++){
		if (has_word(word[i])) cout << word[i] << ": YES" << endl;
		else cout << word[i] << ": NO" << endl;
	}
	for (int i = 0; i < N; i++)
		delete[] word[i];
	delete[] word;
	cout.rdbuf(back_out);
	cin.rdbuf(back_in);
	input.close();
	output.close();
}
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
	streambuf *back_out = cout.rdbuf();
	streambuf *back_in = cin.rdbuf();
	ofstream output;
	ifstream input;

	if (argc >= 2)
		input.open(argv[1]);
	else
		input.open("init.txt");
	string hostname;
	cin.rdbuf(input.rdbuf());
	getline(cin, hostname);
	output.open(hostname + ".txt");
	cout.rdbuf(output.rdbuf());

	// то что надо сделать
	cout << "enable" << endl;
	cout << "conf t" << endl;
	cout << "hostname " << hostname << endl;

	cout << "no ip domain-lookup" << endl;
	cout << "enable secret class" << endl;
	cout << "service password-encryption" << endl;

	cout << "banner motd #Laboratory work of \nstudent Cheretaev Ivan group RI320207 \nUnauthorized access to the device " << hostname << " is prohibited#" << endl;

	cout << "line con 0" << endl;
	cout << "password cisco" << endl;
	cout << "login" << endl;
	cout << "logging synchronous" << endl;

	cout << "line vty 0 15" << endl;
	cout << "password cisco" << endl;
	cout << "login" << endl;
	cout << "logging synchronous" << endl;

	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;

	string interFace, ip, netmask;
	getline(cin, interFace);
	while (!interFace.empty())
	{
		getline(cin, ip);
		getline(cin, netmask);
		cout << "interface " << interFace << endl;
		cout << "ip address " << ip << " " << netmask << endl;
		getline(cin, interFace);
	}
	cout << "end" << endl;

	cin.rdbuf(back_in); // восстанавливаем исходные потоки
	cout.rdbuf(back_out);

	input.close();
	output.close();
}
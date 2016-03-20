#include "IPv6.h"
#include "IPv4.h"
#include <iostream>
#include <fstream>
//#include <clocale>
#include <bitset>
#include <cmath>
#include <codecvt>
//#include <afxvisualmanageroffice2007.h>
using namespace std;
wstring ToWString(const string &s){
	return wstring(s.begin(), s.end());
}

void wcontrol_work(char *fout, char *family, char *name, int group, int N, int y0, int y1, int y2, int z1, int z2, int z3){
	wstring num2str[] = { L"one", L"two", L"three", L"four", L"five" };
	int bits;
	wofstream out;

	const locale empty_locale = locale::empty();
	typedef codecvt_byname<wchar_t, char, mbstate_t> converter_type2;
	typedef codecvt_utf8<wchar_t> converter_type;
	const converter_type* converter = new converter_type;
	const converter_type2* converter2 = new converter_type2("ru_RU.cp1251");
	const locale utf8_locale = locale(empty_locale, converter2);

	out.open(fout, ios::out);

	out.imbue(utf8_locale);
	out << "\\newcommand{\\theFamily}{" << family << "}" << endl;
	out << "\\newcommand{\\theName}{" << name << "}" << endl;
	out << "\\newcommand{\\theGroup}{" << group << "}" << endl;
	out << "\\newcommand{\\theN}{" << N << "}" << endl;
	string name5(name);
	int length = name5.length() > 5 ? 5 : name5.length();
	name5 = name5.substr(0, length);
	IPv6 ipv6(group, name5);
	out << "\\newcommand{\\thenetIPvsix}{" << ToWString(ipv6.ToString()) << "}" << endl;
	out << "\\newcommand{\\prefixNstartOneTwo}{" << ToWString(ipv6.firstsubnet(y0).ToString()) << "}" << endl;
	out << "\\newcommand{\\prefixNfinishOneTwo}{" << ToWString(ipv6.lastsubnet(y0).ToString()) << "}" << endl;
	out << "\\newcommand{\\theYzero}{" << y0 << "}" << endl;

	IPv4 ipv4(N);
	out << "\\newcommand{\\theXzero}{" << int(ipv4.octet[0]) << "}" << endl;
	out << "\\newcommand{\\theXone}{" << int(ipv4.octet[1]) << "}" << endl;

	out << "\\newcommand{\\theYone}{" << y1 << "}" << endl;

	out << "\\newcommand{\\theXzeroBinary}{" << bitset<8>(int(ipv4.octet[0])) << "}" << endl;
	out << "\\newcommand{\\theXoneBinary}{" << bitset<8>(int(ipv4.octet[1])) << "}" << endl;

	out << "%2.1.1" << endl;

	out << "\\newcommand{\\theamountbitstwooneone}{";

	bits = ceil(log2(y1));
	if (bits > 4) {
		out << 4 << " бит из " << ipv4.prefix / 8 + 2 << "-го октета и ";
		if (bits > 12) out << 8 << " бит из " << ipv4.prefix / 8 + 1 << "-го октета, а также " << bits - 12;
		else out << bits - 4;
	}
	else out << bits;
	out << "}" << endl;

	out << "\\newcommand{\\theoctettwooneone}{";
	if (bits > 4) {
		if (bits > 12) out << ipv4.prefix / 8;
		else out << ipv4.prefix / 8 + 1;
	}
	else out << ipv4.prefix / 8 + 2;
	out << "}" << endl;

	out << "\\newcommand{\\theamountnetstwooneone}{" << pow(2, bits) << "}" << endl;
	IPv4** subnets211 = ipv4.getsubnets(y1);
	out << "\\newcommand{\\theamounthoststwooneone}{" << pow(2, 32 - subnets211[0]->getprefix()) - 2 << "}" << endl;

	IPv4 mask = subnets211[0]->getmask();
	for (size_t i = 0; i < 4; i++){
		out << "\\newcommand{\\themask" << num2str[i] << "twooneone}{" << int(mask.octet[i]) << "}" << endl;
		out << "\\newcommand{\\themask" << num2str[i] << "binarytwooneone}{" << bitset<8>(int(mask.octet[i])) << "}" << endl;
	}

	for (size_t i = 0; i < 5; i++){
		out << "\\newcommand{\\thenetone" << num2str[i] << "}{" << ToWString(subnets211[i]->ToString()) << "}" << endl;
		out << "\\newcommand{\\thefirsthostone" << num2str[i] << "}{" << ToWString(subnets211[i]->getfirsthost().ToString()) << "}" << endl;
		out << "\\newcommand{\\thelasthostone" << num2str[i] << "}{" << ToWString(subnets211[i]->getlasthost().ToString()) << "}" << endl;
		out << "\\newcommand{\\thebroadcastone" << num2str[i] << "}{" << ToWString(subnets211[i]->getbroadcast().ToString()) << "}" << endl;
	}

	out << "%2.1.2" << endl;

	out << "\\newcommand{\\theYtwo}{" << y2 << "}" << endl;

	bits = ceil(log2(y2));
	out << "\\newcommand{\\theamountbitssummarytwoonetwo}{" << bits << "}" << endl;;
	out << "\\newcommand{\\theamountbitstwoonetwo}{";

	if (bits > 4) {
		out << 4 << " бит из " << ipv4.prefix / 8 + 2 << "-го октета и ";
		if (bits > 12) out << 8 << " бит из " << ipv4.prefix / 8 + 1 << "-го октета, а также " << bits - 12;
		else out << bits - 4;
	}
	else out << bits;
	out << "}" << endl;

	out << "\\newcommand{\\theoctettwoonetwo}{";
	if (bits > 4) {
		if (bits > 12) out << ipv4.prefix / 8;
		else out << ipv4.prefix / 8 + 1;
	}
	else out << ipv4.prefix / 8 + 2;

	out << "}" << endl;

	IPv4** subnets212 = ipv4.getsubnets(y2);
	out << "\\newcommand{\\theamountnetstwoonetwo}{" << pow(2, bits) << "}" << endl;
	out << "\\newcommand{\\theamountbitshoststwoonetwo}{" << 32 - subnets212[0]->getprefix() << "}" << endl;
	out << "\\newcommand{\\theamounthoststwoonetwo}{" << pow(2, 32 - subnets212[0]->getprefix())-2 << "}" << endl;

	mask = subnets212[0]->getmask();
	for (size_t i = 0; i < 4; i++){
		out << "\\newcommand{\\themask" << num2str[i] << "twoonetwo}{" << int(mask.octet[i]) << "}" << endl;
		out << "\\newcommand{\\themask" << num2str[i] << "binarytwoonetwo}{" << bitset<8>(int(mask.octet[i])) << "}" << endl;
	}

	{
		out << "\\newcommand{\\thenetfirst" << num2str[0] << "}{" << ToWString(subnets212[0]->ToString()) << "}" << endl;
		out << "\\newcommand{\\thefirsthostfirst" << num2str[0] << "}{" << ToWString(subnets212[0]->getfirsthost().ToString()) << "}" << endl;
		out << "\\newcommand{\\thelasthostfirst" << num2str[0] << "}{" << ToWString(subnets212[0]->getlasthost().ToString()) << "}" << endl;
		out << "\\newcommand{\\thebroadcastfirst" << num2str[0] << "}{" << ToWString(subnets212[0]->getbroadcast().ToString()) << "}" << endl;

		out << "\\newcommand{\\thenetend" << num2str[0] << "}{" << ToWString(subnets212[y2 - 1]->ToString()) << "}" << endl;
		out << "\\newcommand{\\thefirsthostend" << num2str[0] << "}{" << ToWString(subnets212[y2 - 1]->getfirsthost().ToString()) << "}" << endl;
		out << "\\newcommand{\\thelasthostend" << num2str[0] << "}{" << ToWString(subnets212[y2 - 1]->getlasthost().ToString()) << "}" << endl;
		out << "\\newcommand{\\thebroadcastend" << num2str[0] << "}{" << ToWString(subnets212[y2 - 1]->getbroadcast().ToString()) << "}" << endl;
	}

	out << "%2.2.1" << endl;
	out << "\\newcommand{\\theZone}{" << z1 << "}" << endl;

	IPv4** subnets221 = ipv4.getsubnetsbyhosts(z1);
	out << "\\newcommand{\\theamountbitstwotwoone}{" << subnets221[0]->getprefix()-ipv4.getprefix() << "}" << endl;
	out << "\\newcommand{\\theamountnetstwotwoone}{" << pow(2, 32-ipv4.prefix-ceil(log2(z2))) << "}" << endl;
	out << "\\newcommand{\\theamountbitshoststwotwoone}{" << 32 - subnets221[0]->getprefix() << "}" << endl;
	out << "\\newcommand{\\theamounthoststwotwoone}{" << pow(2, 32 - subnets221[0]->getprefix())-2 << "}" << endl;
	
	mask = subnets221[0]->getmask();
	for (size_t i = 0; i < 4; i++){
		out << "\\newcommand{\\themask" << num2str[i] << "twotwoone}{" << int(mask.octet[i]) << "}" << endl;
		out << "\\newcommand{\\themask" << num2str[i] << "binarytwotwoone}{" << bitset<8>(int(mask.octet[i])) << "}" << endl;
	}

	int number_nets = pow(2, 32 - (ipv4.getprefix() + ceil(log2(z1))));
	for (size_t i = number_nets-5; i < number_nets; i++){
		out << "\\newcommand{\\thenettwo" << num2str[i - (number_nets - 5)] << "}{" << ToWString(subnets221[i]->ToString()) << "}" << endl;
		out << "\\newcommand{\\thefirsthosttwo" << num2str[i - (number_nets - 5)] << "}{" << ToWString(subnets221[i]->getfirsthost().ToString()) << "}" << endl;
		out << "\\newcommand{\\thelasthosttwo" << num2str[i - (number_nets - 5)] << "}{" << ToWString(subnets221[i]->getlasthost().ToString()) << "}" << endl;
		out << "\\newcommand{\\thebroadcasttwo" << num2str[i - (number_nets - 5)] << "}{" << ToWString(subnets221[i]->getbroadcast().ToString()) << "}" << endl;
	}

	out << "%2.2.2" << endl;

	out << "\\newcommand{\\theZtwo}{" << z2 << "}" << endl;
	IPv4** subnets222 = ipv4.getsubnetsbyhosts(z2 + 2);
	out << "\\newcommand{\\theamountbitshoststwotwotwo}{" << 32 - subnets222[0]->getprefix() << "}" << endl;
	out << "\\newcommand{\\theamounthoststwotwotwo}{" << pow(2, 32 - subnets222[0]->getprefix())-2 << "}" << endl;

	mask = subnets222[0]->getmask();
	for (size_t i = 0; i < 4; i++){
		out << "\\newcommand{\\themask" << num2str[i] << "twotwotwo}{" << int(mask.octet[i]) << "}" << endl;
		out << "\\newcommand{\\themask" << num2str[i] << "binarytwotwotwo}{" << bitset<8>(int(mask.octet[i])) << "}" << endl;
	}

	int number_nets2 = pow(2, 32 - (ipv4.getprefix() + ceil(log2(z2+2))));
	{
		out << "\\newcommand{\\thenetfirst" << num2str[1] << "}{" << ToWString(subnets222[0]->ToString()) << "}" << endl;
		out << "\\newcommand{\\thefirsthostfirst" << num2str[1] << "}{" << ToWString(subnets222[0]->getfirsthost().ToString()) << "}" << endl;
		out << "\\newcommand{\\thelasthostfirst" << num2str[1] << "}{" << ToWString(subnets222[0]->getlasthost().ToString()) << "}" << endl;
		out << "\\newcommand{\\thebroadcastfirst" << num2str[1] << "}{" << ToWString(subnets222[0]->getbroadcast().ToString()) << "}" << endl;

		out << "\\newcommand{\\thenetend" << num2str[1] << "}{" << ToWString(subnets222[number_nets2 - 1]->ToString()) << "}" << endl;
		out << "\\newcommand{\\thefirsthostend" << num2str[1] << "}{" << ToWString(subnets222[number_nets2 - 1]->getfirsthost().ToString()) << "}" << endl;
		out << "\\newcommand{\\thelasthostend" << num2str[1] << "}{" << ToWString(subnets222[number_nets2 - 1]->getlasthost().ToString()) << "}" << endl;
		out << "\\newcommand{\\thebroadcastend" << num2str[1] << "}{" << ToWString(subnets222[number_nets2 - 1]->getbroadcast().ToString()) << "}" << endl;
	}

	out << "%2.2.3" << endl;
	out << "\\newcommand{\\theZthree}{" << z3 << "}" << endl;
	IPv4** subnets223 = ipv4.getsubnetsbyhosts(z3+2);
	out << "\\newcommand{\\theamountbitshoststwotwothree}{" << 32 - subnets223[0]->getprefix() << "}" << endl;
	out << "\\newcommand{\\theamounthoststwotwothree}{" << pow(2, 32 - subnets223[0]->getprefix())-2 << "}" << endl;

	mask = subnets223[0]->getmask();
	for (size_t i = 0; i < 4; i++){
		out << "\\newcommand{\\themask" << num2str[i] << "twotwothree}{" << int(mask.octet[i]) << "}" << endl;
		out << "\\newcommand{\\themask" << num2str[i] << "binarytwotwothree}{" << bitset<8>(int(mask.octet[i])) << "}" << endl;
	}

	number_nets = pow(2, 32 - (ipv4.getprefix() + ceil(log2(z3+2))));
	for (size_t i = number_nets - 5; i < number_nets; i++){
		out << "\\newcommand{\\thenetthree" << num2str[i - (number_nets - 5)] << "}{" << ToWString(subnets223[i]->ToString()) << "}" << endl;
		out << "\\newcommand{\\thefirsthostthree" << num2str[i - (number_nets - 5)] << "}{" << ToWString(subnets223[i]->getfirsthost().ToString()) << "}" << endl;
		out << "\\newcommand{\\thelasthostthree" << num2str[i - (number_nets - 5)] << "}{" << ToWString(subnets223[i]->getlasthost().ToString()) << "}" << endl;
		out << "\\newcommand{\\thebroadcastthree" << num2str[i - (number_nets - 5)] << "}{" << ToWString(subnets223[i]->getbroadcast().ToString()) << "}" << endl;
	}
	out.close();
}

void control_work(char *fout, char *family, char *name, int group, int N, int y0, int y1, int y2, int z1, int z2, int z3){
	string num2str[] = { "one", "two", "three", "four", "five" };
	int bits;
	ofstream out;

	const locale empty_locale = locale::empty();
	typedef codecvt_byname<wchar_t, char, mbstate_t> converter_type2;
	typedef codecvt_utf8<wchar_t> converter_type;
	const converter_type* converter = new converter_type;
	const converter_type2* converter2 = new converter_type2("ru_ru.cp1251");
	const locale utf8_locale = locale(empty_locale, converter2);

	out.open(fout, ios::out);

	out.imbue(utf8_locale);
	out << "\\newcommand{\\theFamily}{" << family << "}" << endl;
	out << "\\newcommand{\\theName}{" << name << "}" << endl;
	out << "\\newcommand{\\theGroup}{" << group << "}" << endl;
	out << "\\newcommand{\\theN}{" << N << "}" << endl;
	string name5(name);
	int length = name5.length() > 5 ? 5 : name5.length();
	name5 = name5.substr(0, length);
	IPv6 ipv6(group, name5);
	out << "\\newcommand{\\thenetIPvsix}{" << ipv6.ToString() << "}" << endl;
	out << "\\newcommand{\\prefixNstartOneTwo}{" << ipv6.firstsubnet(y0).ToString() << "}" << endl;
	out << "\\newcommand{\\prefixNfinishOneTwo}{" << ipv6.lastsubnet(y0).ToString() << "}" << endl;
	out << "\\newcommand{\\theYzero}{" << y0 << "}" << endl;

	IPv4 ipv4(N);
	out << "\\newcommand{\\theXzero}{" << int(ipv4.octet[0]) << "}" << endl;
	out << "\\newcommand{\\theXone}{" << int(ipv4.octet[1]) << "}" << endl;

	out << "\\newcommand{\\theYone}{" << y1 << "}" << endl;

	out << "\\newcommand{\\theXzeroBinary}{" << bitset<8>(int(ipv4.octet[0])) << "}" << endl;
	out << "\\newcommand{\\theXoneBinary}{" << bitset<8>(int(ipv4.octet[1])) << "}" << endl;

	out << "%2.1.1" << endl;
	bits = ceil(log2(y1));
	out << "\\newcommand{\\theamountbitstwooneone}{";
	if (bits > 4) out << 4 << " бит из " << ipv4.prefix / 8 + 1 << "-го октета и " << bits - 4;
	else out << bits;
	out << "}" << endl;

	out << "\\newcommand{\\theoctettwooneone}{";
	if (bits > 4) out << ipv4.prefix / 8 + 2;
	else out << ipv4.prefix / 8 + 1;
	out << "}" << endl;

	out << "\\newcommand{\\theamountnetstwooneone}{" << pow(2, bits) << "}" << endl;
	IPv4** subnets211 = ipv4.getsubnets(y1);
	out << "\\newcommand{\\theamounthoststwooneone}{" << pow(2, 32 - subnets211[0]->getprefix()) - 2 << "}" << endl;

	IPv4 mask = subnets211[0]->getmask();
	for (size_t i = 0; i < 4; i++){
		out << "\\newcommand{\\themask" << num2str[i] << "twooneone}{" << int(mask.octet[i]) << "}" << endl;
		out << "\\newcommand{\\themask" << num2str[i] << "binarytwooneone}{" << bitset<8>(int(mask.octet[i])) << "}" << endl;
	}

	for (size_t i = 0; i < 5; i++){
		out << "\\newcommand{\\thenetone" << num2str[i] << "}{" << subnets211[i]->ToString() << "}" << endl;
		out << "\\newcommand{\\thefirsthostone" << num2str[i] << "}{" << subnets211[i]->getfirsthost().ToString() << "}" << endl;
		out << "\\newcommand{\\thelasthostone" << num2str[i] << "}{" << subnets211[i]->getlasthost().ToString() << "}" << endl;
		out << "\\newcommand{\\thebroadcastone" << num2str[i] << "}{" << subnets211[i]->getbroadcast().ToString() << "}" << endl;
	}

	out << "%2.1.2" << endl;

	out << "\\newcommand{\\theYtwo}{" << y2 << "}" << endl;

	bits = ceil(log2(y2));
	out << "\\newcommand{\\theamountbitstwoonetwo}{";
	if (bits > 4) out << 4 << " бит из " << ipv4.prefix / 8 + 1 << "-го октета и " << bits - 4;
	else out << bits;
	out << "}" << endl;

	out << "\\newcommand{\\theoctettwoonetwo}{";
	if (bits > 4) out << ipv4.prefix / 8 + 2;
	else out << ipv4.prefix / 8 + 1;
	out << "}" << endl;

	IPv4** subnets212 = ipv4.getsubnets(y2);
	out << "\\newcommand{\\theamountnetstwoonetwo}{" << pow(2, bits) << "}" << endl;
	out << "\\newcommand{\\theamountbitshoststwoonetwo}{" << 32 - subnets212[0]->getprefix() << "}" << endl;
	out << "\\newcommand{\\theamounthoststwoonetwo}{" << pow(2, 32 - subnets212[0]->getprefix()) - 2 << "}" << endl;

	mask = subnets212[0]->getmask();
	for (size_t i = 0; i < 4; i++){
		out << "\\newcommand{\\themask" << num2str[i] << "twoonetwo}{" << int(mask.octet[i]) << "}" << endl;
		out << "\\newcommand{\\themask" << num2str[i] << "binarytwoonetwo}{" << bitset<8>(int(mask.octet[i])) << "}" << endl;
	}

	{
		out << "\\newcommand{\\thenetfirst" << num2str[0] << "}{" << subnets212[0]->ToString() << "}" << endl;
		out << "\\newcommand{\\thefirsthostfirst" << num2str[0] << "}{" << subnets212[0]->getfirsthost().ToString() << "}" << endl;
		out << "\\newcommand{\\thelasthostfirst" << num2str[0] << "}{" << subnets212[0]->getlasthost().ToString() << "}" << endl;
		out << "\\newcommand{\\thebroadcastfirst" << num2str[0] << "}{" << subnets212[0]->getbroadcast().ToString() << "}" << endl;

		out << "\\newcommand{\\thenetend" << num2str[0] << "}{" << subnets212[y2 - 1]->ToString() << "}" << endl;
		out << "\\newcommand{\\thefirsthostend" << num2str[0] << "}{" << subnets212[y2 - 1]->getfirsthost().ToString() << "}" << endl;
		out << "\\newcommand{\\thelasthostend" << num2str[0] << "}{" << subnets212[y2 - 1]->getlasthost().ToString() << "}" << endl;
		out << "\\newcommand{\\thebroadcastend" << num2str[0] << "}{" << subnets212[y2 - 1]->getbroadcast().ToString() << "}" << endl;
	}

	out << "%2.2.1" << endl;
	out << "\\newcommand{\\theZone}{" << z1 << "}" << endl;

	IPv4** subnets221 = ipv4.getsubnetsbyhosts(z1);
	out << "\\newcommand{\\theamountbitstwotwoone}{" << subnets221[0]->getprefix() - ipv4.getprefix() << "}" << endl;
	out << "\\newcommand{\\theamountnetstwotwoone}{" << pow(2, 32 - ipv4.prefix - ceil(log2(z2))) << "}" << endl;
	out << "\\newcommand{\\theamountbitshoststwotwoone}{" << 32 - subnets221[0]->getprefix() << "}" << endl;
	out << "\\newcommand{\\theamounthoststwotwoone}{" << pow(2, 32 - subnets221[0]->getprefix()) - 2 << "}" << endl;

	mask = subnets221[0]->getmask();
	for (size_t i = 0; i < 4; i++){
		out << "\\newcommand{\\themask" << num2str[i] << "twotwoone}{" << int(mask.octet[i]) << "}" << endl;
		out << "\\newcommand{\\themask" << num2str[i] << "binarytwotwoone}{" << bitset<8>(int(mask.octet[i])) << "}" << endl;
	}

	int number_nets = pow(2, 32 - (ipv4.getprefix() + ceil(log2(z1))));
	for (size_t i = number_nets - 5; i < number_nets; i++){
		out << "\\newcommand{\\thenettwo" << num2str[i - (number_nets - 5)] << "}{" << subnets221[i]->ToString() << "}" << endl;
		out << "\\newcommand{\\thefirsthosttwo" << num2str[i - (number_nets - 5)] << "}{" << subnets221[i]->getfirsthost().ToString() << "}" << endl;
		out << "\\newcommand{\\thelasthosttwo" << num2str[i - (number_nets - 5)] << "}{" << subnets221[i]->getlasthost().ToString() << "}" << endl;
		out << "\\newcommand{\\thebroadcasttwo" << num2str[i - (number_nets - 5)] << "}{" << subnets221[i]->getbroadcast().ToString() << "}" << endl;
	}

	out << "%2.2.2" << endl;

	out << "\\newcommand{\\theZtwo}{" << z2 << "}" << endl;
	IPv4** subnets222 = ipv4.getsubnetsbyhosts(z2 + 2);
	out << "\\newcommand{\\theamountbitshoststwotwotwo}{" << 32 - subnets222[0]->getprefix() << "}" << endl;
	out << "\\newcommand{\\theamounthoststwotwotwo}{" << pow(2, 32 - subnets222[0]->getprefix()) - 2 << "}" << endl;

	mask = subnets222[0]->getmask();
	for (size_t i = 0; i < 4; i++){
		out << "\\newcommand{\\themask" << num2str[i] << "twotwotwo}{" << int(mask.octet[i]) << "}" << endl;
		out << "\\newcommand{\\themask" << num2str[i] << "binarytwotwotwo}{" << bitset<8>(int(mask.octet[i])) << "}" << endl;
	}

	int number_nets2 = pow(2, 32 - (ipv4.getprefix() + ceil(log2(z2 + 2))));
	{
		out << "\\newcommand{\\thenetfirst" << num2str[1] << "}{" << subnets222[0]->ToString() << "}" << endl;
		out << "\\newcommand{\\thefirsthostfirst" << num2str[1] << "}{" << subnets222[0]->getfirsthost().ToString() << "}" << endl;
		out << "\\newcommand{\\thelasthostfirst" << num2str[1] << "}{" << subnets222[0]->getlasthost().ToString() << "}" << endl;
		out << "\\newcommand{\\thebroadcastfirst" << num2str[1] << "}{" << subnets222[0]->getbroadcast().ToString() << "}" << endl;

		out << "\\newcommand{\\thenetend" << num2str[1] << "}{" << subnets222[number_nets2 - 1]->ToString() << "}" << endl;
		out << "\\newcommand{\\thefirsthostend" << num2str[1] << "}{" << subnets222[number_nets2 - 1]->getfirsthost().ToString() << "}" << endl;
		out << "\\newcommand{\\thelasthostend" << num2str[1] << "}{" << subnets222[number_nets2 - 1]->getlasthost().ToString() << "}" << endl;
		out << "\\newcommand{\\thebroadcastend" << num2str[1] << "}{" << subnets222[number_nets2 - 1]->getbroadcast().ToString() << "}" << endl;
	}

	out << "%2.2.3" << endl;
	out << "\\newcommand{\\theZthree}{" << z3 << "}" << endl;
	IPv4** subnets223 = ipv4.getsubnetsbyhosts(z3 + 2);
	out << "\\newcommand{\\theamountbitshoststwotwothree}{" << 32 - subnets223[0]->getprefix() << "}" << endl;
	out << "\\newcommand{\\theamounthoststwotwothree}{" << pow(2, 32 - subnets223[0]->getprefix()) - 2 << "}" << endl;

	mask = subnets222[0]->getmask();
	for (size_t i = 0; i < 4; i++){
		out << "\\newcommand{\\themask" << num2str[i] << "twotwothree}{" << int(mask.octet[i]) << "}" << endl;
		out << "\\newcommand{\\themask" << num2str[i] << "binarytwotwothree}{" << bitset<8>(int(mask.octet[i])) << "}" << endl;
	}

	number_nets = pow(2, 32 - (ipv4.getprefix() + ceil(log2(z3 + 2))));
	for (size_t i = number_nets - 5; i < number_nets; i++){
		out << "\\newcommand{\\thenetthree" << num2str[i - (number_nets - 5)] << "}{" << subnets223[i]->ToString() << "}" << endl;
		out << "\\newcommand{\\thefirsthostthree" << num2str[i - (number_nets - 5)] << "}{" << subnets223[i]->getfirsthost().ToString() << "}" << endl;
		out << "\\newcommand{\\thelasthostthree" << num2str[i - (number_nets - 5)] << "}{" << subnets223[i]->getlasthost().ToString() << "}" << endl;
		out << "\\newcommand{\\thebroadcastthree" << num2str[i - (number_nets - 5)] << "}{" << subnets223[i]->getbroadcast().ToString() << "}" << endl;
	}
	out.close();
}


int main(){
	char* surname[] = { "Cheretaev", "Kondratyev", "Kostarev", "Zykina", "Tuleneva", "Noskov", "Samoylov", "Dudin", "Tuyfyakov", "Anikin", "Shadrin", "Mehontsev", "Murzin", "Kozyncev", "Buchelnikov", "Tarasov", "Alexandrov", "Zavada", "Gizzatullina", "Rodionov", "Chebakov", "Shakirov", "Khomutinnikov", "Trepalin", "Bernhardt", "Bogarytev", "Filipchenko", "Ibragimov", "Lampiga", "Maletin", "Rusinov", "Safronov" };
	char* name[] = { "Ivan", "Andrey", "Dmitry", "Maria", "Ksenia", "Dmitriy", "Evgeny", "Nikita", "Nikita", "Kirill", "Nikita", "Dmitry", "Ruslan", "Dmitry", "Artyom", "Anton", "Oleg", "Svetlana", "Anzhe", "Alexander", "Vitalii", "Evgeny", "Pavel", "Timofey", "Mark", "Stanislav", "Vladislav", "Vadim", "Sergey", "Kirill", "Pavel", "Nikita" };
	int group[] = { 20207, 20201, 20201, 20207, 20201, 20201, 20201, 20201, 20207, 20207, 20207, 20201, 20207, 20201, 20207, 20201, 20207, 20201, 20201, 20207, 20207, 20201, 20207, 20207, 20207, 20207, 20207, 20207, 20201, 20201, 20207, 20207 };
	int y0[] = { 2, 2, 2, 4, 4, 4, 4, 4, 8, 8, 8, 8, 8, 8, 8, 8, 10, 20, 25, 32, 40, 47, 50, 56, 63, 65, 66, 70, 80, 100, 111, 125 };
	int y1[] = { 8, 16, 16, 32, 16, 64, 8, 128, 256, 512, 1024, 512, 1024, 4096, 2048, 16384, 32768, 512, 1024, 4096, 2048, 16384, 32768, 512, 1024, 4096, 2048, 16384, 32768, 512, 1024, 4096 };
	int y2[] = { 10, 12, 15, 20, 22, 25, 28, 31, 33, 36, 40, 50, 60, 70, 80, 100, 150, 200, 250, 300, 400, 500, 1000, 1200, 1400, 1800, 2500, 3000, 7000, 10000, 15000, 20000 };
	int z1[] = { 256, 16, 32, 64, 128, 256, 256, 512, 1024, 2048, 4096, 8192, 16384, 16384, 16384, 16384, 16384, 8192, 16384, 32768, 1024, 2048, 4096, 8192, 16384, 32768, 1024, 2048, 4096, 8192, 16384, 32768 };
	int z2[] = { 10, 15, 20, 25, 30, 50, 80, 100, 120, 150, 200, 220, 255, 300, 400, 500, 1000, 1200, 1500, 2000, 2048, 1000, 2000, 1000, 2000, 8000, 9000, 10000, 15000, 20000, 25000, 10000 };
	int z3[] = { 5, 30, 13, 16, 25, 1, 32, 40, 48, 64, 80, 100, 110, 111, 120, 66, 200, 400, 500, 1000, 200, 400, 500, 8000, 200, 400, 500, 1000, 200, 400, 500, 1000 };
	int N[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32 };
	int count = 32;

	//char* surname[] = { "Cheretaev" };
	//char* name[] = { "Ivan" };
	//int group[] = { 20207 };
	//int y0[] = { 2 };
	//int y1[] = { 8 };
	//int y2[] = { 10 };
	//int z1[] = { 256 };
	//int z2[] = { 10 };
	//int z3[] = { 5 };
	//int N[] = { 1 };
	//int count = 1;


	for (size_t i = 0; i < count; i++){
		cout << surname[i] << name[i] << endl;
		wcontrol_work("report.sty", surname[i], name[i], group[i], N[i], y0[i], y1[i], y2[i], z1[i], z2[i], z3[i]);
		system("pdflatex.exe -synctex=1 -interaction=nonstopmode \"shablon\".tex >> log_program.log");
		stringstream syscopy;
		syscopy << "copy shablon.pdf " << surname[i] << name[i] << ".pdf >> log_program.log";
		system(&syscopy.str()[0]);
	}
	IPv6 ipv6t1 = IPv6();
	IPv6* ipv6 = new IPv6(20207, string("Oleg"));
	/*out << ipv6->ToString() << endl;;
	out << ipv6t1.ToString() << endl;*/
	system("pause");
	return 0;
}
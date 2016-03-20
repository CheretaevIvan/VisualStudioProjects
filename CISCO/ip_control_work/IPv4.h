#pragma once
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

class IPv4
{
	
public:
	size_t prefix;
	unsigned __int8 octet[4];
	IPv4();
	IPv4(int);
	IPv4(unsigned __int32, int);
	IPv4(unsigned __int8, unsigned __int8, unsigned __int8, unsigned __int8, int);
	IPv4(const IPv4&);

	int getprefix();
	IPv4** getsubnets(int);
	IPv4** getsubnetsbyhosts(int);
	IPv4 getmask();
	IPv4 getfirsthost();
	IPv4 getlasthost();
	IPv4 getbroadcast();
	IPv4 operator^(const IPv4&);
	IPv4 operator|(const IPv4&);
	string ToString();
	~IPv4();
};


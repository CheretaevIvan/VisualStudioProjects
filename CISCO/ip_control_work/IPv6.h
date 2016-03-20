#pragma once
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

class IPv6
{
private:
	unsigned __int16 hextet[8];
	int prefix;
	//__int64 iden
public:
	IPv6();
	IPv6(int, string);
	IPv6(const IPv6 &);

	string ToString();

	IPv6 firstsubnet(int);
	IPv6 lastsubnet(int);

	~IPv6();
};


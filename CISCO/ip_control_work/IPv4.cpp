#include "IPv4.h"


IPv4::IPv4()
{
	prefix = 0;
	for (size_t i = 0; i < 4; i++){
		octet[i] = 0;
	}
}

IPv4::IPv4(unsigned __int8 _o1, unsigned __int8 _o2, unsigned __int8 _o3, unsigned __int8 _o4, int _prefix){
	octet[0] = _o1;
	octet[1] = _o2;
	octet[2] = _o3;
	octet[3] = _o4;
	prefix = _prefix;
}

IPv4::IPv4(unsigned __int32 ip, int _prefix){
	for (size_t i = 0; i < 4; i++){
		octet[i] = unsigned __int8((ip << (i * 8)) >> 24);
	}
	prefix = _prefix;
}

IPv4::IPv4(int N){
	octet[0] = (N * 16) / 254 + 10;
	octet[1] = (N * 16) % 256;
	octet[2] = octet[3] = 0;
	prefix = 12;
}

IPv4::IPv4(const IPv4 &ipv4){
	prefix = ipv4.prefix;
	for (size_t i = 0; i < 4; i++){
		octet[i] = ipv4.octet[i];
	}
}

int IPv4::getprefix(){
	return prefix;
}

IPv4** IPv4::getsubnets(int N){
	int k = ceil(log2(N));
	IPv4 **subnets = new IPv4*[N];
	for (size_t i = 0; i < N; i++){
		subnets[i] = new IPv4(*this);
		subnets[i]->prefix += k;
		*(subnets[i]) = subnets[i]->operator|(IPv4(i << (32-prefix-k), prefix + k));
	}
	return subnets;
}

IPv4** IPv4::getsubnetsbyhosts(int N){
	int k1 = ceil(log2(N));
	int k = 32 - (prefix + k1);
	int number_nets = pow(2, k);
	IPv4 **subnets = new IPv4*[number_nets];
	for (size_t i = 0; i < number_nets; i++){
		subnets[i] = new IPv4(*this);
		subnets[i]->prefix += k;
		*(subnets[i]) = subnets[i]->operator|(IPv4(i << k1, prefix+k));
	}
	return subnets;
}

IPv4 IPv4::getmask(){
	IPv4 res = IPv4();
	for (size_t i = 0; i < prefix / 8; i++){
		res.octet[i] = 0xff;
	}
	res.octet[prefix / 8] = ~(0xff >> (prefix % 8));
	return res;
}

IPv4 IPv4::getfirsthost(){
	IPv4 res(*this);
	res.octet[3] |= 1;
	res.prefix = 0;
	return res;
}

IPv4 IPv4::getlasthost(){
	IPv4 res = getbroadcast();
	res.octet[3] &= 0xfe;
	return res;
}

IPv4 IPv4::getbroadcast(){
	return getmask() ^ IPv4(0xff, 0xff, 0xff, 0xff, 32) | (*this);
}

IPv4 IPv4::operator|(const IPv4 &ipv4){
	IPv4 res(*this);
	for (size_t i = 0; i < 4; i++){
		res.octet[i] |= ipv4.octet[i];
	}
	return res;
}

IPv4 IPv4::operator^(const IPv4 &ipv4){
	IPv4 res(*this);
	for (size_t i = 0; i < 4; i++){
		res.octet[i] ^= ipv4.octet[i];
	}
	return res;
}

string IPv4::ToString(){
	stringstream stream;
	for (size_t i = 0; i < 3; i++){
		stream << dec << unsigned int(octet[i]) << ".";
	}
	stream << dec << unsigned int(octet[3]);
	if (prefix) stream << dec << "/" << prefix;
	return stream.str();
}

IPv4::~IPv4()
{
}

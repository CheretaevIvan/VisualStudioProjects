#include "IPv6.h"


IPv6::IPv6()
{
	prefix = 64;
	for (size_t i = 0; i < 8; i++){
		hextet[i] = 0;
	}
}

IPv6::IPv6(const IPv6 &ipv6){
	prefix = ipv6.prefix;
	for (size_t i = 0; i < 8; i++){
		hextet[i] = ipv6.hextet[i];
	}
}

IPv6::IPv6(int group, string name){	
	hextet[0] = 0x2001;
	hextet[1] = 0xdb8;
	for (size_t i = 2; i < 8; i++){
		hextet[i] = 0;
	}
	hextet[3] = group;
	int i = 8;
	/*hextet[3] = group;
	int i = 8*/;
	for (string::iterator itr = name.begin(); itr != name.end(); ++itr, ++i){
		char sym = *itr;
		hextet[i / 2] |= sym << ((i+1) % 2) * 8;
	}
	prefix = 128;
	for (size_t i = 7; i >= 0; i--){
		for (size_t j = 0; j <= 15; j++){
			if (!(__int16(hextet[i] << 15-j) >> j))
				prefix--;
			else return;
		}
	}
}

IPv6 IPv6::firstsubnet(int N){
	int k = ceil(log2(N));
	IPv6 res(*this);
	res.prefix += k;
	return res;
}

IPv6 IPv6::lastsubnet(int N){
	int k = ceil(log2(N));
	IPv6 res(*this);
	//for (size_t i = 0; i < k; i++){
		int pr = res.prefix / 16;
		int pr1 = res.prefix % 16;
		if (pr1+k<=16)
			res.hextet[pr] |= __int16((N-1) << (16 - (pr1 + k)));
		else{
			res.hextet[pr] |= (N-1) >> pr1;
			res.hextet[pr + 1] |= ((N-1) << k) >> (16 - k);
		}
	//}
	res.prefix += k;
	return res;
}

string IPv6::ToString(){
	stringstream stream;
	for (size_t i = 0; i < 7; i++){
		stream << hex << hextet[i] << ":";
	}
	stream << hex << hextet[7];
	string tmp = stream.str();
	int pos = -1;
	if ((pos = tmp.find("0:0:0:0:0:0:0:0")) != -1){
		tmp.replace(pos, 15, "::");
		stream.str("");
		stream << tmp;
		stream << dec << "/" << prefix;
		return stream.str();
	}
	if ((pos = tmp.find(":0:0:0:0:0:0:0")) != -1){
		if (pos == tmp.length() - 14){
			tmp.replace(pos, 14, "::");
			stream.str("");
			stream << tmp;
			stream << dec << "/" << prefix;
			return stream.str();
		}
	}
	if ((pos = tmp.find("0:0:0:0:0:0:0:")) != -1){
		if (pos == 0){
			tmp.replace(pos, 14, "::");
			stream.str("");
			stream << tmp;
			stream << dec << "/" << prefix;
			return stream.str();
		}
	}
	if ((pos = tmp.find(":0:0:0:0:0:0:")) != -1){
		tmp.replace(pos, 13, "::");
		stream.str("");
		stream << tmp;
		stream << dec << "/" << prefix;
		return stream.str();
	}
	if ((pos = tmp.find("0:0:0:0:0:0:")) != -1){
		if (pos == 0){
			tmp.replace(pos, 12, "::");
			stream.str("");
			stream << tmp;
			stream << dec << "/" << prefix;
			return stream.str();
		}
	}
	if ((pos = tmp.find(":0:0:0:0:0:0")) != -1){
		if (pos == tmp.length() - 12){
			tmp.replace(pos, 12, "::");
			stream.str("");
			stream << tmp;
			stream << dec << "/" << prefix;
			return stream.str();
		}
	}
	if ((pos = tmp.find(":0:0:0:0:0:")) != -1){
		tmp.replace(pos, 11, "::");
		stream.str("");
		stream << tmp;
		stream << dec << "/" << prefix;
		return stream.str();
	}
	if ((pos = tmp.find(":0:0:0:0:0")) != -1){
		if (pos == tmp.length() - 10){
			tmp.replace(pos, 10, "::");
			stream.str("");
			stream << tmp;
			stream << dec << "/" << prefix;
			return stream.str();
		}
	}
	if ((pos = tmp.find("0:0:0:0:0:")) != -1){
		if (pos == 0){
			tmp.replace(pos, 10, "::");
			stream.str("");
			stream << tmp;
			stream << dec << "/" << prefix;
			return stream.str();
		}
	}
	if ((pos = tmp.find(":0:0:0:0:")) != -1){
		tmp.replace(pos, 9, "::");
		stream.str("");
		stream << tmp;
		stream << dec << "/" << prefix;
		return stream.str();
	}
	if ((pos = tmp.find(":0:0:0:0")) != -1){
		if (pos == tmp.length() - 8){
			tmp.replace(pos, 8, "::");
			stream.str("");
			stream << tmp;
			stream << dec << "/" << prefix;
			return stream.str();
		}
	}
	if ((pos = tmp.find("0:0:0:0:")) != -1){
		if (pos == 0){
			tmp.replace(pos, 8, "::");
			stream.str("");
			stream << tmp;
			stream << dec << "/" << prefix;
			return stream.str();
		}
	}
	if ((pos = tmp.find(":0:0:0:")) != -1){
		tmp.replace(pos, 7, "::");
		stream.str("");
		stream << tmp;
		stream << dec << "/" << prefix;
		return stream.str();
	}
	if ((pos = tmp.find(":0:0:0")) != -1){
		if (pos == tmp.length() - 6){
			tmp.replace(pos, 6, "::");
			stream.str("");
			stream << tmp;
			stream << dec << "/" << prefix;
			return stream.str();
		}
	}
	if ((pos = tmp.find("0:0:0:")) != -1){
		if (pos == 0){
			tmp.replace(pos, 6, "::");
			stream.str("");
			stream <<tmp;
			stream << dec << "/" << prefix;
			return stream.str();
		}
	}
	if ((pos = tmp.find(":0:0:")) != -1){
		tmp.replace(pos, 5, "::");
		stream.str("");
		stream << tmp;
		stream << dec << "/" << prefix;
		return stream.str();
	}
	if ((pos = tmp.find(":0:0")) != -1){
		if (pos == tmp.length() - 4){
			tmp.replace(pos, 4, "::");
			stream.str("");
			stream << tmp;
			stream << dec << "/" << prefix;
			return stream.str();
		}
	}
	if ((pos = tmp.find("0:0:")) != -1){
		if (pos == 0){
			tmp.replace(pos, 4, "::");
			stream.str("");
			stream << tmp;
			stream << dec << "/" << prefix;
			return stream.str();
		}
	}
	stream.str("");
	stream << tmp;
	stream << dec << "/" << prefix;
	return stream.str();
}

IPv6::~IPv6()
{
}

#include "pch.h"
#include <iostream>
#include <iostream>
#include <string>
using namespace std;


encrypter::encrypter()
{
	coded = "";
}



void encrypter::EncodeChar(char chr)
{
	int ac = int(chr);
	coded = GetBinari(ac);
	coded = ComplementOne(coded);
	coded = Reverse(coded);

}

void encrypter::Decode(string str)
{
	str = Reverse(str);
	str = ComplementOne(str);
	int ac = GetInteger(str);
	coded = char(ac);
}

std::ostream & operator<<(std::ostream & ofs, const encrypter & enc)
{
	ofs << enc.coded;
	return ofs;
}




string encrypter::GetBinari(int n)
{
	string result = "00000000";
	int i = 7;
	while (n > 0)
	{
		if (n % 2 == 1)
		{
			result[i] = '1';
		}
		n = n / 2;
		i--;
	}
	return result;
}

int encrypter::GetInteger(string str)
{
	int result = 0;
	int cp = 1;
	for (int i = 7; i > -1; i--)
	{
		if (str[i] == '1')
		{
			result += cp;
		}

		cp *= 2;
	}
	return result;
}
string encrypter::ComplementOne(string str)
{
	for (int i = 0; i < 8; i++)
	{
		if (str[i] == '1')
		{
			str[i] = '0';
		}
		else
		{
			str[i] = '1';
		}
	}
	return str;
}

string encrypter::Reverse(string str)
{
	char temp;
	for (int i = 0; i < 4; i++)
	{
		temp = str[i];
		str[i] = str[7 - i];
		str[7 - i] = temp;
	}
	return str;
}




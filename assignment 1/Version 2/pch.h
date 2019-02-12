

#ifndef PCH_H
#define PCH_H
#include <iostream>
#include <string>
using namespace std;
class encrypter
{
private:
	std::string coded;

public:
	encrypter();

	string GetBinari(int n);
	int GetInteger(string str);
	string ComplementOne(string str);
	string Reverse(string str);
	void EncodeChar(char chr);
	void Decode(string str);
	friend std::ostream & operator<<(std::ostream & ofs, const encrypter & enc);
};
#endif //PCH_H

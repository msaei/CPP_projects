// Encrypter2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string> // make string class available
#include <fstream>
using namespace std;

int main()
{
	using namespace std;
	string str;
	encrypter enc1;

	ifstream fin("input.txt");
	ofstream encOut("enc.txt");


	while (!fin.eof())
	{
		getline(fin, str);

		for (int i = 0; i < str.size(); i++)
		{
			enc1.EncodeChar(str[i]);
			encOut << enc1;
		}

		encOut << "10101111";

	}

	encOut.close();
	ifstream encIn("enc.txt");
	ofstream decOut("dec.txt");

	getline(encIn, str);

	for (int i = 0; i < str.size(); i += 8)
	{
		string ss = str.substr(i, 8);
		enc1.Decode(ss);
		decOut << enc1;
	}


	return 0;
}

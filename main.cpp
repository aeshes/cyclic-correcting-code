#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "code.h"
#include "gf.h"
#include "bits.h"

using namespace std;

vector<bitset<15>> generate_code(unsigned int from, unsigned int to)
{
	vector<bitset<15>> code;

	for (unsigned int msg = from; msg < to; msg++)
	{
		code.push_back(bitset<15>(encode(msg)));
	}
	return code;
}

void encode_file(string filein, string fileout)
{
	try
	{
		ifstream in(filein, ios_base::binary);
		ofstream out(fileout, ios_base::binary);
		char byte = 0;

		while (in >> byte)
		{
			cout << byte;
			auto encoded = encode(byte);
			out.write(reinterpret_cast<char *>(&encoded), 2);
		}

		in.close();
		out.close();
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}
}

void decode_file(string filein, string fileout)
{
	try
	{
		ifstream in(filein, ios_base::binary);
		ofstream out(fileout, ios_base::binary);
		unsigned short codeword = 0;
		char byte = 0;

		while (in.read(reinterpret_cast<char *>(&codeword), 2))
		{
			auto decoded = decode(codeword);
			out.write(reinterpret_cast<char*>(&decoded), 1);
		}

		in.close();
		out.close();
	}
	catch (exception e)
	{

	}
}

int main()
{
	gf_poly message = 0x36;
	gf_poly encoded, decoded = 0;

	cout << "message = " << bitset<15>(message) << endl;

	encoded = encode(message);
	cout << "encoded = " << bitset<15>(encoded) << endl;

	decoded = decode(encoded);
	cout << "decoded = " << bitset<15>(decoded) << endl;

	encoded = toggle_bit(encoded, 3);
	encoded = toggle_bit(encoded, 4);
	cout << "corrupt = " << bitset<15>(encoded) << endl;

	decoded = decode(encoded);
	cout << "decoded = " << bitset<15>(decoded) << endl;

	encode_file("data.in", "data.out");
	decode_file("data.out", "data.dec");
}
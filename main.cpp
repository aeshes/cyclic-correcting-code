#include <iostream>
#include <vector>
#include "code.h"
#include "gf.h"
#include "bits.h"

using namespace std;

int main()
{
	gf_poly message = 0x41;
	gf_poly encoded, decoded = 0;

	cout << "message = " << bitset<14>(message) << endl;

	encoded = encode(message);
	cout << "encoded = " << bitset<14>(encoded) << endl;

	decoded = decode(encoded);
	cout << "decoded = " << bitset<14>(decoded) << endl;

	encoded = toggle_bit(encoded, 3);
	encoded = toggle_bit(encoded, 4);
	cout << "corrupt = " << bitset<14>(encoded) << endl;

	decoded = decode(encoded);
	cout << "decoded = " << bitset<14>(decoded) << endl;

	for (char c = 32; c <= 126; c++)
	{
		auto encoded = encode(c);
		auto decoded = decode(encoded);

		cout << "Encoding of symbol " << c << ": " << bitset<14>(encoded) << endl;
		cout << "Decoding of " << bitset<14>(encoded) << ": " << static_cast<char>(decoded) << endl;
	}
}
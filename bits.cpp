#include "constants.h"
#include "bits.h"

int hamming_norm(unsigned int a)
{
	int result = 0;

	while (a > 0)
	{
		if (a & 1)
			result++;
		a >>= 1;
	}

	return result;
}

int hamming_distance(unsigned int a, unsigned int b)
{
	return hamming_norm(a ^ b); 
}

int bit_length(unsigned int a)
{
	int length = 0;

	while (a > 0)
	{
		length++;
		a >>= 1;
	}

	return length;
}

unsigned int toggle_bit(unsigned int a, int bit)
{
	return a ^ (1 << bit);
}

unsigned int rol(unsigned int a, int bits)
{
	return ((a << bits) | (a >> (CODE_LENGTH - bits))) & CODE_BITMASK;
}

unsigned int ror(unsigned int a, int bits)
{
	return ((a >> bits) | (a << (CODE_LENGTH - bits))) & CODE_BITMASK;
}
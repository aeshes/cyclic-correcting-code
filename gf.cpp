#include <iostream>
#include "bits.h"
#include "gf.h"

inline int deg(gf_poly a) {
	if (a == 0)
		return -1;
	else
		return bit_length(a) - 1;
}

gf_poly mul(gf_poly a, gf_poly b)
{
	gf_poly result = 0;

	while (a != 0)
	{
		if (a & 1)
			result ^= b;
		a >>= 1;
		b <<= 1;
	}

	return result;
}

gf_poly rem(gf_poly a, gf_poly b)
{
	gf_poly rem = a;

	while (deg(rem) >= deg(b))
	{
		int power = deg(rem) - deg(b);
		rem ^= b << power;
	}

	return rem;
}

void div(gf_poly a, gf_poly b, gf_poly & quo, gf_poly & rem)
{
	rem = a;
	quo = 0;

	while (deg(rem) >= deg(b)) {
		int power = deg(rem) - deg(b);
		rem ^= b << power; 
		quo ^= 1 << power;
	}
}
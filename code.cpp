#include "constants.h"
#include "code.h"
#include "bits.h"


gf_poly encode(gf_poly message)
{
	return mul(message, GENERATOR);
}

gf_poly correct_errors(gf_poly message, gf_poly syndrome)
{
	if (hamming_norm(syndrome) <= ERROR_CORRECTION_COUNT)
	{
		return message ^ syndrome;
	}
	else
	{
		for (int i = 1; i < CODE_LENGTH; i++)
		{
			syndrome = rol(syndrome, 1);
			gf_poly s = rem(syndrome, GENERATOR);

			if (hamming_norm(s) <= ERROR_CORRECTION_COUNT)
			{
				return message ^ ror(s, i);
			}
		}
	}

	return 0;
}

gf_poly decode(gf_poly message)
{
	gf_poly decoded, syndrome = 0;

	div(message, GENERATOR, decoded, syndrome);

	if (syndrome == 0)
	{
		return decoded;
	}
	else
	{
		message = correct_errors(message, syndrome);

		div(message, GENERATOR, decoded, syndrome);

		return decoded;
	}
}
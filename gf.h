#pragma once

#include <bitset>

using gf_poly = unsigned int;


int deg(gf_poly a);

gf_poly mul(gf_poly a, gf_poly b);

gf_poly rem(gf_poly a, gf_poly b);

void div(gf_poly a, gf_poly b, gf_poly& quo, gf_poly& rem);
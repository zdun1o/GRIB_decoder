#include "Base.h"

int Base::ToIntFromBytes(char* pass_in, int bits) {
	if (bits == 8) return uint8_t(pass_in[0]);
	int rn = 0;
	int idx = (bits / 8) - 1;
	char tmp[1];
	tmp[0] = pass_in[idx];
	for (int i = 0; i < bits; i++) {
		rn += (tmp[0] & 1) ? std::pow(2, i) : 0;
		tmp[0] = pass_in[idx] >> (i + 1) % 8;
		if (i == 7 || i == 15 || i == 23) {
			idx--;
			tmp[0] = pass_in[idx];
		}
	}
	return rn;
}

float Base::binaryToFloat(char* pass_in) {
	int sign = (pass_in[0] & 128) ? 1 : 0;
	uint8_t exp = 0;
	float mantisa = 1.0f;

	char tmp[1];
	tmp[0] = pass_in[0] & 127;
	//tmp[0] = pass_in[0] << 1;
	//tmp[0] = tmp[0] | ((pass_in[1] & 128) ? 1 : 0);
	exp = uint8_t(tmp[0]);

	int idx = 3;
	tmp[0] = pass_in[idx];
	for (int i = 31; i >= 8; i--) {
		mantisa += (tmp[0] & 1) ? pow(2, 8 - i) : 0.0f;
		tmp[0] = tmp[0] >> 1;
		if (i == 24 || i == 16) {
			idx--;
			tmp[0] = pass_in[idx];
		}
	}

	mantisa = pass_in[1] << 16 | pass_in[2] << 8 | pass_in[3];

	//return sign * mantisa * pow(2, exp - 127);
	return (-1) * pow(-1, sign) * pow(2, -24) * mantisa * pow(16, exp - 64);
}

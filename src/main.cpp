#include "Decoder.h"

int main() {
	Decoder decoder;
	decoder.ReadGribFile("src\\20150310.00.W.dwa_griby.grib");
	decoder.Decode();

	std::cin.get();
}
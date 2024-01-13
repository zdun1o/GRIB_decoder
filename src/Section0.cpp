#include "Section0.h"

void Section0::Read(std::vector<char> data, int& offset) {
	while (std::memcpy(m_Begin, data.data() + offset, 4)) {
		if (strncmp(m_Begin, "GRIB", 4) == 0) {
			offset += 4;
			std::memcpy(m_Length, data.data() + offset, 4);
			offset += 4;
			break;
		}
		else offset++;
	}
}

void Section0::ShowSection() {
	std::cout << "----- SECTION 0 -----\n";
	for (auto i : m_Begin) std::cout << i;
	std::cout << "\n";
	std::cout << "Length: " << ToIntFromBytes(m_Length, sizeof(m_Length) * 8) << "\n";
	std::cout << "Version: " << ToIntFromBytes(m_EditionNumber, sizeof(m_EditionNumber) * 8) << "\n";
}
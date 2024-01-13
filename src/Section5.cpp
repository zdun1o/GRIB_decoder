#include "Section5.h"

void Section5::Read(std::vector<char> data, int& offset) {
	std::memcpy(m_End, data.data() + offset, 4);
	offset += 4;
}

void Section5::ShowSection() {
	std::cout << "----- SECTION 5 -----\n";
	for (auto i : m_End) std::cout << i;
	std::cout << "\n";
}
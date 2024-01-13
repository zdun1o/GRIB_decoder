#include "Section3.h"

Section3::Section3(bool state)
	:BMS_state(state)
{
}

void Section3::Read(std::vector<char> data, int& offset) {
	if (BMS_state) {
		std::memcpy(m_LengthBMS, data.data() + offset, 6);
		offset += 6;

		m_BitMap.resize(ToIntFromBytes(m_LengthBMS, sizeof(m_LengthBMS) * 8) - 6);
		std::memcpy(m_BitMap.data(), data.data() + offset, m_BitMap.size());
		offset += m_BitMap.size();
	}
}

void Section3::ShowSection() {
	if (BMS_state) {
		std::cout << "----- SECTION 3 -----\n";
		std::cout << "Length: " << ToIntFromBytes(m_LengthBMS, sizeof(m_LengthBMS) * 8) << "\n";
	}
}
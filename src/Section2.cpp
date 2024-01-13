#include "Section2.h"

Section2::Section2(bool state)
	:GDS_state(state)
{
}

void Section2::Read(std::vector<char> data, int& offset) {
	
	if (GDS_state) {
		std::memcpy(m_LengthGDS, data.data() + offset, 6);
		offset += 6;

		std::memcpy(m_GridDescription.Ni, data.data() + offset, sizeof(La_Lo));
		offset += sizeof(La_Lo);

		int length = ToIntFromBytes(m_LengthGDS, sizeof(m_LengthGDS) * 8) - ToIntFromBytes(m_PVPL, sizeof(m_PVPL) * 8) + 1;
		m_PVPL_list.resize(length);
		std::memcpy(m_PVPL_list.data(), data.data() + offset, length);
		offset += length;
	}
}

void Section2::ShowSection() {
	if (GDS_state) {
		std::cout << "----- SECTION 2 -----\n";
		std::cout << "Length: " << ToIntFromBytes(m_LengthGDS, sizeof(m_LengthGDS) * 8) << "\n";
		std::cout << "Ni: " << ToIntFromBytes(m_GridDescription.Ni, sizeof(m_GridDescription.Ni) * 8) << "\n";
		std::cout << "Nj: " << ToIntFromBytes(m_GridDescription.Nj, sizeof(m_GridDescription.Nj) * 8) << "\n";

		std::cout << "La1: " << ((m_GridDescription.La1[0] & 128) ? "south " : "north ");
		m_GridDescription.La1[0] = m_GridDescription.La1[0] & 127;
		std::cout << ToIntFromBytes(m_GridDescription.La1, sizeof(m_GridDescription.La1) * 8) << "\n";

		std::cout << "Lo1: " << ((m_GridDescription.Lo1[0] & 128) ? "west " : "east ");
		m_GridDescription.Lo1[0] = m_GridDescription.Lo1[0] & 127;
		std::cout << ToIntFromBytes(m_GridDescription.Lo1, sizeof(m_GridDescription.Lo1) * 8) << "\n";

		std::cout << "La2: " << ((m_GridDescription.La2[0] & 128) ? "south " : "north ");
		m_GridDescription.La2[0] = m_GridDescription.La2[0] & 127;
		std::cout << ToIntFromBytes(m_GridDescription.La2, sizeof(m_GridDescription.La2) * 8) << "\n";

		std::cout << "Lo2: " << ((m_GridDescription.Lo2[0] & 128) ? "west " : "east ");
		m_GridDescription.Lo2[0] = m_GridDescription.Lo2[0] & 127;
		std::cout << ToIntFromBytes(m_GridDescription.Lo2, sizeof(m_GridDescription.Lo2) * 8) << "\n";
	}
}
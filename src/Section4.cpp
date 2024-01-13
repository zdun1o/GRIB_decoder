#include "Section4.h"

Section4::Section4(int factor) 
	:m_Dfactor(factor)
{
}

void Section4::Read(std::vector<char> data, int& offset) {

	std::memcpy(m_LengthBDS, data.data() + offset, 14);
	offset += 14;

	m_Rest.resize(ToIntFromBytes(m_LengthBDS, sizeof(m_LengthBDS) * 8) - 14);
	std::memcpy(m_Rest.data(), data.data() + offset, m_Rest.size());
	offset += m_Rest.size();

	float_or_int = (m_FlagBits[0] >> 5 & 1) ? 1 : 0;
	octed_14 = (m_FlagBits[0] >> 4 & 1) ? 1 : 0;
}

void Section4::ShowSection() {
	std::cout << "----- SECTION 4 -----\n";
	std::cout << "Length: " << ToIntFromBytes(m_LengthBDS, sizeof(m_LengthBDS) * 8) << "\n\n";

	std::cout << ((m_FlagBits[0] >> 7 & 1) ? "Grid point data" : "Spherical Harmonic Coefficients") << "\n";
	std::cout << ((m_FlagBits[0] >> 6 & 1) ? "Simple packing" : "Second order packing") << "\n";
	std::cout << ((m_FlagBits[0] >> 5 & 1) ? "Floating points values" : "Integer values") << "\n\n";

	SetFactors();
	ReadValue();
}

void Section4::SetFactors() {
	int sign = (m_ScaleFactor[0] & 128) ? -1 : 1;
	int num = (m_ScaleFactor[0] & 127) << 8 | m_ScaleFactor[1];
	m_Efactor = sign * num;

	m_Rfactor = binaryToFloat(m_Value);

	std::cout << "D scale factor: " << m_Dfactor << "\n";
	std::cout << "E scale factor: " << m_Efactor << "\n";
	std::cout << "R scale factor: " << m_Rfactor << "\n\n";
}

void Section4::ReadValue() {
	int x = m_Rest[0] << 2 | (m_Rest[1] >> 6) & 3;
	std::cout << "first x: " << (m_Rfactor + (x * pow(2, m_Efactor))) / pow(10, m_Dfactor) << std::endl;

}
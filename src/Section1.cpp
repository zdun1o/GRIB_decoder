#include "Section1.h"

Section1::Section1(bool* state1, bool* state2, int* factor)
	:GDS_state(state1), BMS_state(state2), m_factor(factor)
{
}

Section1::~Section1()
{
	if (GDS_state) delete GDS_state;
	if (BMS_state) delete BMS_state;
	if (m_factor) delete m_factor;
}

void Section1::Read(std::vector<char> data, int& offset) {
	std::memcpy(m_LengthPDS, data.data() + offset, 28);
	offset += 28;

	SetState();
	SetFactor();
}

void Section1::ShowSection() {
	int year = ToIntFromBytes(m_Year, sizeof(m_Year) * 8);
	int month = ToIntFromBytes(m_Month, sizeof(m_Month) * 8);
	int day = ToIntFromBytes(m_Day, sizeof(m_Day) * 8);
	int hour = ToIntFromBytes(m_Hour, sizeof(m_Hour) * 8);
	int minute = ToIntFromBytes(m_Minute, sizeof(m_Minute) * 8);

	std::cout << "----- SECTION 1 -----\n";
	std::cout << "Length: " << ToIntFromBytes(m_LengthPDS, sizeof(m_LengthPDS) * 8) << "\n";
	std::cout << "Date: " << year << "-" << month << "-" << day << "  " << hour << ":" << minute << "\n";
	std::cout << ((*GDS_state) ? "GDS: Included" : "GDS: Ommited") << "   " << ((*BMS_state) ? "BMS: Included" : "BMS: Ommited") << "\n";
}

void Section1::SetState() {
	*GDS_state = (m_GdsBms[0] >> 7 & 1) ? true : false;
	*BMS_state = (m_GdsBms[0] >> 6 & 1) ? true : false;
}

void Section1::SetFactor() {
	int sign = (m_ScaleFactor[0] & 128) ? -1 : 1;
	int num = (m_ScaleFactor[0] & 127) << 8 | m_ScaleFactor[1];
	*m_factor = sign * num;
}
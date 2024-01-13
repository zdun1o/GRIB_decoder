#pragma once

#include "Base.h"

class Section3 : public Base {
protected:
	bool BMS_state;
private:
	char m_LengthBMS[3];
	char m_unusedBits[1];
	char m_Numeric[2];
	std::vector <char> m_BitMap;
public:
	Section3() {}
	Section3(bool state);
	~Section3() {}

	virtual void Read(std::vector<char> data, int& offset);
	virtual void ShowSection();
};
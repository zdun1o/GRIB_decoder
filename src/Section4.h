#pragma once

#include "Base.h"

class Section4 : public Base {
protected:
	bool float_or_int, octed_14;
	int m_Dfactor, m_Efactor;
	float m_Rfactor;
private:
	char m_LengthBDS[3];
	char m_FlagBits[1];
	char m_ScaleFactor[2];
	char m_Value[4];
	char m_PointPacked[1];
	char m_Var[2];
	char m_flag_to_octed_4[1];
	std::vector <char> m_Rest;
public:
	Section4() {}
	Section4(int factor);
	~Section4() {}

	virtual void Read(std::vector<char> data, int& offset);
	virtual void ShowSection();

	void SetFactors();
	void ReadValue();
};
#pragma once

#include "Base.h"

class Section0 : public Base{
private:
	char m_Begin[4];
	char m_Length[3];
	char m_EditionNumber[1];
public:
	Section0() {}
	~Section0() {}

	virtual void Read(std::vector<char> data, int& offset);
	virtual void ShowSection();
};
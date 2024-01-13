#pragma once

#include "Base.h"

class Section5 : public Base {
private:
	char m_End[4];
public:
	Section5() {}
	~Section5() {}

	virtual void Read(std::vector<char> data, int& offset);
	virtual void ShowSection();
};
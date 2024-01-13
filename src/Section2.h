#pragma once

#include "Base.h"

struct La_Lo {
	char Ni[2];
	char Nj[2];
	char La1[3];
	char Lo1[3];
	char Res[1];
	char La2[3];
	char Lo2[3];
	char Di[2];
	char Dj[2];
	char ScanMode[1];
	char rest[4];
};

class Section2 : public Base {
protected:
	bool GDS_state;
private:
	char m_LengthGDS[3];
	char m_NV[1];
	char m_PVPL[1];
	char m_DataType[1];
	La_Lo m_GridDescription;
	std::vector <char> m_PVPL_list;
public:
	Section2() {}
	Section2(bool state);
	~Section2() {}

	virtual void Read(std::vector<char> data, int& offset);
	virtual void ShowSection();
};
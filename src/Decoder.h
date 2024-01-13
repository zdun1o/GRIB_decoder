#pragma once

#include <vector>
#include <fstream>

#include "Base.h"
#include "Section0.h"
#include "Section1.h"
#include "Section2.h"
#include "Section3.h"
#include "Section4.h"
#include "Section5.h"

class Decoder {
private:
	std::vector <char> m_FullMess;
	int m_Offset;
	bool GdsState, BmsState, goodPath;
	int D_factor;

	Base* base;

public:
	Decoder();
	~Decoder();

	void ReadGribFile(const char* f_path);
	void Decode();
};
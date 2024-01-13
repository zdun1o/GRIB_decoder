#include "Decoder.h"

Decoder::Decoder()
	:m_Offset(0), base(nullptr), goodPath(false)
{
}

Decoder::~Decoder()
{
	if (base) delete base;
}

void Decoder::ReadGribFile(const char* f_path)
{
	std::ifstream file(f_path, std::ios::binary | std::ios::in);
	if (file.is_open()) {
		goodPath = true;
		char tmp[1];
		while (!file.eof()) {
			file.read(tmp, 1);
			m_FullMess.push_back(tmp[0]);
		}
		file.close();
	}
	else "Podano zla nazwe pliku\n";
}

void Decoder::Decode()
{
	if (goodPath) {
		base = new Section0();
		base->Read(m_FullMess, m_Offset);
		base->ShowSection();

		base = new Section1(&GdsState, &BmsState, &D_factor);
		base->Read(m_FullMess, m_Offset);
		base->ShowSection();

		base = new Section2(GdsState);
		base->Read(m_FullMess, m_Offset);
		base->ShowSection();

		base = new Section3(BmsState);
		base->Read(m_FullMess, m_Offset);
		base->ShowSection();

		base = new Section4(D_factor);
		base->Read(m_FullMess, m_Offset);
		base->ShowSection();

		base = new Section5();
		base->Read(m_FullMess, m_Offset);
		base->ShowSection();
	}
}


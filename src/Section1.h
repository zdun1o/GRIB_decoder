#pragma once

#include "Base.h"

class Section1 : public Base {
private:
	char m_LengthPDS[3];          // 1-3
	char m_PDVnumber[1];          // 4
	char m_CenterID[1];           // 5
	char m_ProcessID[1];          // 6
	char m_GridID[1];			  // 7
	char m_GdsBms[1];             // 8
	char m_IndicatorParam[1];     // 9
	char m_IndicatorLevel[1];     // 10
	char m_HeightPress[2];        // 11-12
	char m_Year[1];               // 13
	char m_Month[1];              // 14
	char m_Day[1];                // 15
	char m_Hour[1];               // 16
	char m_Minute[1];             // 17
	char m_Forecast[1];           // 18
	char m_P1[1];                 // 19
	char m_P2[1];                 // 20
	char m_TimeRange[1];          // 21
	char m_NumberIncluded[2];     // 22-23
	char m_NumberMissing[1];      // 24
	char m_Century[1];            // 25
	char m_SubcenterID[1];        // 26
	char m_ScaleFactor[2];        // 27-28
public:
	Section1() {}
	Section1(bool* state1, bool* state2, int* factor);
	virtual ~Section1();

	virtual void Read(std::vector<char> data, int& offset);
	virtual void ShowSection();
protected:
	bool* GDS_state, *BMS_state;
	int* m_factor;
	void SetState();
	void SetFactor();
};
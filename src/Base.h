#pragma once

#include <vector>
#include <iostream>

class Base {
public:
	Base() {}
	~Base() {}

	virtual void Read(std::vector<char> data, int& offset) = 0;
	virtual void ShowSection() = 0;
protected:
	int ToIntFromBytes(char* tmp, int bits);
	float binaryToFloat(char* pass_in);
};
#pragma once

#include "MyLib.h"
#include <iostream>
#include <sstream>

class EXT_MYLIB Vctr
{
private:
	double m_x, m_y, m_z;

public:
	Vctr();
	Vctr(double i, double j, double k);
	~Vctr();

	std::string to_string() const
	{
		std::ostringstream os;
		os << "(" << m_x << ", " << m_y << ", " << m_z << ")";
		return os.str();
	}

    friend EXT_MYLIB std::ostream& operator<< (std::ostream& os, const Vctr& v);
};



#include "pch.h"
#include "Vctr.h"

EXT_MYLIB Vctr::Vctr() {

}

EXT_MYLIB Vctr::~Vctr() {

}

EXT_MYLIB Vctr::Vctr(double x, double y, double z)
	:m_x(x), m_y(y), m_z(z){

}

EXT_MYLIB std::ostream& operator<< (std::ostream& os, const Vctr& v) {
	os << v.to_string();
	return os;
}


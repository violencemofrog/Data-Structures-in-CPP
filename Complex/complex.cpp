// complex.cpp
//复数实现

#include "complex.h"

//复数加法实现
inline complex& _doapl(complex* ths,const complex& c) {
	ths->re+=c.re;
	ths->im+=c.im;
	return *ths;
}

//返回实部
inline double complex::real() const {
	return re;
}

//设置实部
inline void complex::real(const double& r) {
	re=r;
}

//返回虚部
inline double complex::imag() const {
	return im;
}

//设置虚部
inline void complex::imag(const double& i) {
	im=i;
}

//+=运算符重载
inline complex& complex::operator+=(const complex& c) {
	return _doapl(this,c);
}

//得到实部
double real(const complex& c) {
	return c.real();
}

//得到虚部
double imag(const complex& c) {
	return c.imag();
}

//+重载（复数+复数）
complex operator+(const complex& c1,const complex& c2) {
	return complex(real(c1)+real(c2),imag(c1)+imag(c2));
}

//+重载（实数+复数）
complex operator+(const double& d,const complex& c) {
	return complex(real(c)+d,imag(c));
}

//+重载（复数+实数）
complex operator+(const complex& c,const double& d) {
	return complex(real(c)+d,imag(c));
}

//+重载（正号）
inline complex operator+(const complex& c) {
	return c;
}

//-重载（负号）
inline complex operator-(const complex& c) {
	return complex(-real(c),-imag(c));
}

//==重载（复数比较复数）
inline bool operator==(const complex& c1,const complex& c2) {
	return real(c1)==real(c2)&&imag(c1)==imag(c2);
}

//==重载（实数比较复数）
inline bool operator==(const double& d,const complex& c) {
	return imag(c)==0&&real(c)==d;
}

//==重载（复数比较实数） 
inline bool operator==(const complex& c,const double& d) {
	return imag(c)==0&&real(c)==d;
}

//共轭复数
inline complex conj(const complex& c) {
	return complex(real(c),-imag(c));
}

//输出
ostream& operator<<(ostream& os,const complex& c) {
	return os << '(' << real(c) << ',' << imag(c) << ')';
}
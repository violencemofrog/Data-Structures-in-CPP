// complex.h
//复数

#pragma once

#include <cmath>
#include <iostream>
using namespace std;

class complex {
	private:
		double re,im;//实部，虚部
		friend complex& _doapl(complex*,const complex&);

	public:
		complex(double r=0,double i=0):re(r),im(i){};//构造函数
		double real()const;//返回实部
		void real(const double&);//设置实部
		double imag()const;//返回虚部
		void imag(const double&);//设置虚部

		complex& operator+=(const complex&);
};

inline double real(const complex&);//得到实部
inline double imag(const complex&);//得到虚部
inline complex operator+(const complex&,const complex&);
inline complex operator+(const double&,const complex&);
inline complex operator+(const complex&,const double&);
inline complex operator+(const complex&);
inline complex operator-(const complex&);
inline bool operator==(const complex&,const complex&);
inline bool operator==(const double&,const complex&);
inline bool operator==(const complex&,const double&);
inline complex conj(const complex&);
ostream& operator<<(ostream&,const complex&);

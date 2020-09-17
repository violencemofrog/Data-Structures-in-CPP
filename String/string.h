// mstring.h

#pragma once
#include <cstring>
#include <iostream>

class mstring {
	private:
		char* m_data;
	public:
		mstring(const char* cstr=0);//构造函数 
		mstring(const mstring& str);//拷贝构造
		mstring& operator=(const mstring&);//拷贝函数
		~mstring();//析构函数
		char* get_c_str() const {return m_data;}
};

//构造函数
inline mstring::mstring(const char* cstr=0) {
	if(cstr) {
		m_data=new char[strlen(cstr)+1];
		strcpy(m_data,cstr);
	}
	else {
		m_data=new char[1];
		*m_data='\0';
	}
}

//拷贝构造函数
inline mstring::mstring(const mstring& str) {
	m_data=new char[strlen(str.m_data)+1];
	strcpy(m_data,str.m_data);
}

//拷贝赋值
inline mstring& mstring::operator=(const mstring& str) {
	if(this==&str)//检验是否为自我赋值
		return *this;
	else {
		delete[] m_data;
		m_data=new char[strlen(str.m_data)+1];
		strcpy(m_data,str.m_data);
		return *this;
	}
}


//析构函数
inline mstring::~mstring() {
	delete[] m_data;
}

using namespace std;
inline ostream& operator<<(ostream& os,const mstring& str) {
	os << str.get_c_str();
	return os;
}
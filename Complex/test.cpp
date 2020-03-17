// test.cpp

#include "complex.h"
#include "complex.cpp"


void print(int i,const complex& c) {
	cout << "num" << i << c << endl;
}

int main(void) {
	complex num1,num2(2.2,1.6);
	print(1,num1);print(2,num2);
	num1+=num2;
	print(1,num1);print(2,num2);
	num1=conj(num1);
	print(1,num1);print(2,num2);
	return 0;
}
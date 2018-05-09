#include <iostream>


template<typename T>
class Complex
{
	T re, im;
public:
	Complex(T r, T i) : re(r), im(i) {}
};

void testfunc()
{
	Complex<int> c1(1, 2);
//	Complex<double> c2(1.1, 2.2);
}
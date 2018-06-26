#include <iostream>
using namespace std;

template<int N> struct check {};

// constexpr 함수 - c++11
constexpr int add(int a, int b)
{
	return a + b;
}

int main()
{
	int n = add(1, 2);
	check< add(1, 2) > c;	// ok.. ( 컴파일 타임에 계산됨)

	int n1 = 1, n2 = 2;
	int aa = add(n1, n2);	// ok.. ( 런타임에 계산함)
	//check< add(n1, n2) > d;	// error
}
#include <iostream>
using namespace std;

template<typename T> struct xis_pointer
{
	//bool value = false; // 컴파일 타임 상수가 아님 
	//enum {value = false}; // 타입이 int로 처리되기에 아래 표현이 낫다.
	static constexpr bool value = false;
};

template<typename T> struct xis_pointer<T*>
{
	//enum { value = true };
	static constexpr bool value = true;
};

template<typename T> struct xis_pointer<T* const>
{
	//enum { value = true };
	static constexpr bool value = true;
};
template<typename T> struct xis_pointer<T* volatile>
{
	//enum { value = true };
	static constexpr bool value = true;
};
template<typename T> struct xis_pointer<T* const volatile>
{
	//enum { value = true };
	static constexpr bool value = true;
};


// 핵심개념
// 1. if문은 실행 시간 조건문이다. 컴파일 시간에 조건이 false로 결정되어도,
//    if문의 코드는 컴파일 된다.
template<typename T> void printv(T v)
{
	//if (xis_pointer<T>::value)	// if (false)
	//	cout << v << " : " << *v << endl;
	//else
	//	cout << v << endl;

	// c++17 에서 동작 - vs2017에서는 아직 지원안함.
	// false일때 컴파일을 하지 않음.
	if constexpr (xis_pointer<T>::value)
		cout << v << " : " << *v << endl;
	else
		cout << v << endl;
}

int main()
{
	int n = 3;
	printv(n);	// error
	//printv(&n);
}
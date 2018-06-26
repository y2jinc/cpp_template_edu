#include <iostream>
using namespace std;

// type traits 개념
// 1. 컴파일 시간에 타입에 대한 정보를 얻거나 변형된 타입을 얻을 때 사용하는 도구(메타 함수)
// 2. <type_taits> 헤더로 제공됨 (since C++11)

// type query를 위한 type traits 만드는 일반적인 방법
// 1. primary template 에서 false 리턴 (value = false)
// 2. partial specialization 에서 true 리턴 (value = true)

template<typename T> struct xis_pointer
{
	enum { value = false };
};

// 핵심 : 포인터 타입에 대해서 부분 특수화.!
template<typename T> struct xis_pointer<T*>
{
	enum { value = true };
};

template<typename T> void foo(T v)
{
	if ( xis_pointer<T>::value )
		cout << "pointer" << endl;
	else
		cout << "not pointer" << endl;
}

int main()
{
	int		n = 3;
	
	foo(n);		// not pointer
	foo(&n);	// pointer
}
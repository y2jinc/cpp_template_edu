#include <iostream>
using namespace std;

// 변형 타입을 구하는 traits 만드는 방법
// 1. primary template 을 만들고 "typedef T type"을 제공한다.
//    (C++11 using도 사용 가능)
// 2. 부분 특수화를 통해서 원하는 타입을 얻을 수 있도록 "T 타입을 분할" 한다.

template<typename T> 
struct xremove_pointer
{
	typedef T type;
};

// 부분특수화로 가능.
template<typename T>
struct xremove_pointer<T*>
{
	typedef T type;
};


template<typename T> void foo(T a)
{
	//						<int*>::type
	typename xremove_pointer<T>::type t;

	cout << typeid(t).name() << endl;
}

int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}
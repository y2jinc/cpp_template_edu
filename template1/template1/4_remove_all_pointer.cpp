#include <iostream>
using namespace std;

// 개념
// 1. 재귀 표현식을 사용해서 임의의 타입에서 모든 포인터를 제거하는 기술
// 

template<typename T>
struct xremove_pointer
{
	typedef T type;
};

template<typename T>
struct xremove_pointer<T*>
{
	typedef T type;
};

// xremove_all_pointer은 표준에는 없다.
template<typename T>
struct xremove_all_pointer
{
	typedef T type;
};

template<typename T>
struct xremove_all_pointer<T*>
{
	typedef typename xremove_all_pointer<T>::type type; // typename 붙이는 부분 유의
};

int main()
{
	xremove_pointer<int*>::type a; // int
	xremove_pointer<int**>::type b; // int*
	xremove_all_pointer<int**>::type c; // int
	xremove_all_pointer<int***>::type d; // int

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
}
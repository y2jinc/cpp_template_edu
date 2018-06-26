#include <iostream>
using namespace std;

// 1. type
// 2. 값(non-type)
// 3. template

template<typename T, int N> struct Stack
{
	T buff[N];
};

// 1. type parameter
template<typename T> class List
{};


// 2. non-type(값) parameter

// 1) 정수형 상수
template<int N> class Test1
{};

// 2) enum 상수
enum Color {red = 1, green = 2};
template<Color> class Test2 {};

// 3) 포인터 : 지역 변수 주소는 안됨.. 전역 변수 주소는 가능.
//			   no linkage 를 가지는 변수 주소는 안됨...
template<int*> class Test3 {};

int x = 0;

// 4) 함수 포인터
template<int(*)(void)> class Test4 {};

// 5) 멤버 함수 포인터

//  6) c++17 : auto ->> g++ 현재 에서만 가능
//     g++ xxx.cpp -std=c++1z
//     xxx | c++filt -t    // 타입을 정상적으로 표시.

//template<auto N> struct Test6
//{
//	Test6()
//	{
//		cout << typeid(N).name() << endl;
//	}
//};

int main()
{
	Stack<int, 10> s;

	Test1<10> t1;		// ok

	//int n = 10;
	//Test1<n> t1;		// error

	Test2<red> t3;		// ok

	//Test3<&n> t4;		// error
	Test3<&x> t5;		// ok

	Test4<&main> t6;	// ok

	// g++ 에서 가능
	//Test6<10> t1; // N : int의 값
	//Test6<&x> t2; // N : int* 의 값
	//Test6<&main> t3;

	return 0;
}
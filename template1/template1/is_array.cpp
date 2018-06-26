#include <iostream>
using namespace std;

// is_array 만들기
// 1. Primary template 에서는 false 리턴 (value=false)
// 2. 배열 모양으로 부분 특수화(partial specialization) 모양을 만들고 
//    true 리턴(value=true)
// 3. 타입을 정확히 알아야 한다.
//  - int x[3]; 에서 x는 변수이름, 변수 이름을 
//	  제외한 나머지 요소(int[3])는 타입이다.

// 배열의 크기도 구할수 있다.
//  - C++11 표준 - extent<T, 0>::value
// 함수 템플릿의 인자를 값(T)으로 만들 경우 배열을 전달하면 
// T의 타입은 배열이 아닌 포인터로 결정된다.

template<typename T> struct xis_array
{
	static constexpr bool value = false;
	static constexpr size_t size = -1;
};

// for fixed size array
template<typename T, size_t N> 
struct xis_array<T[N]>
{
	static constexpr bool value = true;
	static constexpr size_t size = N;
};

// for unknown size array
template<typename T>
struct xis_array<T[]>
{
	static constexpr bool value = true;
};

template<typename T> void foo(T& a)	// 참조로 받아야만 배열을 온전히 받을수 있다.
{
	if (xis_array<T>::value)
	{

		cout << "array size : " << xis_array<T>::size << endl;
		cout << "array size : " << xis_array<T>::size << endl;
	}
	else
	{
		cout << "not array" << endl;
	}
		
}

int main()
{
	int x[3][2] = { 1,2,3,4,5,6 }; // 변수 이름 x	 타입 int[3]
						  //                  T[N]

	foo(x);
}
#include <iostream>
using namespace std;

template<int N>
struct int2type
{
	enum { value = N };
};

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


// 해결책
// 1. 동일한 이름ㅇ르 가지는 함수가 여러 개 있을 때, 어느 함수를 호출할지 결정하는
//    것은 컴파일 시간에 이루어진다. 선택되지 않은 함수가 템플릿이었다면
//    "instantiation" 되지 않는다.

// 이게 integral_constant로 c++11 표준으로 포함됨.

template<typename T> 
void printv_imp(T v, int2type<1>)
{
	cout << v << " : " << *v << endl;
}

template<typename T> 
void printv_imp(T v, int2type<0>)
{
	cout << v << endl;
}

template<typename T> void printv(T v)
{
	printv_imp(v, int2type<xis_pointer<T>::value>() );
						// int2type<1>(), int2type<0>()
						// 포인터 : 1
					    // 포인터 아님 : 0
}

int main()
{
	int n = 3;
	printv(n);	// ok
	printv(&n);
}
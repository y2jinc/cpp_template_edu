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


// if constexpr 사용 하지않고 해결

// 1. if 문은 실행 시간 조건 문이다.
//    컴파일 시간에 조건이 false로 결정되어도,
//	  if문의 안에서 호출한 함수 템플릿은 "template instantiation"된다.
// 2. if문과 같은 실행시간 조건 분기문이 아닌 "컴파일 시간 분기문"이 필요하다.

template<typename T> void printv_pointer(T v)
{
	cout << v << " : " << *v << endl;
}

template<typename T> void printv_not_pointer(T v)
{
	cout << v << endl;
}

template<typename T> void printv(T v)
{
	if (xis_pointer<T>::value) // if (false)
		printv_pointer(v);
	else
		printv_not_pointer(v);
}

int main()
{
	int n = 3;
	printv(n);	// error
	//printv(&n);
}
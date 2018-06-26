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

int main()
{
	cout << xis_pointer<int>::value << endl;
	cout << xis_pointer<int*>::value << endl;
	cout << xis_pointer<int* const>::value << endl;
	cout << xis_pointer<int* volatile>::value << endl;
	cout << xis_pointer<int* const volatile>::value << endl;
	cout << xis_pointer<int* volatile const>::value << endl;

	return 0;
}

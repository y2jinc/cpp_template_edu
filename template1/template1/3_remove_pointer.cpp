#include <iostream>
using namespace std;

// xis_pointer 와 xremove_pointer를 비교해보자.
// xis_pointer는 value xremove_pointer는 타입을 사용.
// xremove_pointer 타입 사용시 typename을 앞에 써준다.

template<typename T>
struct xis_pointer
{
	static constexpr bool value = false;
};

template<typename T>
struct xis_pointer<T*>
{
	static constexpr bool value = true;
};

template<typename T>
struct xis_pointer<T* const>
{
	static constexpr bool value = true;
};

template<typename T>
struct xis_pointer<T* volatile>
{
	static constexpr bool value = true;
};

template<typename T>
struct xis_pointer<T* const volatile>
{
	static constexpr bool value = true;
};

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

template<typename T>
struct xremove_pointer<T* const>
{
	typedef T type;
};

template<typename T>
struct xremove_pointer<T* volatile>
{
	typedef T type;
};

template<typename T>
struct xremove_pointer<T* const volatile>
{
	typedef T type;
};

template<typename T> void foo(T a)
{	
	// typename 적어야 함. 주의!!
	typename xremove_pointer<T>::type t;
}

template<typename T> void foo_ispointer(T a)
{
	bool b = xis_pointer<T>::value;
}

int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}
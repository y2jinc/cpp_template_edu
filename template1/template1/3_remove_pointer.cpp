#include <iostream>
using namespace std;

// xis_pointer �� xremove_pointer�� ���غ���.
// xis_pointer�� value xremove_pointer�� Ÿ���� ���.
// xremove_pointer Ÿ�� ���� typename�� �տ� ���ش�.

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

// �κ�Ư��ȭ�� ����.
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
	// typename ����� ��. ����!!
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
#include <iostream>
using namespace std;

template<typename T> struct xis_pointer
{
	//bool value = false; // ������ Ÿ�� ����� �ƴ� 
	//enum {value = false}; // Ÿ���� int�� ó���Ǳ⿡ �Ʒ� ǥ���� ����.
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


// �ٽɰ���
// 1. if���� ���� �ð� ���ǹ��̴�. ������ �ð��� ������ false�� �����Ǿ,
//    if���� �ڵ�� ������ �ȴ�.
template<typename T> void printv(T v)
{
	//if (xis_pointer<T>::value)	// if (false)
	//	cout << v << " : " << *v << endl;
	//else
	//	cout << v << endl;

	// c++17 ���� ���� - vs2017������ ���� ��������.
	// false�϶� �������� ���� ����.
	if constexpr (xis_pointer<T>::value)
		cout << v << " : " << *v << endl;
	else
		cout << v << endl;
}

int main()
{
	int n = 3;
	printv(n);	// error
	//printv(&n);
}
#include <iostream>
using namespace std;

template<int N>
struct int2type
{
	enum { value = N };
};

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


// �ذ�å
// 1. ������ �̸����� ������ �Լ��� ���� �� ���� ��, ��� �Լ��� ȣ������ �����ϴ�
//    ���� ������ �ð��� �̷������. ���õ��� ���� �Լ��� ���ø��̾��ٸ�
//    "instantiation" ���� �ʴ´�.

// �̰� integral_constant�� c++11 ǥ������ ���Ե�.

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
						// ������ : 1
					    // ������ �ƴ� : 0
}

int main()
{
	int n = 3;
	printv(n);	// ok
	printv(&n);
}
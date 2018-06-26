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


// if constexpr ��� �����ʰ� �ذ�

// 1. if ���� ���� �ð� ���� ���̴�.
//    ������ �ð��� ������ false�� �����Ǿ,
//	  if���� �ȿ��� ȣ���� �Լ� ���ø��� "template instantiation"�ȴ�.
// 2. if���� ���� ����ð� ���� �б⹮�� �ƴ� "������ �ð� �б⹮"�� �ʿ��ϴ�.

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
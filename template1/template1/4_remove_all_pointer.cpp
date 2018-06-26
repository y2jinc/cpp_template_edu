#include <iostream>
using namespace std;

// ����
// 1. ��� ǥ������ ����ؼ� ������ Ÿ�Կ��� ��� �����͸� �����ϴ� ���
// 

template<typename T>
struct xremove_pointer
{
	typedef T type;
};

template<typename T>
struct xremove_pointer<T*>
{
	typedef T type;
};

// xremove_all_pointer�� ǥ�ؿ��� ����.
template<typename T>
struct xremove_all_pointer
{
	typedef T type;
};

template<typename T>
struct xremove_all_pointer<T*>
{
	typedef typename xremove_all_pointer<T>::type type; // typename ���̴� �κ� ����
};

int main()
{
	xremove_pointer<int*>::type a; // int
	xremove_pointer<int**>::type b; // int*
	xremove_all_pointer<int**>::type c; // int
	xremove_all_pointer<int***>::type d; // int

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
}
#include <iostream>
using namespace std;

// ���� Ÿ���� ���ϴ� traits ����� ���
// 1. primary template �� ����� "typedef T type"�� �����Ѵ�.
//    (C++11 using�� ��� ����)
// 2. �κ� Ư��ȭ�� ���ؼ� ���ϴ� Ÿ���� ���� �� �ֵ��� "T Ÿ���� ����" �Ѵ�.

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


template<typename T> void foo(T a)
{
	//						<int*>::type
	typename xremove_pointer<T>::type t;

	cout << typeid(t).name() << endl;
}

int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}
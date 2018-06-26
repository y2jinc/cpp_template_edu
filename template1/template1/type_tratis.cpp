#include <iostream>
using namespace std;

// type traits ����
// 1. ������ �ð��� Ÿ�Կ� ���� ������ ��ų� ������ Ÿ���� ���� �� ����ϴ� ����(��Ÿ �Լ�)
// 2. <type_taits> ����� ������ (since C++11)

// type query�� ���� type traits ����� �Ϲ����� ���
// 1. primary template ���� false ���� (value = false)
// 2. partial specialization ���� true ���� (value = true)

template<typename T> struct xis_pointer
{
	enum { value = false };
};

// �ٽ� : ������ Ÿ�Կ� ���ؼ� �κ� Ư��ȭ.!
template<typename T> struct xis_pointer<T*>
{
	enum { value = true };
};

template<typename T> void foo(T v)
{
	if ( xis_pointer<T>::value )
		cout << "pointer" << endl;
	else
		cout << "not pointer" << endl;
}

int main()
{
	int		n = 3;
	
	foo(n);		// not pointer
	foo(&n);	// pointer
}
#include <iostream>
#include <type_traits>
using namespace std;

// ���ø��� ���鶧 Ÿ���� �����ϴ� ���.
// 1. <type_traits> ��� ����

// 2. ::value ���� �����ϴ� ���. (is_pointer<T>::value)
//	  - if�� ���ÿ��� *v ���� ǥ���� ����� �� ����.
//	  - C++17 �� if constexpr ���ÿ��� *v ����� �� �ִ�.
//	  - C++17 ���ʹ� is_pointer_v<T> ǥ���ĵ� ����

// 3. ture_type/false_type �� ����� �Լ� �����ε�

template<typename T> 
void foo_imp(T v, true_type)
{
	*v = 10;
}

template<typename T> 
void foo_imp(T v, false_type)
{

}

template<typename T> 
void foo(T v)
{
	// T �� ������ ���� �˰� �ʹ�.
	if (is_pointer<T>::value)
	{
		*v = 10;
	}
	else
	{

	}

	foo_imp(v, is_pointer<T>());
}

int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}
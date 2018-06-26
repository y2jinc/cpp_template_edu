#include <iostream>
#include <type_traits>
using namespace std;

// type traits ����

// 1. ������ Ÿ���� ��� traits
//   - typename remove_pointer<T>::type n;
//	 - remove_pointer_t<T> n;		--> C++14 ���� ����

// 2.Ÿ���� ������ �����ϴ� traits
//   - bool b = is_pointer<T>::value;
//	 - bool b = is_pointer_v<T>;	--> C++17 ���� ����
//	 - �Լ� �����ε� ���(true_type, false_type)

// C++14
template<typename T>
using xremove_pointer_t = typename remove_pointer<T>::type;


// variable template (C++17)
//inline constexpr bool is_pointer_v = is_pointer<T>::value;

void foo_imp(true_type) {}
void foo_imp(false_type) {}

template<typename T>
void foo(T a)
{
	// 1. ������ Ÿ�� ��� ���
	typename remove_pointer<T>::type n;
	xremove_pointer_t<T>	n2;	// ���� ������ �Ȱ���.(C++14 ���� ����)

	cout << typeid(n).name() << endl; // int
	cout << typeid(n2).name() << endl; // int

	// 2. Ÿ���� ������ �����ϴ� ���
	bool b = is_pointer<T>::value;
	//bool b2 = is_pointer_v<T>;

	if (is_pointer<T>::value)
	//if constexpr (is_pointer_v<T>) --> C++17
	{
		//cout << *a << endl;
	}

	foo_imp(is_pointer<T>());
}

int main()
{
	int n = 0;
	foo(&n);
}

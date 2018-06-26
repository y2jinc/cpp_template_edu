#include <iostream>
#include <type_traits>
using namespace std;

// type traits ���
// 1. type �� ���� query - is_p0ointer<>, is_array<>, extent<>
// 2. type �� ���� ���� Ÿ�� ���ϱ� - remove_pointer<>, add_pointer<>

// remove_pointer<>�� �����غ���.

template<typename T> void foo(T a)
{
	bool b = is_pointer<T>::value;
	typename remove_pointer<T>::type t;

	cout << typeid(t).name() << endl;
}

int main()
{
	int n = 0;
	foo(n);
	foo(&n);
}
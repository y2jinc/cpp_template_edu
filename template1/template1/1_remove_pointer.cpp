#include <iostream>
#include <type_traits>
using namespace std;

// type traits 기능
// 1. type 에 대한 query - is_p0ointer<>, is_array<>, extent<>
// 2. type 에 대한 변형 타입 구하기 - remove_pointer<>, add_pointer<>

// remove_pointer<>를 구현해보자.

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
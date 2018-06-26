#include <iostream>
#include <type_traits>
using namespace std;


// <type_traits>
// 예제				| C++ 표준
// xis_pointer		| is_pointer
// xis_array		| is_array
// 배열의 크기		| extent
// xremove_pointer	| remove_pointer
// result_type		| result_of / invoke_result 구현방식이 다름.

template<typename T> 
void foo(T a)
{
	typename remove_pointer<T>::type n;
	bool b = is_pointer<T>::value;
}

int main()
{
	int n = 0;
	foo(&n);
}

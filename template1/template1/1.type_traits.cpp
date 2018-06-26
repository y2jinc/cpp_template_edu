#include <iostream>
#include <type_traits>
using namespace std;


// <type_traits>
// ����				| C++ ǥ��
// xis_pointer		| is_pointer
// xis_array		| is_array
// �迭�� ũ��		| extent
// xremove_pointer	| remove_pointer
// result_type		| result_of / invoke_result ��������� �ٸ�.

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

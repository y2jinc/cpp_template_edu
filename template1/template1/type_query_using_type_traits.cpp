#include <iostream>
#include <type_traits>
using namespace std;

// 템플릿을 만들때 타입을 조사하는 방법.
// 1. <type_traits> 헤더 포함

// 2. ::value 값을 조사하는 방법. (is_pointer<T>::value)
//	  - if문 사용시에는 *v 등의 표현을 사용할 수 없다.
//	  - C++17 의 if constexpr 사용시에는 *v 사용할 수 있다.
//	  - C++17 부터는 is_pointer_v<T> 표현식도 제공

// 3. ture_type/false_type 을 사용한 함수 오버로딩

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
	// T 가 포인터 인지 알고 싶다.
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
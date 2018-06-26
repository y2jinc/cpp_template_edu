#include <iostream>
#include <type_traits>
using namespace std;

// type traits 사용법

// 1. 변형된 타입을 얻는 traits
//   - typename remove_pointer<T>::type n;
//	 - remove_pointer_t<T> n;		--> C++14 부터 지원

// 2.타입의 정보를 조사하는 traits
//   - bool b = is_pointer<T>::value;
//	 - bool b = is_pointer_v<T>;	--> C++17 부터 지원
//	 - 함수 오버로딩 사용(true_type, false_type)

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
	// 1. 변형된 타입 얻는 방법
	typename remove_pointer<T>::type n;
	xremove_pointer_t<T>	n2;	// 위의 구문과 똑같음.(C++14 부터 지원)

	cout << typeid(n).name() << endl; // int
	cout << typeid(n2).name() << endl; // int

	// 2. 타입의 정보를 조사하는 방법
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

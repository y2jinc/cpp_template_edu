#include <iostream>
#include <type_traits>
using namespace std;

// 참고.
//template<typename T>
//struct is_pointer : false_type
//{
//	// value = false;
//};
//
//template<typename T>
//struct is_pointer<T*> : true_type
//{
//	// value = true;
//};

// 개념
// 1. is_pointer<T> 에서
//   - T가 포인터가 아니면 value = false, 기반 클래스는 false_type
//	 - T가 포인터 라면 value = true, 기반 클래스는 true_type

// --> 객체의 타입이 아니라 객체를 생성(instance)해서 분류한다.

template<typename T>
void printv_imp(T v, true_type)
{
	cout << v << " : " << *v << endl;
}

template<typename T>
void printv_imp(T v, false_type)
{
	cout << v << endl;
}

template<typename T> 
void printv(T v)
{
	// 함수를 선택하기 위해서 is_pointer<T> 타입을 instance 함.
	printv_imp(v, is_pointer<T>()); 
}

int main()
{
	int n = 3;
	printv(n);
	printv(&n);
}
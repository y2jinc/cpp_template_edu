#include <iostream>
using namespace std;


template<typename T> struct Test
{
	static void foo() { cout << typeid(T).name() << endl; }
};

template<typename T> struct Test<T*>
{
	static void foo() { cout << typeid(T).name() << endl; }
};

template<typename T, int N = 10> struct Stack
{
	T buff[N];
};

// primaty template 에 적용된 default 값이 있다면
// 특수화에서는 대입할 수 사용할수 없다. (= 10 제거.)
// primary의 디폴트 값을 사용 하게 됨.
template<typename T, int N/* = 10*/> struct Stack<T*, N>
{
	T* buff[N];
};

int main()
{
	Test<int>::foo();	// int	
	Test<int*>::foo();	// int*가 아니고 int 임.

	Stack<int, 10>	s1;
	Stack<int>		s2; // N = 10
	Stack<int*>		s3; // N = 10
}
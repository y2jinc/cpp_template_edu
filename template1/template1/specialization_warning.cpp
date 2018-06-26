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

// primaty template �� ����� default ���� �ִٸ�
// Ư��ȭ������ ������ �� ����Ҽ� ����. (= 10 ����.)
// primary�� ����Ʈ ���� ��� �ϰ� ��.
template<typename T, int N/* = 10*/> struct Stack<T*, N>
{
	T* buff[N];
};

int main()
{
	Test<int>::foo();	// int	
	Test<int*>::foo();	// int*�� �ƴϰ� int ��.

	Stack<int, 10>	s1;
	Stack<int>		s2; // N = 10
	Stack<int*>		s3; // N = 10
}
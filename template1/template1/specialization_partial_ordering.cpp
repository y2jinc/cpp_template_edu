#include <iostream>
using namespace std;

// @order
// 1. specialization > partial specialization > primary template
// 2. 2�� �̻��� partial specialization ������ ��� ���� �� ��
//	  - The most specialized specization is used.

// primary template
template<typename T, typename U> struct order
{
	static void foo() { cout << "T, U" << endl; }
};

// partial specialization : T, T
template<typename T> struct order<T, T>
{
	static void foo() { cout << "T, T" << endl; }
};

// partial specialization : T*, T*
template<typename T> struct order<T*, T*>
{
	static void foo() { cout << "T*, T*" << endl; }
};

//// partial specialization : T*, int*
//template<typename T> struct order<T*, int*>
//{
//	static void foo() { cout << "T*, T*" << endl; }
//};

// specialization : int*, int*
template<> struct order<int*, int*>
{
	static void foo() { cout << "int*, int*" << endl; }
};


// primary template
// partial specialization : T, T
// partial specialization : T*, T*
// partial specialization : T*, int* -> ������ �ٸ���.

// specialization		  : int*, int*

int main()
{
	order<int*, int*>::foo();
}
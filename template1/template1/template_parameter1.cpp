#include <iostream>
using namespace std;

// 1. type
// 2. ��(non-type)
// 3. template

template<typename T, int N> struct Stack
{
	T buff[N];
};

// 1. type parameter
template<typename T> class List
{};


// 2. non-type(��) parameter

// 1) ������ ���
template<int N> class Test1
{};

// 2) enum ���
enum Color {red = 1, green = 2};
template<Color> class Test2 {};

// 3) ������ : ���� ���� �ּҴ� �ȵ�.. ���� ���� �ּҴ� ����.
//			   no linkage �� ������ ���� �ּҴ� �ȵ�...
template<int*> class Test3 {};

int x = 0;

// 4) �Լ� ������
template<int(*)(void)> class Test4 {};

// 5) ��� �Լ� ������

//  6) c++17 : auto ->> g++ ���� ������ ����
//     g++ xxx.cpp -std=c++1z
//     xxx | c++filt -t    // Ÿ���� ���������� ǥ��.

//template<auto N> struct Test6
//{
//	Test6()
//	{
//		cout << typeid(N).name() << endl;
//	}
//};

int main()
{
	Stack<int, 10> s;

	Test1<10> t1;		// ok

	//int n = 10;
	//Test1<n> t1;		// error

	Test2<red> t3;		// ok

	//Test3<&n> t4;		// error
	Test3<&x> t5;		// ok

	Test4<&main> t6;	// ok

	// g++ ���� ����
	//Test6<10> t1; // N : int�� ��
	//Test6<&x> t2; // N : int* �� ��
	//Test6<&main> t3;

	return 0;
}
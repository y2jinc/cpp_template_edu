#include <iostream>
using namespace std;

// @����
// 1. primary template �� ���ø� ���ڰ� 2�����, ����ڴ� �ݵ�� ���ø� ���ڸ�
//    2���� ���� �ؾ� �Ѵ�. (����Ʈ ���ڰ� ���ٸ�)
// 2. ������, �κ� Ư��ȭ(partial specialzation)������ ���� �� ���ø��� ������
//	  ������ Primary template �� ������ ������ �ٸ� �� �ִ�. ��, �κ� Ư��ȭ��
//	  ���𿡴� �ݵ�� ���ø� ���ڸ� 2�� �����ؾ� �Ѵ�.
// 3. ����� Partial specization �� ����� ����� �߿�.

template<typename T, typename U> struct Test
{
	static void foo() { cout << "T, U" << endl; }
};

template<typename T, typename U> struct Test<T*, U>
{
	static void foo() { cout << "T*, U" << endl; }
};

template<typename T, typename U> struct Test<T*, U*>
{
	static void foo() { cout << "T*, U*" << endl; }
};

// �ٽ� -> �κ� Ư��ȭ�� ������ �޶����� �ִ�.
template<typename T> struct Test<T, T> // ������ �ڿ��� Primary template Ÿ�� ���� ������ ���ƾ���.
{
	static void foo() { cout << "T, T" << endl; }
};

template<typename T> struct Test<int, T>
{
	static void foo() { cout << "int, T" << endl;	}
};

template<> struct Test<int, int>
{
	static void foo() { cout << "int, int" << endl; }
};

template<> struct Test<int, short>
{
	static void foo() { cout << "int, short" << endl; }
};

// ����� Partial specialization ����
template<typename T, typename U, typename V>
struct Test<T, Test<U,V>>
{
	static void foo() { cout << "T, Test<U,V>" << endl; }
};

int main()
{
	Test<int, double>::foo();	// T, U
	Test<int*, double>::foo();	// T*, U
	Test<int*, double*>::foo();	// T*, U*
	Test<int, int>::foo();		// T, T
	Test<int, char>::foo();		// int, U
	Test<int, short>::foo();	// int, short
	
	Test<double, Test<char, short>>::foo();	// T, Test<U,V>

	return 0;
}
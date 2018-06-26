#include <iostream>
using namespace std;

// �Լ��� ������ ���ϴ� traits �����
// 1. primary template�� ����� "typedef type"�� �����Ѵ�.(C++11 using �� ��� ����)
// 2. �κ� Ư��ȭ�� ���ؼ� ���ϴ� Ÿ���� ���� �� �ֵ��� "T Ÿ���� ����" �Ѵ�.
// 3. �κ� Ư��ȭ�� ���ؼ� �Լ� Ÿ��(double(short,int)) ����� T�� ���� Ÿ��(double)��
//    ������(����Ÿ��)�� �и� �Ѵ�.
//	  - T(double(short, int)) -> R(A1, A2)
// 4. primary template �� "typedef T type" �� �ʿ� ���� ���� �����ص� �ȴ�.

// ����
// 1. C++ 11 ǥ�ؿ��� �Լ��� ���� Ÿ���� ���ϱ�
//   - result_of(before C++17), invoke_result(since C++17)
//   - �������� ������ ��İ��� ���� �ٸ� ������� �����Ǿ� ����.
//	 - decltype ����ؼ� ����. (�Ϲ� �Լ�, �Լ� ��ü, ����ǥ���ĵ��� ��� callable object ���)

double hoo(short a, int b) { return 0; }

template<typename T, size_t N> 
struct argument_type
{
	//typedef T type;
};

/*
template<typename R, typename A1, typename A2, size_t N>
struct argument_type<R(A1, A2), N>
{
	typedef ? type;
};
*/

template<typename R, typename A1, typename A2>
struct argument_type<R(A1, A2), 0>
{
	typedef A1 type;
};

template<typename R, typename A1, typename A2>
struct argument_type<R(A1, A2), 1>
{
	typedef A2 type;
};

template<typename T>
void foo(T& t)
{
	// T : double (short, int)
	typename argument_type<T, 0>::type ret;
	cout << typeid(ret).name() << endl;
}

int main()
{
	foo(hoo);
	return 0;
}
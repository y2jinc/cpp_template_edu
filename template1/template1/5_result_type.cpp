#include <iostream>
using namespace std;

// �Լ��� ������ ���ϴ� traits �����
// 1. primary template�� ����� "typedef type"�� �����Ѵ�.(C++11 using �� ��� ����)
// 2. �κ� Ư��ȭ�� ���ؼ� ���ϴ� Ÿ���� ���� �� �ֵ��� "T Ÿ���� ����" �Ѵ�.
// 3. �κ� Ư��ȭ�� ���ؼ� �Լ� Ÿ��(double(short,int)) ����� T�� ���� Ÿ��(double)��
//    ������(����Ÿ��)�� �и� �Ѵ�.
//	  - T(double(short, int)) -> R(A1, A2)
// 4. primary template �� "typedef T type" �� �ʿ� ���� ���� �����ص� �ȴ�.

template<typename T>
struct result_type
{
	//typedef T type;	// �ǵ�ġ �ʰ� primary �� ������ �ʵ��� �ּ�ó��
};

// ���� Ÿ�Ը� �̵��� �κ� Ư��ȭ
template<typename R, typename A1, typename A2> 
struct result_type<R(A1, A2)>
{
	typedef R type;
};

double hoo(short a, int b) { return 0; }

template<typename T>
void foo(T& t)
{
	// T : double (short, int)
	typename result_type<T>::type ret;
	// typename result_type<int>::type ret; // error
	cout << typeid(ret).name() << endl;
}

int main()
{
	foo(hoo);	
	return 0;
}
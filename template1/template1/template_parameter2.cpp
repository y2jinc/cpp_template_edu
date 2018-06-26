#include <iostream>
using namespace std;

// 3. template parameter

template<typename T> class list {};

template<typename T, template<typename> class C> struct stack
{
	//C c;	// error, list c
	C<T> c; // ok.. list<int> c
};


// default parameter
template<typename T = int, int N = 10> struct stack1
{

};

// c++11 : �������� ���ø� -> ���߿� �ٷ��.
template<typename ... T> class Test {};
template<int ... T> class Test2 {};

int main()
{
	//list		s1;	// error. list�� Ÿ���� �ƴϰ� ���ø�
	list<int>	s2; // ok.	  list<int>�� Ÿ��

	stack<int, list> s3; // ok

	stack1<int, 10> d1;
	stack1<int> d2;
	stack1<> d3;	// ��� ���ڸ� ����Ʈ �� ���

	return 0;
}
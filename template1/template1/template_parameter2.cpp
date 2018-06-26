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

// c++11 : 가변인자 템플릿 -> 나중에 다룬다.
template<typename ... T> class Test {};
template<int ... T> class Test2 {};

int main()
{
	//list		s1;	// error. list는 타입은 아니고 템플릿
	list<int>	s2; // ok.	  list<int>는 타입

	stack<int, list> s3; // ok

	stack1<int, 10> d1;
	stack1<int> d2;
	stack1<> d3;	// 모든 인자를 디폴트 값 사용

	return 0;
}
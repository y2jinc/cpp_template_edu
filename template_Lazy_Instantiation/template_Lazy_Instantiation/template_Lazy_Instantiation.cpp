// template_Lazy_Instantiation.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


#include <iostream>
using namespace std;
//class A
//{
//	int data;
//public:
//	void foo(int n) { *n = 10; }	// error
//};

template<typename T>
class A
{
	T data;
public:
	void foo(T n) { *n = 10; }
};


struct Resource1
{
	Resource1() { cout << "Resource1()" << endl; }
	~Resource1() { cout << "~Resource1()" << endl; }
};

struct Resource2
{
	Resource2() { cout << "Resource2()" << endl; }
	~Resource2() { cout << "~Resource2()" << endl; }
};

/*
struct Test
{
	Resource1 res1;
	static Resource2 res2;
};
Resource2 Test::res2;		// 1. 생성자
*/

template<typename T>
struct Test
{
	Resource1 res1;
	static Resource2 res2;
};
template<typename T> Resource2 Test<T>::res2;	

// @remark : 템플릿 클래스에서 static 멤버 변수는 사용하지 않으면 인스턴스 되지 않는다.

int main()
{
	//A<int> a;
	//a.foo(0);

	cout << "main" << endl;
	Test<int> t;					// 
	t.res2;							// 이 부분을 사용해야만 resource2가 생성됨.

	return 0;
}
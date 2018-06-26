#include <iostream>
using namespace std;

// @정리
// 1. primary template 의 템플릿 인자가 2개라면, 사용자는 반드시 템플릿 인자를
//    2개를 전달 해야 한다. (디폴트 인자가 없다면)
// 2. 하지만, 부분 특수화(partial specialzation)버전을 만들 때 템플릿의 인자의
//	  개수는 Primary template 의 인자의 개수와 다를 수 있다. 단, 부분 특수화의
//	  선언에는 반드시 템플릿 인자를 2개 전달해야 한다.
// 3. 재귀적 Partial specization 을 만드는 모양이 중요.

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

// 핵심 -> 부분 특수화시 개수가 달라질수 있다.
template<typename T> struct Test<T, T> // 하지만 뒤에는 Primary template 타입 인자 개수가 같아야함.
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

// 재귀적 Partial specialization 형식
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
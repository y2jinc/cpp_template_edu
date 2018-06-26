#include <iostream>
using namespace std;

// 1. 함수 오버 로딩은 인자의 개수가 다르거나, 인자의 타입이 다를 때 사용
// 2. 인자의 개수와 타입이 동일 할 때, 인자의 값 만으로는 오버로딩 할 수 없다.

// int2type 개념
// 1. 컴파일 시간 정수형 상수를 각각의 독립된 타입으로 만드는 도구.
// 2. int2type을 사용하면"컴파일 시간에 결정된 정수형 상수"를
//    모두 다른 타입으로 만들 수 있다.(77, 78은 같은 타입 이지만, int2type<77>,
//	  int2type<78>은 다른 타입이다.)
// 3. int2type을 사용하면 "컴파일 시간에 결정된 정수형 상수"를 가지고 함수 
//    오버로딩에 사용하거나, 템플릿 인자, 상속 등에서 사용할수 있다.

// 핵심 코드
template<int N> 
struct int2type
{
	enum { value = N };
};

void foo(int n)		{}
void foo(double d)	{}

template<typename T>
void foo(T a) {}

int main()
{
	foo(3);		// foo(int)
	foo(3.4);	// foo(double)

	// 아래의 코드가 각각 다른 함수를 
	// 호출하게 할수 없을까?
	foo(0);
	foo(1);	// 0, 1은 같은 타입
			// foo(0), foo(1)은 같은 함수 호출.

	int2type<0> t0;	// struct int2type<0>
	int2type<1> t1; // struct int2type<1>	t0와 t1은 다른 타입

	foo(t0);
	foo(t1); // t0와 t1은 다른 타입 이므로
			 // foo(t0), foo(t1)은 다른 함수 호출.
}
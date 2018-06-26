#include <iostream>
using namespace std;

// 함수의 정보를 구하는 traits 만들기
// 1. primary template을 만들고 "typedef type"을 제공한다.(C++11 using 도 사용 가능)
// 2. 부분 특수화를 통해서 원하는 타입을 얻을 수 있도록 "T 타입을 분할" 한다.
// 3. 부분 특수화를 통해서 함수 타입(double(short,int)) 모양인 T를 리턴 타입(double)과
//    나머지(인자타입)로 분리 한다.
//	  - T(double(short, int)) -> R(A1, A2)
// 4. primary template 의 "typedef T type" 이 필요 없는 경우는 제거해도 된다.

template<typename T>
struct result_type
{
	//typedef T type;	// 의도치 않게 primary 가 사용되지 않도록 주석처리
};

// 리턴 타입만 뽑도록 부분 특수화
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
#include <iostream>
using namespace std;

// 함수의 정보를 구하는 traits 만들기
// 1. primary template을 만들고 "typedef type"을 제공한다.(C++11 using 도 사용 가능)
// 2. 부분 특수화를 통해서 원하는 타입을 얻을 수 있도록 "T 타입을 분할" 한다.
// 3. 부분 특수화를 통해서 함수 타입(double(short,int)) 모양인 T를 리턴 타입(double)과
//    나머지(인자타입)로 분리 한다.
//	  - T(double(short, int)) -> R(A1, A2)
// 4. primary template 의 "typedef T type" 이 필요 없는 경우는 제거해도 된다.

// 참고
// 1. C++ 11 표준에서 함수의 리턴 타입을 구하기
//   - result_of(before C++17), invoke_result(since C++17)
//   - 예제에서 구현한 방식과는 전혀 다른 방식으로 구현되어 있음.
//	 - decltype 사용해서 구현. (일반 함수, 함수 객체, 람다표현식등의 모든 callable object 고려)

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
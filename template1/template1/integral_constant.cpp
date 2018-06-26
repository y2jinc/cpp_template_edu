#include <iostream>
using namespace std;

// 핵심 개념
// 1. int뿐 아니라 모든 정수 계열(bool, char, short, int, long long long)의 
//    상수 값을 타입으로 만들 수 있게 하자.(참고, 실수는 템플릿 인자로 사용 할 수 없다.)

// 2. integral_constant : "모든 정수 계열의 컴파일 시간 상수"를 타입으로 만드는 템플릿.

// 3. true_type, false_type
//   - true/false : 참 거짓을 나타내는 값. 서로 같은 타입
//	 - true_type/false_type : 참/거짓을 나타내는 타입. 서로 다른 타입.

// 4. is_pointer 등의 type_traits 를 만들 때 integral_constant 를 기반 클래스로 사용한다.
//	 - T가 포인터가 아니라면, value = false, 기반 클래스는 false_type
//	 - T가 포인터 라면 value = true, 기반 클래스는 true_type

template<typename T, T N> 
struct integral_constant
{
	static constexpr T value = N;
};

// C++11 표준에 포함되어있다.
//integral_constant<int, 0> t0;
//integral_constant<int, 1> t1;
//integral_constant<short, 0> t3;

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

// is_pointer 만들때...
template<typename T> 
struct is_pointer : false_type
{
	// value = false;
};

template<typename T>
struct is_pointer<T*> : true_type
{
	// value = true;
};

// integral_constant2.cpp에 이어서...


int main()
{

}
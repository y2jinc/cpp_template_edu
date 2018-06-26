#include <iostream>
using namespace std;

class Test
{
public:
	//...
	//enum { DWORD = 5 };
	typedef int DWORD;
};

template<typename T>
typename T::DWORD foo(T t) // T : test
{
	// 아래 한줄을 해석해 보세요.
	// T::DWORD* p; // 값 : 5 * p -> ms compiler 에서는 에러나지 않음.
			        // 타입 : 지역변수 p(포인터)를 선언한다.

	// typename T::DWORD * p; // => 타입으로 해석

	return 0;
}

int main()
{
	Test t;
	foo(t);
	return 0;
}
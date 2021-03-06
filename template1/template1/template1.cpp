// template1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include <iostream>
using namespace std;


template<typename T>
class Test
{
public:
	void foo() {}
	void goo() {}

private:
	T aaaa;
};

template<typename T>
T square(T a)
{
	return a * a;
}

//////////////////////////////////////////////////////////////////////////
// 명시적 인스턴스화

//template class Test<int>;	// foo, goo 모두 인스턴스화
//template void Test<int>::foo(); // foo 만 인스턴스화

//template int square<int>(int);
//template int square<>(int);
//template int square(int);	

//////////////////////////////////////////////////////////////////////////

int main()
{
	//square(3);
	//square(3.3);

	//short s = 3;
	//square(s);

	//////////////////////////////////////////////////////////////////////////
	// 암시적 인스턴스화
	int n1 = square(3);		
	int n2 = square<int>(3);		

	Test<int> t1;
	t1.foo();
	//////////////////////////////////////////////////////////////////////////



    return 0;
}
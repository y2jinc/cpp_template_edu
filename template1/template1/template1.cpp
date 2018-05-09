// template1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include <iostream>
using namespace std;

template<typename T>
T square(T a)
{
	return a * a;
}

int main()
{
	//square<int>(3);	int square(int a) 생성 
	//square(3.3);		double square(double a) 생성

	square(3);
	square(3.3);

    return 0;
}
#include <iostream>
using namespace std;

// 상속을 사용한 couple template 의 선형화 기술

// 1. empty class Null
//	- 아무 멤버도 없는 클래스.
//	- 크기는 항상 1이다.(sizeof(Null))
//	- 아무 멤버도 없지만"타입"이므로 함수 오버로딩이나 템플릿 인자로 활용 가능
// 2. 상속을 사용하는 기술
// 3. 개수를 제한을 없앨수 없을까? => C++11 Variadic template

template<typename T, typename U>
struct couple
{
	T v1;
	U v2;

	enum { N = 2 };
};

struct Null {};		// empty class

// 2개이상 5개 이하의 타입전달.
template<typename P1, 
		 typename P2, 
		 typename P3 = Null, 
		 typename P4 = Null,
	     typename P5 = Null>
class xtuple 
	: public couple<P1, xtuple<P2, P3, P4, P5, Null>>
{
};

template<typename P1, typename P2>
class xtuple<P1, P2, Null, Null, Null>
	: public couple<P1, P2>
{
};

int main()
{	
	//													   couple<short, double>
	//										 couple<short, xt<double, Null, Null, Null, Null>>
	//						    couple<long, xt<short, double, Null, Null, Null>>
	//			   couple<char, xt<long, short, double, Null, Null>>
	// couple<int, xt<char, long, short, double, Null>>
	xtuple<int, char, long, short, double> t5;

	cout << sizeof(t5) << endl;

	//xtuple<int, int, double> t3;
}
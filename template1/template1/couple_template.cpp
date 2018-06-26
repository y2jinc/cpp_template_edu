#include <iostream>
using namespace std;

// couple 만들기 핵심
// 1. 템플릿의 인자로 자기 자신의 타입을 전달하는 코드
// 2. 부분특수화를 만들 때 템플릿 인자의 개수
// 3. N을 값을 표현하는 방법
// 4. couple 의 1번째, 2번째 인자가 모두 커플일 경우

template<typename T> 
void printN(const T& cp)
{
	cout << T::N << endl;
}

template<typename T, typename U>
struct couple
{
	T v1;
	U v2;

	enum { N = 2 };
};

// 2번째 인자가 couple 일 경우
template<typename A, typename B, typename C>
struct couple< A, couple<B,C> >
{
	A v1;
	couple<B,C> v2;

	enum { N = couple<B,C>::N + 1 };
};

// 1번째 인자가 couple 일 경우
template<typename A, typename B, typename C>
struct couple< couple<A, B>, C >
{
	couple<A, B> v1;
	C v2;	

	enum { N = couple<A, B>::N + 1 };
};

// 1번째, 2번째 인자가 couple 일 경우
template<typename A, typename B, typename C, typename D>
struct couple< couple<A, B>, couple<C, D>>
{
	couple<A, B> v1;
	C v2;

	enum { N = couple<A, B>::N + couple<C, D>::N };
};

int main()
{
	couple<int, double> c2;
	couple<int, couple<int, char>> c3;
	couple<int, couple<int, couple<int, double>>> c4;	
	
	printN(c2);
	printN(c3);
	printN(c4);

	couple<int, double> d2;
	couple<couple<int, char>, int> d3;
	couple<couple<int, couple<int, double>>, int> d4;

	printN(d2);
	printN(d3);
	printN(d4);

	couple<couple<int, int>, couple<int, int>> e4;
	printN(e4);

	return 0;
}

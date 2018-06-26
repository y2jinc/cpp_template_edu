#include <iostream>
using namespace std;

// couple ����� �ٽ�
// 1. ���ø��� ���ڷ� �ڱ� �ڽ��� Ÿ���� �����ϴ� �ڵ�
// 2. �κ�Ư��ȭ�� ���� �� ���ø� ������ ����
// 3. N�� ���� ǥ���ϴ� ���
// 4. couple �� 1��°, 2��° ���ڰ� ��� Ŀ���� ���

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

// 2��° ���ڰ� couple �� ���
template<typename A, typename B, typename C>
struct couple< A, couple<B,C> >
{
	A v1;
	couple<B,C> v2;

	enum { N = couple<B,C>::N + 1 };
};

// 1��° ���ڰ� couple �� ���
template<typename A, typename B, typename C>
struct couple< couple<A, B>, C >
{
	couple<A, B> v1;
	C v2;	

	enum { N = couple<A, B>::N + 1 };
};

// 1��°, 2��° ���ڰ� couple �� ���
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

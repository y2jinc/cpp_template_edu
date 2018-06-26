#include <iostream>
using namespace std;

// ����� ����� couple template �� ����ȭ ���

// 1. empty class Null
//	- �ƹ� ����� ���� Ŭ����.
//	- ũ��� �׻� 1�̴�.(sizeof(Null))
//	- �ƹ� ����� ������"Ÿ��"�̹Ƿ� �Լ� �����ε��̳� ���ø� ���ڷ� Ȱ�� ����
// 2. ����� ����ϴ� ���
// 3. ������ ������ ���ټ� ������? => C++11 Variadic template

template<typename T, typename U>
struct couple
{
	T v1;
	U v2;

	enum { N = 2 };
};

struct Null {};		// empty class

// 2���̻� 5�� ������ Ÿ������.
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
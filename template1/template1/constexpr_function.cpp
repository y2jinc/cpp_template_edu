#include <iostream>
using namespace std;

template<int N> struct check {};

// constexpr �Լ� - c++11
constexpr int add(int a, int b)
{
	return a + b;
}

int main()
{
	int n = add(1, 2);
	check< add(1, 2) > c;	// ok.. ( ������ Ÿ�ӿ� ����)

	int n1 = 1, n2 = 2;
	int aa = add(n1, n2);	// ok.. ( ��Ÿ�ӿ� �����)
	//check< add(n1, n2) > d;	// error
}
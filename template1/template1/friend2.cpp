#include <iostream>
using namespace std;

template<typename T>
class Point { };

template<typename T>
void foo(Point<T> a)
{	
	cout << "T" << endl;
};

void foo(Point<int>); // { cout << "int" << endl; }

// template function�� �־
// �Ϲ� �Լ��� ����Ϸ���.

int main()
{
	Point<int> p;
	foo(p);
	return 0;
}
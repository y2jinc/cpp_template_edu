#include <iostream>
using namespace std;

template<typename T>
class Point 
{ 
	T x, y;
public:
	Point(T a = 0, T b = 0) : x(a), y(b) {}

	//friend ostream& operator<<(ostream& os, const Point<T>& p);

	// 1�� ���ø� �Լ��� ����.
	// N:N ���谡 ��.
	template<typename U>
	friend ostream& operator<<(ostream& os, const Point<U>& p);
};

// �Լ� ���ø�
template<typename T>
ostream& operator<<(ostream& os, const Point<T>& p)
{
	return os << p.x << ", " << p.y;
}

template<typename T>
class Point
{
	T x, y;
public:
	Point(T a = 0, T b = 0) : x(a), y(b) {}

	// 2�� ���ø� �Լ��� ���Ǻ� ����.
	// 1:1 ����
	friend ostream& operator<<(ostream& os, const Point<T>& p)
	{
		return os << p.x << ", " << p.y;
	}
};

/*
class Point<int>
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	friend ostream& operator<<(ostream& os, const Point<int>& p);	// error ������ ������ friend2.cpp ����.
};

*/


int main()
{
	Point<int> p(1, 2);

	cout << p << endl;
	return 0;
}
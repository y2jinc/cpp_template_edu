#include <iostream>
using namespace std;

template<typename T>
class Point 
{ 
	T x, y;
public:
	Point(T a = 0, T b = 0) : x(a), y(b) {}

	//friend ostream& operator<<(ostream& os, const Point<T>& p);

	// 1안 템플릿 함수로 선언.
	// N:N 관계가 됨.
	template<typename U>
	friend ostream& operator<<(ostream& os, const Point<U>& p);
};

// 함수 템플릿
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

	// 2안 템플릿 함수로 정의부 포함.
	// 1:1 관계
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

	friend ostream& operator<<(ostream& os, const Point<int>& p);	// error 나오는 이유는 friend2.cpp 참고.
};

*/


int main()
{
	Point<int> p(1, 2);

	cout << p << endl;
	return 0;
}
#include <iostream>
using namespace std;

//typedef int DWORD;
//typedef void(*F)(int);

using DWORD = int;
using F = void(*)(int);

// using �� typedef ���� ���� ��.

template<typename T, typename U> struct Pair
{
	T v1;
	U v2;
};

//typedef Pair Point; // error

template<typename T, typename U>
using Point = Pair<T, U>;	// using�� type �Ӿƴ϶� template�� ��Ī�� ���� �� �ִ�.

template<typename T>
using Point2 = Pair<T, T>;

template<typename T>
using Point3 = Pair<T, short>;

int main()
{
	DWORD n;
	F f;

	Point<int, double> p; // Pair<T,U>

	Point2<int> p2;	// Pair<int, int>

	Point3<int> p3;	// Pair<int, short>
		
	return 0;
}
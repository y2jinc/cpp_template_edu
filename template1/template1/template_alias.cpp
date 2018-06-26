#include <iostream>
using namespace std;

//typedef int DWORD;
//typedef void(*F)(int);

using DWORD = int;
using F = void(*)(int);

// using 이 typedef 보다 나은 점.

template<typename T, typename U> struct Pair
{
	T v1;
	U v2;
};

//typedef Pair Point; // error

template<typename T, typename U>
using Point = Pair<T, U>;	// using은 type 뿐아니라 template도 별칭을 만들 수 있다.

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
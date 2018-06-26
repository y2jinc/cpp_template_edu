// class template type deduction
//		using value_type

#include <iostream>
#include <list>
using namespace std;

template<typename T> 
class Vector
{
	T* buff;
	int size;
public:
	Vector(int sz, T value) {}

	template<typename C> Vector(C c) {}

	template<typename D> 
	Vector(typename D::iterator begin_itr, typename D::iterator end_itr) {}
	
};

//template<typename C> 
//Vector(C c)->Vector< typename C::value_type >;

int main()
{
	Vector<int> v(10, 3);

	list<int> s = { 1,2,3 };
	Vector<list<int>> v2(2);

	// 다른 컨테이너의 반복자로 초기화한 Vector
	Vector<list<int>::iterator> v3(s.begin(), s.end());

	//int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//Vector v4(x, x + 10);
}
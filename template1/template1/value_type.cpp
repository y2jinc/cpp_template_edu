#include <iostream>
#include <vector>
#include <list>
using namespace std;

//template<typename T>
//void print_first_element(vector<int>& v)
//{
//	int n = v.front();
//	cout << n << endl;
//}

/*
// 모든 타입 접근
template<typename T>
void print_first_element(vector<T>& v)
{
	T n = v.front();
	cout << n << endl;
}
*/

// 모든 컨테이너를 처리하는 함수
template<typename T>
void print_first_element(T& v)
{
	// T : list<double>	
	// T::value_type => list<double>::value_type
	typename T::value_type n = v.front();
	// auto n = v.front(); // c++ 11 에서 가능
	cout << n << endl;
}

int main()
{
	vector<double> v = { 1, 2, 3 };
	print_first_element(v);
}


#include <iostream>
using namespace std;

template<bool b, typename T, typename F>
struct IfThenElse
{
	typedef T type;
};

template<typename T, typename F>
struct IfThenElse<false, T, F>
{
	typedef F type;
};

int main()
{
	IfThenElse<true, int, double>::type		t0; // int
	IfThenElse<false, int, double>::type	t1; // double

	cout << typeid(t0).name() << endl;
	cout << typeid(t1).name() << endl;

	return 0;
}


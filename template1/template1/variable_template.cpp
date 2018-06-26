#include <iostream>
using namespace std;

//#define PI 3.14

//constexpr double pi = 3.14;
//constexpr float pi = 3.14f;

// template 종류
// 1. function template
// 2. class template
// 3. variable(변수) template(c++ 14)

template<typename T>
constexpr T pi = 3.14;			// variable template

template<typename T> 
void foo(T a, T b)
{

}

int main()
{
	float f = 3.3f;
	foo(f, pi<float>);

	double d = pi<double>;

	return 0;
}
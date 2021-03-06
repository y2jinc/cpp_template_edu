// template_type_index.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <boost\type_index.hpp>
using namespace std;
using namespace boost::typeindex;

template<typename T>
void foo(const T a)
{
	// const, volatile, reference는 조사 할 수 없다.
	cout << "T : " << typeid(T).name() << endl;	
	cout << "a : " << typeid(a).name() << endl;
}

template<typename T>
void foo_boost(const T a)
{
	// const, volatile, reference 조사 가능
	cout << "T : " << type_id_with_cvr<T>().pretty_name() << endl;	
	cout << "a : " << type_id_with_cvr<decltype(a)>().pretty_name() << endl;
}

int main()
{
	//foo<int>(3);

	foo(3);			// T : int,		a : const int
	foo(3.3);		// T : double,	a : const double

	foo_boost(3);		// T : int,		a : const int
	foo_boost(3.3);		// T : double,	a : const double

    return 0;
}


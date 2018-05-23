#include "stdafx.h"

template<typename T> 
void foo(T n)
{
	*n = 10;
}

void test1()
{
	//if constexpr (false)	// static if -> c++17에서 지원
	//	foo(0);
}
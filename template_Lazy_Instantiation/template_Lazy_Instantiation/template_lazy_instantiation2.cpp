#include "stdafx.h"

template<typename T> 
void foo(T n)
{
	*n = 10;
}

void test1()
{
	//if constexpr (false)	// static if -> c++17���� ����
	//	foo(0);
}
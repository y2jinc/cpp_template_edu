#include "stdafx.h"

template<typename T> void foo(T n, int)
{
	*n = 3.4;
}

template<typename T> void foo(T n, double) {}

void test2()
{
	foo(1, 3.4);
}
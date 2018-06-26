#include <iostream>
using namespace std;

// is_array �����
// 1. Primary template ������ false ���� (value=false)
// 2. �迭 ������� �κ� Ư��ȭ(partial specialization) ����� ����� 
//    true ����(value=true)
// 3. Ÿ���� ��Ȯ�� �˾ƾ� �Ѵ�.
//  - int x[3]; ���� x�� �����̸�, ���� �̸��� 
//	  ������ ������ ���(int[3])�� Ÿ���̴�.

// �迭�� ũ�⵵ ���Ҽ� �ִ�.
//  - C++11 ǥ�� - extent<T, 0>::value
// �Լ� ���ø��� ���ڸ� ��(T)���� ���� ��� �迭�� �����ϸ� 
// T�� Ÿ���� �迭�� �ƴ� �����ͷ� �����ȴ�.

template<typename T> struct xis_array
{
	static constexpr bool value = false;
	static constexpr size_t size = -1;
};

// for fixed size array
template<typename T, size_t N> 
struct xis_array<T[N]>
{
	static constexpr bool value = true;
	static constexpr size_t size = N;
};

// for unknown size array
template<typename T>
struct xis_array<T[]>
{
	static constexpr bool value = true;
};

template<typename T> void foo(T& a)	// ������ �޾ƾ߸� �迭�� ������ ������ �ִ�.
{
	if (xis_array<T>::value)
	{

		cout << "array size : " << xis_array<T>::size << endl;
		cout << "array size : " << xis_array<T>::size << endl;
	}
	else
	{
		cout << "not array" << endl;
	}
		
}

int main()
{
	int x[3][2] = { 1,2,3,4,5,6 }; // ���� �̸� x	 Ÿ�� int[3]
						  //                  T[N]

	foo(x);
}
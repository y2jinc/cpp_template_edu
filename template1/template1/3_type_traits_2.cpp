#include <iostream>
#include <type_traits>
using namespace std;

// �迭 ���� �����ϱ�

// array => pointer : decay(https://stackoverflow.com/questions/1461432/what-is-array-decaying)
template<typename T> void foo(T& a)	// &(reference)�� �޾ƾ� ��!
{
	if (is_array<T>::value)
	{
		cout << "array" << endl;
		//cout << "array size : " << is_array<T>::size << endl;

		cout << extent<T, 0>::value << endl; // 3
		cout << extent<T, 1>::value << endl; // 2
	}
	else
	{
		cout << "it is not array." << endl;
	}
}

int main()
{
	int x[3][2] = { 1,2,3,4,5,6 };
	foo(x);
}
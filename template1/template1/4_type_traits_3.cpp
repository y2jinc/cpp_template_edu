#include <iostream>
#include <type_traits>

using namespace std;

// type_traits
// 1. is_array<T>::value, extent<T,0>::value
// 2. is_same<T,U>::value
// 3. remove_cv<T,U>::type
// 4. decay<T,U>::type - array�϶� �����ͷ� ��ȯ�ؼ� Ÿ���� ���.
// 5. is_base_of<T,U>::value - T�� U�� ���̽� Ŭ�������� Ȯ��.
// @ https://en.cppreference.com/w/cpp/types ����

// array => pointer : decay
template<typename T, typename U> 
void foo(T a, U b)
{
	//bool ret = is_same<typename remove_cv<T>::type,
	//				   typename remove_cv<U>::type>::value;
	bool ret = is_same<typename decay<T>::type,
					   typename decay<U>::type>::value;

	cout << ret << endl;

	bool T_is_base_class_of_U = is_base_of<T, U>::value;
	cout << "T is base class of U = " << T_is_base_class_of_U << endl;

	// �� �˾ƾ� �Ѵ�.
	// �� �κ��� ���� �˾ƺ���.
	if (is_trivially_constructible<T>::value)	
	{

	}
}

int main()
{
	foo(0, 0);

	foo<int, const int>(0, 0);

	foo<int[3], int*>(0, 0);
}
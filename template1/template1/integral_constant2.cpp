#include <iostream>
#include <type_traits>
using namespace std;

// ����.
//template<typename T>
//struct is_pointer : false_type
//{
//	// value = false;
//};
//
//template<typename T>
//struct is_pointer<T*> : true_type
//{
//	// value = true;
//};

// ����
// 1. is_pointer<T> ����
//   - T�� �����Ͱ� �ƴϸ� value = false, ��� Ŭ������ false_type
//	 - T�� ������ ��� value = true, ��� Ŭ������ true_type

// --> ��ü�� Ÿ���� �ƴ϶� ��ü�� ����(instance)�ؼ� �з��Ѵ�.

template<typename T>
void printv_imp(T v, true_type)
{
	cout << v << " : " << *v << endl;
}

template<typename T>
void printv_imp(T v, false_type)
{
	cout << v << endl;
}

template<typename T> 
void printv(T v)
{
	// �Լ��� �����ϱ� ���ؼ� is_pointer<T> Ÿ���� instance ��.
	printv_imp(v, is_pointer<T>()); 
}

int main()
{
	int n = 3;
	printv(n);
	printv(&n);
}
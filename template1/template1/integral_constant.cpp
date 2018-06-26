#include <iostream>
using namespace std;

// �ٽ� ����
// 1. int�� �ƴ϶� ��� ���� �迭(bool, char, short, int, long long long)�� 
//    ��� ���� Ÿ������ ���� �� �ְ� ����.(����, �Ǽ��� ���ø� ���ڷ� ��� �� �� ����.)

// 2. integral_constant : "��� ���� �迭�� ������ �ð� ���"�� Ÿ������ ����� ���ø�.

// 3. true_type, false_type
//   - true/false : �� ������ ��Ÿ���� ��. ���� ���� Ÿ��
//	 - true_type/false_type : ��/������ ��Ÿ���� Ÿ��. ���� �ٸ� Ÿ��.

// 4. is_pointer ���� type_traits �� ���� �� integral_constant �� ��� Ŭ������ ����Ѵ�.
//	 - T�� �����Ͱ� �ƴ϶��, value = false, ��� Ŭ������ false_type
//	 - T�� ������ ��� value = true, ��� Ŭ������ true_type

template<typename T, T N> 
struct integral_constant
{
	static constexpr T value = N;
};

// C++11 ǥ�ؿ� ���ԵǾ��ִ�.
//integral_constant<int, 0> t0;
//integral_constant<int, 1> t1;
//integral_constant<short, 0> t3;

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

// is_pointer ���鶧...
template<typename T> 
struct is_pointer : false_type
{
	// value = false;
};

template<typename T>
struct is_pointer<T*> : true_type
{
	// value = true;
};

// integral_constant2.cpp�� �̾...


int main()
{

}
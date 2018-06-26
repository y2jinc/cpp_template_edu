#include <iostream>
#include <type_traits>
using namespace std;

// IfThenElse template
// 1. ������ �ð� bool ���� ���� type ����
// 2. IfThenElse, IF, Select ��� �̸����� �˷��� �ִ�.
// 3. C++ ǥ�ؿ��� conditional �̶�� �̸����� ����. <type_traits> ���

template<bool b, typename T, typename F>
struct IfThenElse
{
	typedef T type;
};

template<typename T, typename F>
struct IfThenElse<false, T, F>
{
	typedef F type;
};

template<typename A, typename B, typename C>
struct IfThenElse<false, A, IfThenElse<true, B, C>>
{
	typedef B type;
};

template<typename A, typename B, typename C>
struct IfThenElse<false, A, IfThenElse<false, B, C>>
{
	typedef C type;
};

// ��Ʈ ���� �� ������ ���� Ŭ����
template<size_t N>
struct Bit
{
	//int bitmap;	// 32bit ����
	
	//using type = typename IfThenElse<(N <= 8), char, int>::type;

	//using type = typename conditional<(N <= 8), char, int>::type;

	using type = typename IfThenElse<(N <= 8), char, IfThenElse<(N <= 16), short, int> >::type;	

	type bitmap;
};


int main()
{
	Bit<32> b1;
	Bit<8>	b2;
	Bit<16>	b3;

	cout << sizeof(b1) << endl; // 4
	cout << sizeof(b2) << endl; // 1
	cout << sizeof(b3) << endl; // 2 -> ���� �ؾ��ұ�?

	return 0;
}


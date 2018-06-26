#include <iostream>
#include <type_traits>
using namespace std;

// IfThenElse template
// 1. 컴파일 시간 bool 값에 따라 type 선택
// 2. IfThenElse, IF, Select 라는 이름으로 알려져 있다.
// 3. C++ 표준에는 conditional 이라는 이름으로 제공. <type_traits> 헤더

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

// 비트 관리 및 보관을 위한 클래스
template<size_t N>
struct Bit
{
	//int bitmap;	// 32bit 관리
	
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
	cout << sizeof(b3) << endl; // 2 -> 어케 해야할까?

	return 0;
}


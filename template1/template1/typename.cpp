#include <iostream>
using namespace std;

class Test
{
public:
	//...
	//enum { DWORD = 5 };
	typedef int DWORD;
};

template<typename T>
typename T::DWORD foo(T t) // T : test
{
	// �Ʒ� ������ �ؼ��� ������.
	// T::DWORD* p; // �� : 5 * p -> ms compiler ������ �������� ����.
			        // Ÿ�� : �������� p(������)�� �����Ѵ�.

	// typename T::DWORD * p; // => Ÿ������ �ؼ�

	return 0;
}

int main()
{
	Test t;
	foo(t);
	return 0;
}
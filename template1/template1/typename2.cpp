#include <iostream>
using namespace std;

class Test
{
public:
	enum { value1 = 1 };
	static int value2;

	typedef int INT;
	using SHORT = short;	// C++11

	class innerClass {};
};

int Test::value2 = 1;

int main()
{
	int n1 = Test::value1;
	int n2 = Test::value2;

	Test::INT a;
	Test::SHORT b;
	Test::innerClass c;

	cout << sizeof(a) << sizeof(b) << sizeof(c);

	return 0;
}
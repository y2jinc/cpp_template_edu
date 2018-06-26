#include <iostream>
using namespace std;

template<typename T> class Stack
{
public:
	T pop()			{}
	void push(T a);
};

template<typename T> void Stack<T>::push(T a)
{
	cout << "T" << endl;
}

// ����Լ� ���ø� Ư��ȭ�� �κ� Ư��ȭ�� �Ҽ� ����.
//template<typename T> void Stack<char*>::push(char* a) // error
template<> void Stack<char*>::push(char* a)
{
	cout << "char*" << endl;
}

// @specialization ���� ����
// 1. Partial specialization �������� T�� Ÿ���� �����Ǵ� ���.
// 2. Partial specialization �������� default ���� ǥ�� ���� �ʴ´�.
// 3. Ŭ���� ��ü�� �ƴ� Ư�� ��� �Լ��� specialization �� �� �ִ�.
//    ������, Ư�� ��� �Լ��� partial specialization �� �� �� ����.

int main()
{
	Stack<int>	s1; s1.push(0);
	Stack<char*> s2; s2.push(0);
}
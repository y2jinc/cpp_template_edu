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

// 멤버함수 템플릿 특수화시 부분 특수화는 할수 없다.
//template<typename T> void Stack<char*>::push(char* a) // error
template<> void Stack<char*>::push(char* a)
{
	cout << "char*" << endl;
}

// @specialization 주의 사항
// 1. Partial specialization 버전에는 T의 타입이 결정되는 방식.
// 2. Partial specialization 버전에는 default 값을 표시 하지 않는다.
// 3. 클래스 전체가 아닌 특정 멤버 함수만 specialization 할 수 있다.
//    하지만, 특정 멤버 함수만 partial specialization 할 수 는 없다.

int main()
{
	Stack<int>	s1; s1.push(0);
	Stack<char*> s2; s2.push(0);
}
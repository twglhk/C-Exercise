//Operator overloading - ��ȣ �����ڿ� �Լ� ��ü

#include <iostream>

using namespace std;

class Accumulator
{
private:
	int m_counter = 0;

public:
	int operator()(int i) { return (m_counter += i); }
};

int main()
{
	Accumulator acc;
	cout << acc(10) << endl; // �̷� ���·� ����ϴ� ���� functor��� �Ѵ�.
	cout << acc(20) << endl;

	return 0;
}
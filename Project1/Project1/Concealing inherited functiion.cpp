#include <iostream>

using namespace std;

class Base
{
protected: 
	int m_i;

public:
	Base(int value)
		: m_i(value)
	{}

	void print()
	{
		cout << "I'm base" << endl;
	}
};

class Derived : public Base
{
private:
	double m_d;

	using Base::print; // ���������� private�� using�� ������ָ� �θ𿡼� public�̾����� 
	                   // ���⼭�� Private���� �ٲ�. �ܺ� ��� ����.

public:
	Derived(int value)
		: Base(value)
	{}

	using Base::m_i; // proteced�� ����� ������ �̷��� ����ϸ� Derived �ȿ��� public�� �Ǿ����.
	void print() = delete;
};

int main()
{
	Base b(10);
	Derived d(7);
	

	d.m_i = 1024;  // Derived class���� ����� �޾����� protected ������ �����Ƿ� ��� �Ұ���. 
				   // using Base::m_i; ����ϸ� �ܺ� ��� ����.


	b.print();
	d.print();     // Derived class �� private �������� using �ϸ� �ܺ� ��� �Ұ���.
	               // Access specifier�� �ٲٴ� ��� �ܿ��� ����� delete�� �����ϸ� ��� �Ұ���.

	return 0;
}
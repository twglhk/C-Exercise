#include <iostream>
class Base
{
public:
	Base(){}

	// freint func�� member�� �ƴϱ� ������ ���������� override �Ұ����ϴ�.
	friend std::ostream& operator << (std::ostream &out, const Base &b)
	{
		return b.print(out); // �ٸ� ��� �Լ��� ����ϰ� �����.
	}

	// �� ��� ���� �Լ��� �ڽ� Ŭ�������� override
	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	Derived() {}
	
	// @override 
	// �ڽ� Ŭ���������� operator overloading �� ��� ��.
	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Derived";
		return out;
	}

};

int main()
{
	Base b;
	std::cout << b << '\n';
	
	Derived d;
	std::cout << d << '\n'; 

	Base &bref = d;
	std::cout << bref << '\n';

	return 0;
}
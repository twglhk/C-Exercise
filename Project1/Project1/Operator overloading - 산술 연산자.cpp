#include <iostream>

using namespace std;

class Cents
{
private: 
	int m_cents;

public:
	Cents(int cents_ = 0) { m_cents = cents_; } // constructor
	int GetCents() const { return m_cents; } 
	int& GetCents() { return m_cents; }

	// �ȿ� ���� ����
	/*friend Cents operator +(const Cents& c1, const Cents& c2)
	{
		return Cents(c1.GetCents() + c2.GetCents());
	}*/

	// �� �������� friend ���� syntex error, �̷��� ������ ���׿��꿡���� �� ��Ҹ� ���ָ� ��.
	Cents operator +(const Cents& c2)
	{
		return Cents(this->m_cents + c2.m_cents); // �̷� ������ �ϳ��� this pointer�� �־���
	}

	/*

	����� 
	//, =, [], (), -> ��׵��� ��� �Լ��θ� �����ε��� �����ϴ�. 

	*/
};

// version 1
void add(const Cents& c1, const Cents& c2, Cents& c_out)
{
	c_out.GetCents() = c1.GetCents() + c2.GetCents();
}

// version 2
Cents add(const Cents& c1, const Cents& c2)
{
	return Cents(c1.GetCents() + c2.GetCents());
}

// version 3
//Cents operator +(const Cents& c1, const Cents& c2)
//{
//	return Cents(c1.GetCents() + c2.GetCents());
//}

// version 4  (frined �߰��� ����. �ٷ� private ��� �����ؼ� ��� ����)
//Cents operator +(const Cents& c1, const Cents& c2)
//{
//	return Cents(c1.m_cents + c2.m_cents);
//}

int main()
{
	Cents cents1(6);
	Cents cents2(8);

	Cents c_sum;
	add(cents1, cents2, c_sum);

	cout << c_sum.GetCents() << endl;	// version 1
	cout << add(cents1, cents2).GetCents() << endl; // version 2
	cout << (cents1 + cents2).GetCents() << endl; // version 3
	cout << (cents1 + cents2 + Cents(6)).GetCents() << endl; // version 3.5, anonymous object �������.
	cout << (cents1 + cents2).GetCents() << endl;

	/*
	�����ε� �ȵǴ� ������ ģ����
	?: ���� ������
	:: ���� ������
	sizeof 
	. member selection
	.* member pointer selection

	������ �켱������ ���� �Ұ���
	���������� ��� ������ �翬�� ���̴� �͵鸸 ������ �����ε� �ϴ� ���� ��õ. (������ ���, ����� ��� ��)
	�ָ��Ѱ� �׳� �Լ� ���°� ����.
	
	^ ��� ������ �켱 ������ ���Ƽ� ��ȣ ����� �ؼ� �� ���ϴ°� ����

	*/

	return 0;
}
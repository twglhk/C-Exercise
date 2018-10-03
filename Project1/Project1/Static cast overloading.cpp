#include <iostream>
using namespace std;

class Cents
{
private:
	int m_nCents;

public:
	Cents(int cents = 0)
	{
		m_nCents = cents;
	}

	operator int()
	{
		cout << "Case here" << endl;
		return m_nCents;
	}

	int getCents() { return m_nCents; }
	void setCents(int cents) { m_nCents = cents; }
};


class Dollar
{
private:
	int m_nDollars = 0;

public:
	Dollar(const int& input) : m_nDollars(input) {};

	operator Cents()
	{
		return Cents(m_nDollars * 100);
	}

};


void PrintInt(const int& value)
{
	cout << value << endl;
}

int main()
{
	Dollar dollar(2);
	Cents cents = dollar;

	// �� ���� ����� ����ȯ
	//int value = (int)cents;
	//value = int(cents);
	//value = static_cast<int>(cents); 
	PrintInt(cents); // int ����ȯ�� ���� �ÿ� �Ұ���. operator int()�� Ŭ������ �־��־�� ��.



	return 0;
}
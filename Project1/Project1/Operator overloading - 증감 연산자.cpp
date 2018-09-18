#include <iostream>

using namespace std;

//class Digit
//{
//private:
//	int m_digit;
//
//public:
//	Digit(int digit = 0): m_digit(digit) {}
//
//	// prefix
//	Digit& operator ++()
//	{
//		++m_digit;
//		return *this;
//	}
//
//	// postfix
//	Digit operator ++ (int)
//	{
//		Digit temp(m_digit); // ���� ���� ����
//		++(*this);
//		return temp;
//	}
//
//	friend ostream &operator << (ostream& out, const Digit &d)
//	{
//		out << d.m_digit;
//		return out;
//	}
//
//};


// Digit ���� �����ϱ�
class Digit
{
private:
	int m_digit;

public:
	Digit(int digit = 0) : m_digit(digit) {}

	// prefix, ���� 9�� 1�� �����ϸ� 0���� �ٲ�.
	Digit& operator ++()
	{
		if (m_digit == 9)
			m_digit = 0;

		else
			++m_digit;
		
		return *this;
	}

	// postfix
	Digit operator ++ (int)
	{
		Digit temp(m_digit); // ���� ���� ����
		++(*this);
		return temp;
	}

	friend ostream &operator << (ostream& out, const Digit &d)
	{
		out << d.m_digit;
		return out;
	}

};

int main()
{
	Digit d(5);

	while (true)
	{
		cout << ++d << endl;
	}
	
	cout << d << endl;



	/*cout << d++ << endl;
	cout << d << endl;*/

	return 0;
}
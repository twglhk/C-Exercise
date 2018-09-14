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

	// - ������ overloading
	Cents operator - () const
	{
		return Cents(-m_cents);
	}

	bool operator ! () const
	{
		// �� �κ��� � ���α׷��̳Ŀ� ���� ��Ȳ�� �°� ����
		return (m_cents == 0) ? true : false; 
	}

	// ����� overloading
	friend std::ostream& operator << (std::ostream& out, const Cents& cents)
	{
		out << cents.m_cents;
		return out; // �� return�� �ϴ� ������ chaining �����̴�. ���޾� �ٸ� ���� ����� �� �ʿ��ϴ�. 
	}
};

int main()
{
	Cents cents1(3);
	Cents cents2(0);

	// - operator
	cout << cents1 << endl;
	cout << -cents1 << endl;
	cout << -Cents(10) << endl; 

	// ! operator
	cout << !cents1 << endl;
	cout << !cents2 << endl;
	return 0;
}
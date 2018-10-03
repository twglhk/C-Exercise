#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:

	// constructor
	explicit Fraction(int num = 0, int den = 1)
		: m_numerator(num), m_denominator(den)
	{
		assert(den != 0);
	}

	// Delete, char�� ������ �����ڸ� ���ƹ����� ���.
	Fraction(char) = delete;


	Fraction(const Fraction& fraction) // copy constructor
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "called copy constructor" << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Fraction& f)
	{
		out << f.m_numerator << " / " << f.m_denominator << endl;
		return out;
	}
};

void doSomething(Fraction frac)
{
	cout << frac << endl;
}


int main()
{
	Fraction frac(3, 5);
	//Fraction f('c');  // �����ڿ� delete�� ����ϸ� �̰� �Ұ���������.
	
	// doSomething(7); // �̷��� �ص� �ڵ����� ������ �Ǵµ� �� ���� 'Converting constructor'��� �Ѵ�.
	                // �Լ� ���忡�� Fraction�ۿ� �޾Ƶ��� ������ ���ٸ� �ڵ� ����.

	doSomething(Fraction(7)); // ���� �����ڿ� Explicit�� �ɷ��ִٸ� ��ó�� ��� �Ұ���. �̷��� ���ų�
	doSomething(frac);        // �̷��� �����. �ٸ� �̷��� ����� ��� �� ���������� explicit�� �ɸ� constructor�� �ƴ�
	                          // copy constructor�� ȣ��ȴٴ� �� ������ ��.
	return 0;
}
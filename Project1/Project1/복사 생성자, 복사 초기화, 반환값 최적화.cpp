#include <iostream>
#include <cassert>

using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

	/*

	+) copy constructor�� ���ο� private ������ ������ ��� �ܺο��� ���� �Ұ���. ���ȼ� ����
	
	Fraction(const Fraction& fraction) // copy constructor
		: m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "called copy constructor" << endl;
	}
	
	*/

public:
	
	// constructor
	Fraction(int num = 0, int den = 1)
		: m_numerator(num), m_denominator(den)
	{
		assert(den != 0);
	}

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

Fraction doSomething()
{
	Fraction temp(1, 2);
	cout << &temp << endl;
	return temp;
}


int main()
{
	Fraction frac(3,5);
	Fraction fr_copy(frac); // call copy constructor
	Fraction fr_init = frac; // copy initialization, call copy constructor
	Fraction fr_skip(Fraction(3, 7)); // �� ��쿡�� ���� �����ڰ� ȣ�� ���� �ʰ� Fraction(3, 7) -> 3,7 �� �����Ϸ��� ������.
	
	Fraction fr_func = doSomething();  // call copy constructor, Debug->Release ���� ����� ȣ�� �ȉ�.
	                                   // �Լ����� return �� ���� �Լ��� �����鼭 ������ �ʿ� x
	                                   // �׷��� �����϶� ��ü������ �� �κп��� ������ �ٷ� ���� �Ű���.
	                                   // Return value Optimization

	cout << &fr_func << endl;          // �Լ� ������ return �� �ּҿ� �� ������ �ּҴ� �ٸ�.
	                                   // �ٸ��� ������ ���� �����ڰ� ȣ��Ǵ°� ����.
	                                   // �׷��� Release ��忡���� ��������.

	cout << frac << fr_copy << fr_init <<  endl;


	return 0;
}
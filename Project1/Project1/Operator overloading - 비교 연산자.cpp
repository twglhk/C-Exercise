#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents_ = 0) { m_cents = cents_; } // constructor
	int GetCents() const { return m_cents; }
	int& GetCents() { return m_cents; }

	friend bool operator == (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents == c2.m_cents;
	}

	friend bool operator != (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents != c2.m_cents;
	}

	// std::sort�� ����� �� ������ �� ũ�ٴ� �� �����ڸ� ���� ��� => ������ �ݴ�� ��(��������).
	/*friend bool operator > (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents > c2.m_cents;
	}*/

	friend bool operator < (const Cents& c1, const Cents& c2)
	{
		return c1.m_cents < c2.m_cents;
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
	Cents cents1(6);
	Cents cents2(6);

	if (cents1 == cents2)
		cout << "Equal" << endl;

	/////////////////////////////////////////

	std::vector<Cents> arr(20);
	for (unsigned i = 0; i < 20; i++)
		arr[i].GetCents() = i;
	
	// Random generating
	//std::random_shuffle(arr.begin(), arr.end());
	std::random_device rng;
	std::mt19937 urng(rng());
	std::shuffle(arr.begin(), arr.end(), urng); 

	for (const auto& num : arr)
		cout << num << " ";
	cout << endl;

	sort(arr.begin(), arr.end()); // �̰� �ϱ� ���ؼ��� ũ�� �񱳰� �����ؾ��Ѵ�.
	                              // int ������ �񱳰� ���������� Cent Ŭ���� ������ �� �Ұ���
	                              // ���� �� �����ڸ� �����ε� ���־�� �Ѵ�.

	for (const auto& num : arr)
		cout << num << " ";
	cout << endl;

	return 0;
}
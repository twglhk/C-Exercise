#include <iostream>

using namespace std;


template <class T>
class Storage
{
	T m_value;

public:
	Storage(T value) 
	{
		m_value = value;
	}

	~Storage()
	{
	}

	void print()
	{
		cout << m_value << endl;
	}

};

template <> // ���������� typename || class ��� x
void Storage<double>::print() // ���� �����ڿ� instantiation�� type ���
{
	std::cout << "Double Type";
	std::cout << std::scientific << m_value << endl;
}

template <typename T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

// template�� �Ϲ�ȭ�� ��Ű�� �������� �� ����� �ݴ�� 'Ư��ȭ'�� ��Ų��.
// Ư�� ���̽��� �ٷ� �� ���
template<>  // typename �� ������� �ʴ´�!!
char getMax(char x, char y)
{
	cout << "Warning : Comparing Chars" << endl;

	return (x > y) ? x : y;
}

int main()
{
	//cout << getMax(1, 2) << endl;
	// getMax<int>(1,2) �� auto instantiation ���ְ� �ִ�.
	// ���� getMax<double>(1,2) �� ����� ���� double�� instantiation
	
	//cout << getMax('a', 'b') << endl;

	Storage<int> nValue(5);
	Storage<double> dValue(3.14);

	nValue.print();
	dValue.print();

	return 0;
}
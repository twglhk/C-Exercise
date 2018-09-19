// Operator overloading - ÷�� ������

#include <iostream>
#include <cassert>
using namespace std;

class IntList
{
private:
	int m_list[10] = { 1,2,3,4,5,6,7,8,9,10 };

public:
	void setItem(int index, int value)
	{
		m_list[index] = value;
	}

	int getItem(int index)
	{
		return m_list[index];
	}

	// list�� address�� return
	int* getList()
	{
		return m_list;
	}

	// subscript operator overloading
	int &  operator [] (const int index) // param �� �� int type�� �ƴ϶� ��Ȳ�� �°�
	{
		// ��Ÿ�� ������ ����. ���� ó��. if���� ����� ��� performance�� �������Ƿ� ������� �ʴ´�.
		assert(index >= 0);
		assert(index < 10);

		return m_list[index];

		// reference�� return �ϴ� ������ my_list[3] = 10; ó�� ������ �����ؾ� �Ǳ� ������ ������
		// return ���� �׻� �ּҸ� ��� �־�� �ϱ� �����̴�. 
	}

	const int &  operator [] (const int index) const // overloading to read only.
	{
		// ��Ÿ�� ������ ����. ���� ó��.
		assert(index >= 0);
		assert(index < 10);

		return m_list[index];
	}

	
};


int main()
{
	IntList my_list;
	
	// �Լ��� �̿��� ���ð� ���
	my_list.setItem(3, 1);
	cout << my_list.getItem(3) << endl;
	
	// ÷�ڸ� �̿��� ���ð� ���
	my_list.getList()[3] = 2;
	cout << my_list.getList()[3] << endl; // �̷��� ���� ���� �����ϴ�.

	// ÷�� overloading
	my_list[3] = 10;
	cout << my_list[3] << endl;

	// Const�� ���
	const IntList myConList;
	// myConList[1] = 0; // �Ұ���. 
	cout << myConList[3] << endl; // �б⸸ ����
	
	// Class�� Pointer�� ������ ���
	IntList* lpList = new IntList;
	//lpList[3] = 10; // �Ұ���. �̰� ���ʿ� ������ ������ �ε��� ������ �ϴ� ���̱� ����.
	(*lpList)[3] = 10; // dereferencing�� �ϰ� �����ؾ���.
	lpList[2] = IntList(); // �̰� �Ǵ� ������ lpList�� ������ �����̱� ������ array �� ���� �ֱ� ����.
	                       // ���� IntList�� array�� �ִٸ� ������ ����.

	return 0;
}
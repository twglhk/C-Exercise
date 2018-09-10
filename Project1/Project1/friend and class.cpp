#include <iostream>
using namespace std;

// error C2061: syntax error: identifier 'B' 
// B�� A�� �տ� ����Ǿ� ���� ��� A�� B�� �� ���� ����. 
// �� �� ���� ������ ���ָ� ������ �ذ��� ���� �ִ�.
// �б� �����ϱ� ������ ��¿ �� ���� ����� ���� �ִ�. �� ���� �������� �� �ֱ� ����

class A; // Forward Declaration

class B
{
private:
	int m_value = 2;

public:
	//void doSomething(A& a)
	//{
	//	cout << a.m_value << endl; // �̷��� �ٸ� Ŭ������ private ������ ����ϰ� ���� ���? �ش� Ŭ���� ���η� ���� �� Ŭ������ friend �����Ѵ�.
	//}

	void doSomething_sec(A& a);
};


class A
{
private:
	int m_value = 1;

	//friend void doSomething(A& a, B& b); // �ܺ� �Լ����� private���� ����� ��� ������ ����ϰ� ���� �� friend+�Լ� prototype
	//friend class B; // ��°�� �ٸ� class�� friend�� �����ϸ� �ش� Ŭ�������� �� Ŭ������ private ����� ����� �� �ִ�.
	friend void B::doSomething_sec(A& a); // �̷��� �� �����ϴ°� ���� ��� �Լ��� ���ؼ��� ������ �� �ֵ��� friend ���� ����. 
	//�׷��� �̷��Ը� �ϸ� A�� B�� �̷� ����� �ִ��� ��. ���� B Ŭ���� ���ο��� ����ο� ���Ǹ� �и����������
	
};

//class B
//{
//private:
//	int m_value = 2;
//
//
//	friend void doSomething(A& a, B& b); // �ܺ� �Լ����� private���� ����� ��� ������ ����ϰ� ���� �� friend+�Լ� prototype
//};




// class ���ο��� friend ���谡 �� �ܺ� �Լ�
//void doSomething(A& a, B& b)
//{
//	cout << a.m_value << " " << b.m_value <<  endl;
//}



void B::doSomething_sec(A& a)
{
	cout << a.m_value << endl; 
}


int main()
{
	A a;
	B b;
	//doSomething(a, b);

	b.doSomething_sec(a);

	return 0;
}
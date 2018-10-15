#include <iostream>

using namespace std;

class A
{
public:
	virtual void printOverride(int x) { cout << "A" << endl; }
	void printCovariant() { cout << "A" << endl; }
	virtual A* getThis() 
	{ 
		cout << "A::getThis()" << endl;
		return this; 
	}
};

class B : public A
{
public:
	long x;

	//void printOverride(short x) { cout << "B" << endl; } 
	// �Լ� param�� �ٸ��� overriding �Ұ�
	// Overloading���� �ν��Ѵ�. ���� Ŭ���� �Լ� ȣ��

	
	void printOverride(int x) override { cout << "B" << endl; }
	// �Լ� �ڿ� 'override'�� ������ָ� �����Ϸ��� override�� �ƴ� ��� �̸� ������ �߰�����.
	// Ȥ�� �Լ��� �̸��� Ʋ�� ��쵵 ã���ش�. ex) printOverride2 (int x)
	// prototype �� �ٸ� ��쵵 �߰�����.      ex) printOverride (int x) const override
	// �Ǽ��� �����ϴ� ���.


	virtual void printFinal(int x) final { cout << "B final" << endl; }
	// Final ����� ���� Ŭ�������� Override ��� �Ұ���

	void printCovariant() { cout << "B" << endl; }
	virtual B* getThis() 
	{ 
		cout << "B::getThis()" << endl;
		return this; 
	} // ���� return type�� �ٸ��� overriding�� �� �Ǵµ� �θ� �ڽ� �����̱� ������ ��.
	


	// void print1() { cout << "B" << endl; }
	

};

class C : public B
{
public:
	// virtual void printFinal(int x) { cout << "C" << endl; } // Final�̶� ��� �Ұ�
};

int main()
{
	A a;
	B b;
	//C c;

	A& ref = b;
	ref.printOverride(1);
	
	b.getThis()->printCovariant();
	ref.getThis()->printCovariant();

	
	/*
	Convariant Return type : ù��° ������ ũ�Ⱑ �ι�° ������ ũ�⿡ ���� ����
	�����ϰ� �̾߱��ؼ� ���� Ŭ�������� virtual�� ����� ��� �Լ��� �ڽ� Ŭ������ ���� ȣ��.
	virtual�� ������� ���� ���� �θ� Ŭ������ ���� ȣ���Ѵ�.
	A& ref = b; ���� ref�� ��·�� ������ A�̴�. �׷��� ���⿡ �ڽ� Ŭ������ ���������ν�
	virtual�� override�� �Լ��� �ڽ� Ŭ�������� ������ ���� ����ϰڴٴ� �ǹ��̴�.
	*/

	cout << sizeof(ref) << endl;
	cout << sizeof(b) << endl;
	
	cout << typeid(b.getThis()).name() << endl;
	cout << typeid(ref.getThis()).name() << endl;

	return 0;
}
#include <iostream>

using namespace std;

/*
	move semantics�� �׻� ��� �� �ȴ�.
	R-value reference�� move semantics�� ����� ��, ����� �� ������, ����ϸ� �� �Ǵ���
	�Ǻ��ϰ� ���ش�. 
*/

void doSomething(int& lref)
{
	cout << "L-value ref" << endl;
}

void doSomething(int &&ref)
{
	cout << "R-value ref" << endl;
}

int getResult()
{
	return 100 * 100;
}

int main()
{
	int x = 5;
	int y = getResult();
	const int cx = 6;
	const int cy = getResult();

	// L-value reference
	int &lr1 = x;			// Modifiable l-values, old c++�� reference �ǹ�
	// int &lr2 = cx;		// Non modifiable l-values, lr2�� const�� �ƴϱ� ������ �Ұ���
	// int &lr3 = 5;		// R-values, �� ������ �����ϴ� ������ �޸𸮸� ��������. �׷��� �Ұ���

	const int &lr4 = x;		// Modifiable l-values
	const int &lr5 = cx;	// Non-modifiable l-values
	const int &lr6 = 5;		// R-values, symbolic const �� ����Ѵٸ� ����


	// R-value reference
	//int &&rr1 = x;			// Modifiable l-values
	//int &&rr2 = cx;			// Non modifiable l-values
	int &&rrr = getResult();
	int &&rr3 = 5;				// R-values, �� ������ Ư¡�� R-value�� ���� �� �ִ�. 
								// 5 ���� ����� �� ������ ������ ����� ���.
								// R-value reference�� �ӽ÷� �����ϴ� ����� �����Ѵ�.

	cout << rr3 << endl;
	rr3 = 10;
	cout << rr3 << endl;

	// &&�� �ǹ̴� 5��� r-value ��ü�� ���� ����� �� �ִٴ� ���� ��Ÿ����.
	// Ŭ������ �ν��Ͻ���� rr�� ����ϰų� rr�� �ٲ� �� �ְ� �ϴ� ���̴�.


	//const int &&rr4 = x;		// Modifiable l-values
	//const int &&rr5 = cx;		// Non modifiable l-values
	const int &&rr6 = 5;		// R-values

	// L-R value reference parameters
	doSomething(x);				// L-value
	//doSomething(cx);			// const. const�� const�� �ƴ� lvalue�� ���� �� ����.
	doSomething(5);				// R-value
	doSomething(getResult());	// R-value

	/*
		��������δ� move semantics�� Ȱ���� key point
		L-value�� �Ѱ��� ��� move semantics�� �߻��ϸ� �� �Ǵ� ��찡 �����.
		���� ��� x�� �Լ��� reference param���� ���� �� x�� �ٽ� �Լ� �ۿ��� ����� ���� �ִٴ� ��
		�׷��� move semantics�� �̿��� �� ������ �ɸ���. �浹�� �Ͼ �� �ִ�.

		�ݴ�� R-value reference�� ������ ������ ���ε� ����ó�� �̿��� �����ϰ� ������ִ� ���̴�.
		������ move semantics�� Ȱ���ص� ������ ����.
	*/
		
	return 0;
}
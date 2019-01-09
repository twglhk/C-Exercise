#include <iostream>
#include "Resource.h"
#include "AutoPtr.h"

using namespace std;

/*
new/delete �޸�, �� ���� �޸𸮸� ���� �����ϴ� ���� ���ŷο�.
����Ʈ �����͸� ������ �� ���� ����
*/

// RAII : resource acquitition is initialization
// RAII ? �޸� �Ҵ� ���� ������ �������־�� �Ѵٴ� ��Ģ

void dosomething()
{
	/*
		�Ҵ�� �޸𸮴� ��� case�� ���ؼ� delete�� ���־�� ����
		1. �Լ��� ������ ��
		2. ���� ������ ���
		3. ���� ó���� ���

		==> �� ���ŷο��� �ذ� => ����Ʈ������ ����
	*/


	// Resource* res = new Resource; // dull ptr
	AutoPtr<Resource> res = new Resource;

	try
	{

		if (true) throw - 1;

		// delete res; // not called
	}
	catch (...)
	{
		// CASE 3
		// delete res;
	}

	if (true)
	{
		// CASE 2
		// delete res;
		return;
	}

	// work with res

	// CASE 1
	// delete res;

	return;
}

int main()
{
	// dosomething();

	AutoPtr<Resource> res1(new Resource);
	AutoPtr<Resource> res2;

	cout << std::boolalpha;

	cout << res1.m_ptr << endl;
	cout << res2.m_ptr << endl;

	res2 = res1; // ������ ���� ==> move semantics

	cout << res1.m_ptr << endl;
	cout << res2.m_ptr << endl;

	/*
		value semantics (copy)
		reference semantics (pointer)
		move semantics (move)
	*/

	return 0;
}
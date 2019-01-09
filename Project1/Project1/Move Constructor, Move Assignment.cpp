#include "Resource.h"
#include "AutoPtr.h"
#include "Timer.h"

AutoPtr<Resource> generateResource()
{
	AutoPtr<Resource> res(new Resource(1000000));
	return res;
}

int main()
{
	using namespace std;
	streambuf* orig_buf = cout.rdbuf();
	//cout.rdbuf(NULL);

	{
		AutoPtr<Resource> main_res;
		main_res = generateResource();  // �Լ��� ������ AutoPtr�� �ٽ� ���� ���� ����.
										// ������ deep copy�� �ϱ� ���� R-value reference�� ����
										// swallow copy
	}

	cout.rdbuf(orig_buf);

	return 0;
}
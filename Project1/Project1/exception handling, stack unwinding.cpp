#include <iostream>

using namespace std;

// void last() throw(int) exception specifier
// void last() throw(...) exception specifier

void first();
void second();
void third();
void last();

void first()
{
	cout << "FIRST" << endl;

	try
	{
		second();
	}
	catch (int)
	{
		// second ���� ���ƿ� throw�� ó�� ����. ���������� �Լ� ����.
		cerr << "first caught int exception" << endl;
	}

	cout << "END FIRST" << endl;
}

void second()
{
	cout << "SECOND" << endl;

	try
	{
		third();
	}
	catch (double)
	{
		// ���������� try���� ���ƿ� throw�� ���� catch ó���� �����Ƿ� ������� �ʴ´�. 
		cerr << "second caught double exception" << endl;
	}

	cout << "SECOND END" << endl;
}

void third()
{
	cout << "THIRD" << endl;
	last();

	// last���� throw �� ���� catch�� �κ��� ���� ������ ���� �Ұ���
	cout << "END THIRD" << endl;
}

void last() throw(int)
{
	cout << "LAST" << endl;
	cout << "Throws Exception" << endl;

	throw - 1;

	// ����ó���� ���� �Ұ���
	cout << "END LAST" << endl;
}

int main()
{
	cout << "START" << endl;

	try
	{
		first();
	}

	catch (int)
	{
		// cerr == cout ����ϴ�. 
		// std::clog �� �����. 
		// ��ɻ� ū ���̴� ���µ� �ֿܼ� ����ϴ� ä���� ���������� �ִٴ� �ǹ�.
		// cout ���� ��� �ٷιٷ� ����� �� �ϰ� ���ۿ� ��Ƶδٰ� endl ������ �� flush���� ����.
		// cerr �� ���� �޼����̹Ƿ� ���۸� �� ��ġ�� ��� �Ѵ�.
		cerr << "main caught int exception" << endl;
	}
	// uncaught exception
	catch (...)
	{
		cerr << "main caught ellipses exception" << endl;
	}


	cout << "END MAIN" << endl;


	return 0;
}
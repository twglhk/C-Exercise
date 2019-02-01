#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	/* string ���� �� ���� */
	string my_string("abcdefg");

	cout << my_string[0] << endl;
	cout << my_string[3] << endl;

	my_string[3] = 'Z';
	cout << my_string << endl;


	/* ���� exception */
	try
	{
		//my_string[100] = 'X';  // �� case�� ����ó���� �� �ȴ�. ������ �� �ֱ� ����.
		my_string.at(100) = 'X'; // invalid string position exception occur
								 // vector�� ���������� �̷� ������ ���� ó�� ����.
							     // performance�� �����ؼ� �������.
	}
	catch(std::exception& e)
	{
		cout << e.what() << endl;
	}


	/* string�� const char*�� �ٲٱ� */
	cout << my_string.c_str() << endl;
	cout << my_string.c_str()[6] << endl;

	const char *arr = my_string.c_str();
	cout << (int)arr[6] << endl;
	cout << (int)arr[7] << endl; // �� �ڿ� null char�� �ٿ��� �����ش�.
								 // C style�� ��� ����.


	/* string�� c style Array�� �ٲٱ� */
	char buf[20];

	my_string.copy(buf, 5, 1); // null char�� �־������� �ʴ´�. 
							   // offset �� ���� ��ġ

	buf[5] = '\0';

	cout << buf << endl;

	return 0;
}
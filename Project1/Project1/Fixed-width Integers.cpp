#include <iostream>
//#include <cstdint> 
//iostream�� include �ص� �� �� ����

int main()
{
	using namespace std;
	std::int16_t i(5);  // 16bit = 2byte �� �ٲ��ִ� ��. short�� ���ǵǾ� ����.
	std::int8_t myint = 65; // 1byte �̹Ƿ� char��.

	// int������ ������ �� �ִµ� define�� �ٸ��� �Ǿ�����.

	cout << myint << endl;

	std::int_fast8_t fi(5); // 8bit �߿��� ���� ���� data type.  
	std::int_least64_t fl(5); // ��� 64bit, 8byte�� ���� data type

	return 0;
}
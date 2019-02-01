#include <iostream>
#include <sstream>
using namespace std;

/* ���ڿ� �帧�� buffer ������ �ϴ� ���� string stream*/

int main()
{
	{ /* str()�� string stream�� string �ֱ�� extraction operator ����ؼ� �����ϱ� */
		stringstream os;
		os.str("Hello World!"); // buffer�� �ִ� ������ ���� ( )�� �������� �ٲ۴�.

		string str;
		os >> str;				// ��ĭ�� ������ �߶� �����´�.
		cout << str << endl;
	}

	{ /* insertion operator�� string stream�� string �ֱ� */
		stringstream os;
		os << "Hello World";	// << insertion operator , >> extraction operator
		os << " Hi!\n" << endl;	// buffer�� string �����Ϳ� �����δ�. �� << �� ������� ���̴�.
								// �ٹٲ�(\n)�� string�� ���� �� �� �ִ�. endl�� ���������̴�.

		string str = os.str();	// ��ĭ�� ������ ���� �����´�.
		cout << str << endl;
		cout << os.str() << endl; 
	}
	
	{ /* ���ڸ� string stream���� �ֱ�/�ޱ�. */
		
		// ���ڿ��� �ֱ�/�ޱ�
		stringstream os;
		os << "12345 67.89";
		string str1, str2;
		os >> str1 >> str2;
		cout << str1 << " | " << str2 << endl;

		// �ʱ�ȭ�� �̷� ������ �ؾ��Ѵ�.
		os.str("");
		os.clear();
		// == os.str(""); , �� param�� ���� ���� stream�� ������ return ���ش�.
		// == os.str(string);

		// ���ڷ� �ֱ� / ���ڿ��� �ޱ�
		int i = 12345;
		double d = 67.89;
		os << i << " " << d;
		os >> str1 >> str2;
		cout << str1 << " | " << str2 << endl;

		os.clear();

		// ���ڷ� �ֱ� / ���ڷ� �ޱ�
		int i2;
		double d2;
		os << i << " " << d;
		os >> i2 >> d2;
		cout << i2 << " | " << d2 << endl;

		os.clear();

		// ���ڿ��� �ֱ� / ���ڷ� �ޱ�
		os << "12345 67.89";
		os >> i2 >> d2;
		cout << i2 << " | " << d2 << endl;
	}


	return 0;
}
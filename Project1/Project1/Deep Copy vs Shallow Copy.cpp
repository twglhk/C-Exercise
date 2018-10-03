#include <iostream>
#include <cassert>
#include <string>

using namespace std;

/*
���� �Ҵ�� �޸𸮿� ���� ������ ������ ����ν� ������ �ִ� Ŭ������ ��� copy�� assignment �� ��
���� ���糪 ���� ����Ŀ� ���� assignment operator overloading, copy constructor ������ ��ٷο�����.
�ֱٿ��� std::vector�� std::string�� ����ϱ� ������ ����ڰ� �� ������ ���������� ����ϴ� ��찡 ���� ���� ���̴�.
���� ���ظ� ���ؼ� �����ϸ� ����.
*/

class Mystring
{

//private: �ּҸ� ���� ���� ���������� �ӽ÷� public���� �������.
public:
	char *m_data = nullptr;
	int m_length = 0;

	/*
	Default copy constructor�� ���� ������ �״�� �����ϴ� ��.
	������ ������ �ּҵ� �״�� �������ִ� ��
	�� ���� ���� ���� (Shallow copy) ��� �Ѵ�.
	*/

	// �� ���� ������ ������ �ذ��Ϸ��� string�� ����ϸ� ��.
	// Ȥ�� std::string Ŭ���� ����ϸ� ��.
	std::string str; 


public:
	Mystring(const char * source = "")
	{
		assert(source);

		m_length = std::strlen(source)+1;
		m_data = new char[m_length];

		for (int i = 0; i < m_length; i++)
		{
			m_data[i] = source[i];
		}

		m_data[m_length - 1] = '\0';
	}

	Mystring(const Mystring &source)
	{
		cout << "Copy constructor" << endl;

		m_length = source.m_length;

		if (source.m_data != nullptr) // source�� ���� �����Ͱ� ������
		{
			m_data = new char[m_length]; // �� ��ü���� �޸� ���� ��

			for (int i = 0; i < m_length; i++) // source�� ������ ����
				m_data[i] = source.m_data[i];

			/*
			<����ȭ�� 2>

			�̷� ������ ���� �޸𸮸� �Ҵ� �޾Ƽ�
			�����ϴ� ����� ���� ���� (Deep copy)��� �Ѵ�.
			*/
		}

		else
			m_data = nullptr; // �׳� 0�� ���� ���� �ִµ� ������ ������ ���� nullptr ���
	}

	Mystring& operator = (const Mystring & source)
	{
		// Shallow copy
		/*this->m_data = source.m_data;
		this->m_length = source.m_length;*/

		cout << "Assignment operator" << endl;

		// assignment operator�� ��� �ڱ� �ڽ��� ������ ���� �ִµ� ���α׷��� ������ ���� �� �ֱ� ������ ����.
		if (this == &source) // prevent self-assignment
			return *this;

		delete[] m_data; // assignment operator�� ��� ���� ����� ���� �ƴ� �� �ֱ� ������ ���� �޸� �����ؾ���.


		// �� ���� �κ��� copy constructor�� 2�� ������ ������ �Լ�ȭ ��Ű�°� ����.
		m_length = source.m_length;

		if (source.m_data != nullptr)
		{
			m_data = new char[m_length];

			for (int i = 0; i < m_length; i++)
				m_data[i] = source.m_data[i];
		}

		else
			m_data = nullptr;

		

		return *this;
	}


	// Mystring(const Mystring& source) = delete; // ����å��. ���� ���縦 �ƿ� ���ڴٴ� �ǹ�.

	~Mystring()
	{
		delete[] m_data;
	}

	char* getString() { return m_data; }
	int getLength() { return m_length; }

};

int main()
{
	Mystring hello("Hello");
	
	/*
	<����ȭ�� 3> , str1�� ��ü�� ��������� �����Ƿ� = �� �������� copy constructor ȣ��.
	str2�� assignment operator�� ȣ��ȴ�.
	*/

	//Mystring str1 = hello;
	Mystring str1(hello); // copy constructor�� ȣ��Ǳ� ������ �̷��� ��������� ���� ����.
	Mystring str2;
	str2 = hello;
	

	cout << (int*)hello.m_data << endl;
	cout << hello.getString() << endl;

	{
		Mystring copy = hello; // �����Ǵ� ���� copy�� �߻��� ��� copy constructor call
							   // default copy constructor�� ȣ��ȴ�.

		// copy = hello; // �̷� ������ �� ���� ���� �����ڰ� ȣ��
		cout << (int*)copy.m_data << endl;
		cout << copy.getString() << endl;

		/*
		+) ����ȭ�� 1�� ��Ȳ, Custom copy constructor�� ������� �ʴ� ���

		default copy constructor�� ������ �״�� �������ش�. �׷��� � ������ ����°�?
		heap �޸𸮿��� m_data�� �ϳ��� �����Ѵ�. �� copy�� hello �� ��ü�� �� �����͸� �����ϴ� ��Ȳ.
		�׷��� �� scope�� �����鼭 destructor�� ȣ���. heap�� �����͸� ����.
        �׷��� hello ��ü������ ����� m_data�� �� ���� ���Եǹ���.
		*/

	}

	cout << hello.getString() << endl;

	return 0;
}
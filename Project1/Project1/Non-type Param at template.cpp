#include <assert.h>
#include <iostream>

template <typename T, unsigned int T_SIZE> // T_SIZE�� compile time�� ����
                                           // Compile time�� �˷��� �־����.
class MyArray
{
private:
	//int m_length; // ��� ������ ������ �޴� ��ſ� T_SIZE�� �޴´�.
	T* m_data;      // T m_data[T_SIZE] stack���� ū size ���� �Ұ���
	                // �׷��� ������ ��찡 �ƴϸ� �����Ҵ��� ����.

public:
	MyArray() 
	{
		//m_length = 0;
		m_data = new T[T_SIZE];
	}

	~MyArray()
	{
		delete[] m_data;
 	}

	T & operator[] (int index)
	{
		assert(index >= 0 && index < T_SIZE);
		return m_data[index];
	}

	int getLength()
	{
		return T_SIZE;
	}

	void print()
	{
		for (int i = 0; i < T_SIZE; i++)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}

	// explicit instantiation
	// template class MyArray<char>
	// template class MyArray<double>

	// template void MyArray<char>::print();
	// template void MyArray<double>::print();
	// �̷��� ������� ��쿡 �� ���������� ������ �ȴ�.
	// T_SIZE�� ��� ��쿡 �������� ���� ���� ����.
	// template class MyArray<char,1~100> ��
	// ���� non type param�� �����ϴ� ���� header�� �־�� �Ѵ�.
	// Header only Open source lib �� ���� ����� ��� ������ ������ �ִ� ��쵵 �ִ�.

};


int main()
{
	// std::vector<double> my_array; my_array.resize(100);
	// MyArray<double> my_array(100);
	// ���� ���� �� ��� 100�̶�� ����� compile time�� �˷��� ���� �ʾƵ� �����ϴ�.
	// Runtime�� �����Ǿ ��� ����.
	// ���� double�� ���� �ڷ����� compile time�� �˷��� �־�� �Ѵ�.

	MyArray<double, 100> my_array; // 100�� compile time�� �˷��� �־����.
	                               // �� ����� �ַ� �޸� ���� �������ٴ�
	                               // 2����~3������ ���� �� ������ ���.

	for (int i = 0; i < my_array.getLength(); i++)
		my_array[i] = i + 65;

	my_array.print();

	return 0;
}
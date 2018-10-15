#include <iostream>
#include <cassert>
#include <initializer_list>

using namespace std;

class IntArray
{
private:
	unsigned m_length = 0;
	int* m_data = nullptr;

public:
	IntArray(unsigned length) 
		: m_length (length)
	{	
		m_data = new int[length];
	}

	~IntArray()
	{
		delete[] this->m_data;
	}


	// initialize_list�� class�� constructor���� ����ϱ�.
	IntArray(const std::initializer_list<int>& list)
		: IntArray(list.size()) // �̷��� �ϸ� ������ ������ �����ڰ� ȣ��Ǿ� �޸𸮸� �Ҵ�޾ƿ�.
	{
		int count = 0;
		for (auto & element : list) // for-each�� Initializer_list ������ iterator�� �̿���. 
		{
			m_data[count] = element;
			++count;
		}

		//for (unsigned count = 0; count < list.size(); count++)
		//	m_data[count] = list[count]; // error , initializer_list�� [] �� �������� ����. 
	}


	// Assignment operator ver
	IntArray& operator = (const std::initializer_list<int>& list) 
	{
		if (this->m_data != nullptr)
			delete[] m_data;
			
		m_length = list.size();
		m_data = new int[m_length];
	
		int count = 0;
		for (auto & element : list)
		{
			m_data[count] = element;
			++count;
		}
		
		return *this;
	}

	friend ostream& operator << (std::ostream& out, const IntArray& arr)
	{
		for (unsigned i = 0; i < arr.m_length; i++)
			out << arr.m_data[i] << " ";
		out << endl;
		return out;
	}

};


int main()
{
	int my_arr1[5] = { 1,2,3,4,5 };
	int *my_arr2 = new int[5]{ 1,2,3,4,5 };

	auto i1 = { 10,20,30 };
	/*
	class std::initializer_list<int>
	�̴ϼȶ����� ����Ʈ�� ����ϸ� ���ϰ� ����Ʈ �ۼ��� �����ϴ�. 
	*/


	IntArray int_array{ 1,2,3,4,5 };
	cout << int_array << endl;

	IntArray ass_array = { 1,2,3,4,5 };
	cout << ass_array;
	
	ass_array = i1;
	cout << ass_array;

	return 0;
}
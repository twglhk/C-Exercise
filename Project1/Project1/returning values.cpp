#include <iostream>
#include <array>

using namespace std;

// �������� ���� �Ǵ� ��Ȳ�� ����. performance ���鿡���� ���� ����.
int getValue(int x)
{
	int value = x * 2;
	return value;
}

int& getValue_reference(int x)
{
	int value = x * 2;
	return value; // �ش� scope ������ ������� ���� ������ & return ���Ŀ��� return �ϸ� �� ��.
}

int* getValue_pointer(int x)
{
	int value = x * 2;
	return &value;
}

int* allocateMemory(int size)
{
	return new int[size];
}

int& get(std::array<int, 100>& my_array, int ix)
{
	return my_array[ix];
}

struct  S
{
	int a, b, c, d;
};

S getStruct()
{
	S my_s{ 1,2,3,4 }; // �� ����� ������ �Լ� �ϳ��� ���� ������ ����ü�� ���� ��������. 
					   // tuple�� ���� �ذ� ����

	return my_s;
}

std::tuple<int, double> getTuple()
{
	int a = 10;
	double d = 3.14;
	return std::make_tuple(a, d);
}


int main()
{
	int value1 = getValue(3);

	int pValue1 = *getValue_pointer(3); // ����� ������ dereferencing �ϴ� ����ε� �������� ����.
									   // warning C4172: returning address of local variable or temporary: value
	
	int *pValue2 = getValue_pointer(3); // �̰ŵ� ���������� �Լ� ���ο��� ������� local ������ �޸� �ּҸ� �������� ������ ���� ����.
	cout << pValue1 << endl;
	
	//------------------------------------------------------------------------------------------------------------

	int *array1 = new int[10]; // �޸𸮸� �����ϰ� �� ������ �޸��� pointer ���� return �ϴ� ����� �Լ��� ���� �����ؼ� �����. => Factory pattern�� ���.
	int *array2 = allocateMemory(10); // �̷� ������.
	
	delete[] array1; // �̷��� new�� delete�� ���� ���� ���� �ڵ��� �� ������ ���� �� ����. �̷��� �� ����.
	
	//------------------------------------------------------------------------------------------------------------

	int value2 = getValue_reference(4); // reference�� ��� �����ִ� ��Ȳ���� �Լ��� local ���� �ȿ� �ִ� data�� ����Ǽ� value2�� ��.
	int &value3 = getValue_reference(5); // �̷������� �޾ƹ����� �Լ��� �Ҹ�Ǵ� local value�� reference�� �״�� �޾ƿ��� ��.
									     // pointer�� ������ ������ �߻���.

	cout << value3 << endl;
	cout << value3 << endl; // �̷��� 2�� ����غ��� ������ ���� ���ͼ� ���ϴ� ���� �޾ƿ� ���� ����. OS�� memory �Ҵ�Ǿ����� ������ ���°� �Ǿ���.
	                       
	//------------------------------------------------------------------------------------------------------------

	std::array<int, 100> my_array;
	my_array[30] = 10;
	get(my_array, 30) = 1024; // ������ �ڵ�� ������ ����� �Ѵ�. ���� ����Ѵ�. �Լ��� ���� ������ �޸� ������ ũ�� �޶����� �ʱ� ������ ������.
	get(my_array, 30) *= 10;

	cout << my_array[30] << endl;

	//------------------------------------------------------------------------------------------------------------

	S my_s = getStruct();
	my_s.b;

	//------------------------------------------------------------------------------------------------------------

	std::tuple<int, double> my_tp = getTuple();
	cout << std::get<0>(my_tp) << endl; // a
	cout << std::get<1>(my_tp) << endl; // b
	// ����ü �޴� ��ĺ��ٴ� ������ ������ ������

	//------------------------------------------------------------------------------------------------------------

	auto[a, d] = getTuple();
	cout << a << endl;
	cout << d << endl;
	// �� �� �̷��� �ֳ�

	return 0;
}
#include <iostream>
#include <array>

using namespace std;

// Reference pointer, const ����� �Լ� ���� ������ �����غ� ��.
void printLength(const array<int,5>& my_arr)
{
	cout << my_arr.size() << endl;
}

int main()
{
	int arr[5] = { 1,2,3,4,5 }; // �Ϲ����� array
	//int arr[] = { 1,2,3,4,5 }; [] index ������� �ʾƵ� ������ std::array�� �Ұ���
	
	std::array<int, 5> my_arr = { 1,2,3,4,5 }; // std::array, ������ �� ���־����.
	my_arr = { 0,1,2,3,4 };
	my_arr = { 30,6,7,3 }; // �������� 0���� ä����

	cout << my_arr[0] << endl;	 // memory access�� ��. performance ������ ���� at���ٴ� �̰� �� ��.
	cout << my_arr.at(0) << endl; // ����ó���� ��. ��� �˻�

	cout << my_arr.size() << endl; // size return
	printLength(my_arr);

	for (auto &element : my_arr)	// auto ��� �������.
		cout << element << " ";
	cout << endl;

	std::sort(my_arr.begin(), my_arr.end()); // Quick sort ��� �Լ�

	for (auto &element : my_arr)	
		cout << element << " ";
	cout << endl;

	std::sort(my_arr.rbegin(), my_arr.rend()); // reverse �˾Ƶα�
	
	for (auto &element : my_arr)
		cout << element << " ";
	cout << endl;
	
	return 0;
}
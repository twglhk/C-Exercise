#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

int main()
{
	int fibonacci[] = { 0,1,1,2,3,5,8,13,21,34 };
	
	// change array
	// 1. �Լ� param ���� ���޵Ǵ� ����̶� ���� ������ ����.
	for (int number : fibonacci)
		number = 10;

	// 2. Reference ������ �ٲ��ָ� ���� ������ ��������.
	for (int& number : fibonacci)
		number *= 10;

	// 3. auto& �� ����ϸ� : ���� �ڷ����� ���� �ڵ����� casting ����
	for (auto& number : fibonacci)
		number *= 30;

	// output. const auto& �̷� ������ �����ϸ� �� �ݺ������� number�� ���� x
	for (const auto& number : fibonacci)
		cout << number << " ";
	cout << endl;


	return 0;
}
#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	//int fibonacci[] = { 0,1,1,2,3,5,8,13,21,34 };
	vector<int> fibonacci = { 0,1,1,2,3,5,8,13,21,34 };

	// numeric_limits Ŭ���� ���ø��ε� ������� �پ��� �Ӽ��� ��ȸ�� �� ����.
	// lowest�� �־��� Ÿ��(int)�� ���� ���� ���ڸ� return ���ش�.
	int nMax_number = std::numeric_limits<int>::lowest();

	// �ݺ��ϸ鼭 vector ���� �߿� ���� ū ���� ã��
	for (const auto& number : fibonacci)
		nMax_number = std::max(nMax_number, number);

	cout << nMax_number << endl;

	return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string my_str("012345678");
	//string my_str("");
	/*
		string�� null char�� ����.
		���̸� ���� ������ �ֱ� �����̴�.
		������ ���̰� 0�̸� empty �Լ� true ���
	*/



	/*
		������ ����ϰ� �ʹٸ� ? reserve
	*/

	my_str.reserve(1000); // �ּ����� size �䱸 ����


	cout << std::boolalpha;
	cout << my_str.length() << endl;
	cout << my_str.empty() << endl;
	cout << my_str.size() << endl;
	cout << my_str.capacity() << endl; 

	/*
		�����Ͱ� �߰��� ���ɼ��� �ֱ� ������ �޸� relocation�� ���� �������� �Ѵ�.
		�� new/delete�� ���Ϸ��� �Ѵ�. �׷��� ���ڰ� �������ٸ� relocation�� ���� �ʰ� 
		������ �߰��� �ȴ�.
	*/

	cout << my_str.max_size() << endl;


	return 0;
}
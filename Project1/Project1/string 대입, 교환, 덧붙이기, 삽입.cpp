#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1("one");

	string str2;
	str2 = str1;
	str2 = "two";
	str2.assign("three").append(" ").append("four ").append("five");  
	// self reference return
	// assign�� �ٸ� ���� �Լ��� overloading �Ǿ� �ִ�.
	
	str2 += "six";
	str2 = str2 + "seven";
	str2.push_back('A');

	cout << str1 << " " << str2 << endl;
	std::swap(str1, str2);
	cout << str1 << " " << str2 << endl;
	std::swap(str1, str2);
	cout << str1 << " " << str2 << endl;

	str2.insert(2, "bbb");
	cout << str2 << endl;

	return 0;
}
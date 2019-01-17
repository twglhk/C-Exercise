#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

/*
	������ C++���� ���α׷��� �������� �÷��ְ� ���α׷����� �δ��� �ٿ��ִ� �͵��̴�.
	lambda �Լ�? �͸� �Լ�. ��Ÿ ������ ���� �����Ѵ�.
*/

void goodBye(const string& s)
{
	cout << "Good Bye " << s << endl;
}

class Object
{
public:
	void hello(const string & s)
	{
		cout << "Hello " << s << endl;
	}
};


int main()
{
	// 1. lambda �ڵ�

	// lambda-introducer []
	// lambda-parameter-declaration ()
	// lambda-return-type-clause ->
	// compound-statement { }
	auto func = [](const int& i)->void { cout << "Hellor World" << endl; };
	[](const int& i)->void { cout << "Hellor World" << endl; } (1234);

	{
		string name = "JackJack";
		
		// lambda-introducer�� �ܺ� ���� ���� �����ϰ� �����. 
		// reference & copy, scope ���� ������ ��� ��� �����ϰ� ����.
		[&]() {std::cout << name << endl; } ();
		[&name]() {std::cout << name << endl; } ();
		[=]() {std::cout << name << endl; } ();
		[name]() {std::cout << name << endl; } ();

		// class member �� ���� �ʹٸ� introducer�� this�� ok
		// [this]() {std::cout << name << endl; } ();

	}
	
	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	// �̷��� �� ���� �ִµ� ��� lambda�� �̷��� ������� �ʴ´�.
	// return type�� void�� ��� ����
	auto func2 = [](int val) {cout << val << endl; };
	for_each(v.begin(), v.end(), func2);

	// �̷��� �ٷ� param���� �ִ´�.
	for_each(v.begin(), v.end(), [](int val) {cout << val << endl; });

	// �ż��� �ڵ�
	cout << []() ->int { return 1; }() << endl;



	// 2. std::function �� std::bind

	// function pointer�� ü��ȭ ��Ų �� ==> std::function
	std::function<void(int)> func3 = func2;
	func3(123);
		
	// std::bind?? std::function���� param type�� �Է��ϰ� ���� ���� �� ����Ѵ�.
	// �ٵ� �̰� �� ���� ������ std::placeholders�� �˾ƾ� �Ѵ�.
	std::function<void()> func4 = std::bind(func3, 456);
	func4();

	{
		// Ŭ���� ��� �Լ��� pointer, instance�� pointer, hello �Լ��� param�� ����
		Object instance;
		auto f = std::bind(&Object::hello, &instance, std::placeholders::_1);

		// �׷��� �̷��� �ҋM
		f(string("World"));
		f("World");


		// ���� �׳� �Լ��� bind ����, �Լ��� ������, �Լ� param�� ����
		auto f2 = std::bind(&goodBye, std::placeholders::_1);

		// ���������� �ҋM
		f2(string("World"));
		f2("World");
	}

	return 0;
}
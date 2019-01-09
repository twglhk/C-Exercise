#include "Resource.h"
#include "AutoPtr.h"
#include <vector>
#include <string>

using namespace std;

/*
	�ֱ������� move semantics�� ����ϴ� ���� ���α׷��Ӱ� ����� ���� ���ϰ� ���� ���� �ִ�.
	std::move �� �̷� ��Ȳ�� ����� �� �ִ�.
*/

template<typename T>
void MySwap(T &a, T &b)
{
	// Call copy constructor
	/*T tmp = a;
	a = b;
	b = tmp;*/

	// Call move constructor
	// �� �� ���۵� Ŭ�������� move semantics�� �� ������ ���ƾ� �Ѵ�.
	T tmp { std::move(a) };
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	//AutoPtr<Resource> res1(new Resource(1000000));
	//cout << res1.m_ptr << endl;

	////AutoPtr<Resource> res2 = res1;
	//AutoPtr<Resource> res2 = std::move(res1);
	//// std::move�� ������ param�� && (R-value reference)�� �νĵ� �� �ֵ��� �ٲ��ش�.
	//// �׳� ���� �Ŀ����� copy semantics�� ������ ������
	//// std::move�� ������ move semantic�� ����ȴ�. 
	//// �� ������ ���� res1���� res2�� move�� �Ѵٴ� �ǹ̴� ������ res1���� ������ �۾��� ����
	//// �ʰڴٴ� ���� ���α׷��Ӱ� ������� ���̴�. R-value �� ����ٴ� �ǹ� ��ü��
	//// �ش� �ڵ� ���Ŀ��� ������� �ʰڴٴ� �ǹ��̱� �����̴�. 
	//// ������ �Ϲ����� ���, �� res1�� �ٽ� ����Ѵٴ� ��Ȳ���� move�� ������ �� �ִ�.

	//cout << res1.m_ptr << endl;
	//cout << res2.m_ptr << endl;


	/*{
		AutoPtr<Resource> res1(new Resource(3));
		res1->setAll(3);

		AutoPtr<Resource> res2(new Resource(5));
		res2->setAll(5);

		MySwap(res1, res2);

		res1->print();
		res2->print();
	}*/

	{
		vector<string> v;
		string str = "Hello";

		v.push_back(str); // copy semantics�� ����ϰڴٴ� �ǹ��̴�

		cout << str << endl;
		cout << v[0] << endl;

		v.push_back(std::move(str)); // move semantics�� ����ϰڴٴ� �ǹ��̴�.
									 // &&�� param���� �޴´�. ���������� vector�� move�� �����Ǿ� �ִ�.
		cout << str << endl;		 // move�� �Ǿ��� ������ �� �̻� str������ ����� �� ����.
		cout << v[0] << " " << v[1] << endl;

		str = "BACK";
		cout << str << endl;

	}

	{
		std::string x{ "abc" };
		std::string y{ "de" };

		std::cout << "x : " << x << std::endl;
		std::cout << "y : " << y << std::endl;

		MySwap(x, y);

		std::cout << "x : " << x << std::endl;
		std::cout << "y : " << y << std::endl;
	}

	return 0;
}
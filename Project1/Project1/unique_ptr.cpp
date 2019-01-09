#include <iostream>
#include <memory> // for unique_ptr
#include "Resource.h"

/*
	pointer�� ����Ű�� �������� �������� �� ������ ���� ��쿡 ����ϴ� smart pointer�� 
	unique_ptr�̴�.
*/

auto doSomething()
{
	// 1�� ���
	auto res1 = std::make_unique<Resource>(5);
	return res1;

	// 2�� ���
	return std::unique_ptr<Resource>(new Resource(5));

	// 3�� ���
	return std::make_unique<Resource>(5);   // ���������� move semantics ����
											// �������� Ȯ���� �Ѿ��. ������.
}

void doSomething2(std::unique_ptr<Resource> & res)
{
	res->setAll(100);
	res->print();
}

// ���࿡ L-value reference�� ������ error!!
// unique_ptr�� copy semantics�� ������� �ʴ´�.
// �̷��� �ְ� �ʹٸ� param�� ���� �� std::move(res)�� Ȱ���Ѵ�.
// move semantics�� Ȱ���� ������ ��� �ش� param�� �� �Լ��� local val�� ó���ȴ�.
// ������ �ٽ� �Լ� �ۿ��� ����� �� ���� �ȴ�.
//void doSomething2(std::unique_ptr<Resource> res)
//{
//	res->setAll(100);
//	res->print();
//
//}

// std::move�� �Ű���µ� �ٽ� �ۿ��� ����ϰ� �ʹٸ� �ٽ� �����ִ� ������ �����.
//auto doSomething2(std::unique_ptr<Resource> res)
//{
//	res->setAll(100);
//	res->print();
//  return res;
//}

// unique_ptr�� ����Ű�� instance�� pointer ���� �Ѱ��־ �۾��� �ϰ� ���� ����̴�.
void doSomething2(Resource* res)
{
	res->setAll(100);
	res->print();
}


int main()
{
	{
		//Resource *res = new Resource(1000000);

		std::unique_ptr<Resource> res(new Resource(100000));

		// early return or throw

		// delete res;
		// delete ������ ���� �ÿ� �Ҹ��ڰ� ȣ���� �� �ǰ� �ü���� �޸� ������ ó����
		// unique_ptr ����ϸ� delete �ڵ� ó�� ����
	}

	{
		std::unique_ptr<int> upi(new int); // �⺻ data type���� ��� ����

		// 1�� ���
		std::unique_ptr<Resource> res1(new Resource(5));

		// 2�� ���
		auto* ptr = new Resource(5);
		std::unique_ptr<Resource> res2(ptr);

		// 3�� ��� (����)
		auto res3 = std::make_unique<Resource>(5);
		//(==) std::unique_ptr<Resource> res3 = std::make_unique<Resource>(5);

		// 4�� ��� : �Լ��� ���� �ޱ�
		auto res4 = doSomething();

		res1->setAll(5);
		res1->print();

		std::unique_ptr<Resource> res5; // pointer value

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl; // nullptr�� �ƴϴ�. �ʱ�ȭ�� �Ǿ���
		std::cout << static_cast<bool>(res5) << std::endl; // nullptr

		// res5 = res1;  // unique_ptr�� copy semantics ����� �Ұ����ϴ�.
						 // �������� �� ������ �־�� �ϱ� �����̴�.

		res5 = std::move(res1);

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl; // nullptr�� �ƴϴ�. �ʱ�ȭ�� �Ǿ���
		std::cout << static_cast<bool>(res5) << std::endl; // nullptr
		
		if (res1 != nullptr) res1->print();
		if (res5 != nullptr) res5->print(); //(*res5).print();
	}

	{
		auto res1 = std::make_unique<Resource>(5);
		res1->setAll(1);
		res1->print();

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;

		doSomething2(res1);
		// res1 = doSomething2(res1); // �������� �ٽ� ���� ���� �� �ִ�.
		// doSomething2(res1.get());  // unique_ptr�� get()�� �̿��ϸ� ����Ű�� data�� pointer�� ��´�.

		std::cout << std::boolalpha;
		std::cout << static_cast<bool>(res1) << std::endl;

		res1->print();
	}

	{
		Resource *res = new Resource;
		std::unique_ptr<Resource> res1(res);
		std::unique_ptr<Resource> res2(res); // unique_ptr�� 2�� �����ϸ� delete�� 2�� �Ϸ���.
											 // ���� �̷��� ����ϸ� �� �ȴ�.

		delete res;							 // ���������� unique_ptr�� ������ delete �ϸ� �� �ȴ�.
	}


	return 0;
}
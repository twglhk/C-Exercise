#include <iostream>
#include <memory>
#include "Resource.h"

/*	
	unique_ptr�� �޸� �������� ���������� ������ �� �ִ� ����Ʈ �����Ͱ� 
	std::shared_ptr�̴�.
*/

void doSomething(std::unique_ptr<Resource> res)
{

}

int main()
{
	{

		// �Լ��� param���� ���� �� �̷� ������ ����� ���� �ʴ�.
		// doSomething(std::unique_ptr<Resource>(new Resource(1000))); 
		doSomething(std::make_unique<Resource>(1000)); // �� ������� ����� ���� ����.

		Resource *res = new Resource(3);
		res->setAll(1);
		std::shared_ptr<Resource> ptr1(res);
		// std::shared_ptr�� Ư¡�� ������ �� ������ �ϰ� �ִ��� count �Ѵٴ� ���̴�.

		ptr1->print();

		{
			//std::shared_ptr<Resource> ptr2(ptr1);
			//std::shared_ptr<Resource> ptr2(res); // �̷��� res�� ���� ����� �Ǹ� 
												 // str1�� share�ϴ� ���� ��. ���� �߻�

			// �ٸ� ����Ʈ �����͸� �����ϴ� ���� ���������� ���ϴ�.
			// ������ ���������� ����� ���� ����ȴ�.
			auto ptr2 = std::make_shared<Resource>(3);

			// Ȥ�� �ٸ� ����Ʈ �����͸� share�ϰ� �ʹٸ�
			auto ptr3 = ptr1;

			//ptr2->setAll(3);
			//ptr2->print();

			std::cout << "Going out of the block" << std::endl;
			// ptr1�� �����ϰ� �ֱ� ������ ptr2�� ���� ������ ������� delete�� ���� �ʴ´�.
		}

		ptr1->print();

		std::cout << "Going out of the outer block" << std::endl;

	}// ������ shared_ptr�� ���������� destructor�� ȣ�� �ȴ�.

	// unique_ptr���� ������ ���� Ư¡

	return 0;
}
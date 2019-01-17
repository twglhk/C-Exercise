#include <iostream>
#include <memory>
#include <string>

/*
	shared_ptr�� ����� �� �߻��ϴ� ���� ������ ������ weak_ptr�� �ذ��� �� �ִ�.

*/

class Person
{
private:
	std::string m_name;
	//std::shared_ptr<Person> m_partner;
	std::weak_ptr<Person> m_partner; 

public:
	Person(const std::string &name) : m_name(name)
	{
		std::cout << m_name << " created\n";
	}

	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
	{
		if (!p1 || !p2)
			return false;

		p1->m_partner = p2;
		p2->m_partner = p1;

		std::cout << p1->m_name << " is partnered with " << p2->m_name << "\n";

		return true;
	}

	const std::shared_ptr<Person> getPartner() const
	{
		return m_partner.lock();
	}

	const std::string & getName() const
	{
		return m_name;
	}
};

int main()
{
	auto lucy = std::make_shared<Person>("lucy");
	auto ricky = std::make_shared<Person>("ricky");

	partnerUp(lucy, ricky);

	// object�� �Ҹ��ڸ� ȣ���� �� �̹� �ٸ� shared_ptr�� �����ϱ� ������
	// ����� shared_ptr�� ���� ���� ���� �ȴ�. ==> ��ȯ ������ ����!!
	// weak_ptr�� ����Ѵٸ� �� ���� �ذ��� �����ϴ�.
	// �� weak_ptr�� ���������� ����� �Ұ����ϴ�. 
	// lock()�̶�� �Լ��� ���� shared_ptr�� �ٲ㼭 ����� �־�� �Ѵ�.

	std::cout << lucy->getPartner()->getName() << std::endl;

	return 0;
}
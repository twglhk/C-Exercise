#include <iostream>
#include <exception>
#include <string>

class CustomException : public std::exception
{
public:
	const char* what() const noexcept override // noexcept : �� �ȿ����� ���ܸ� ������ �ʴ´� (C++ 11)
	{
		return "Custom Exception";
	}
};

int main()
{
	try
	{
		//std::string s;
		//s.resize(-1); // resize �� ũ�Ⱑ �̻��� ��� �Լ� ���ο��� throw�� �Ѵ�.

		// throw std::runtime_error("Bad thing happend"); // ���Ѵٸ� std�� exception�� ���� throw �� ���� �ִ�.
		throw CustomException();

	}
	//catch (std::length_error & exception) // ��������� exception ó��
	//{
	//	std::cerr << "Length Error!!" << std::endl;	
	//	std::cerr << exception.what() << std::endl;
	//}
	catch (std::exception & exception) // exception�� ��� exception�� �θ� Ŭ����
	{
		std::cout << typeid(exception).name() << std::endl; // � �������� �˰� ���� ��� ���.
		std::cerr << exception.what() << std::endl;
	}

	return 0;
}
#pragma once

#include <iostream>

// std::auto_ptr<int>;  c++ 17���� �� ���̰� ��.
// �Ʒ� Ŭ������ AutoPtr�� ����� ������ ��
template <class T>
class AutoPtr
{
public:
	T *m_ptr;

public:
	AutoPtr(T *ptr = nullptr)
		: m_ptr(ptr)
	{
		std::cout << "AutoPtr default constructor" << std::endl;
	}

	~AutoPtr()
	{
		std::cout << "AutoPtr destructor" << std::endl;
		if (m_ptr != nullptr) delete m_ptr;
	}

	AutoPtr(const AutoPtr &a)
	{
		std::cout << "AutoPtr copy constructor" << std::endl;

		// deep copy
		m_ptr = new T;
		*m_ptr = *a.m_ptr; // Resource ���� assignment ����

		/*m_ptr = a.m_ptr;
		a.m_ptr = nullptr;*/
	}

	AutoPtr& operator = (const AutoPtr &a)
	{
		std::cout << "autoptr copy assignment" << std::endl;

		if (&a == this)			// prevent self assignment
			return *this;

		if (m_ptr != nullptr) delete m_ptr;

		// deep copy
		m_ptr = new T;
		*m_ptr = *a.m_ptr;
		return *this;

		/*delete m_ptr;
		m_ptr = a.m_ptr;
		a.m_ptr = nullptr;
		return *this;*/
	}

	// Copy constructor & Copy assignment �� ������ ���ƹ����� ���
	//AutoPtr(const AutoPtr& a) = delete;
	//AutoPtr& operator= (const AutoPtr& a) = delete;


	AutoPtr(AutoPtr&& a) // R-value reference 
		: m_ptr(a.m_ptr)
	{
		a.m_ptr = nullptr;  // really necessary? Risk�� ���� ���ɼ��� �ֱ� ����	
							// Destructor ������ nullptr�� �ƴϸ� delete ȣ��
		std::cout << "AutoPtr move constructor" << std::endl;
	}

	AutoPtr& operator= (AutoPtr&& a) // R-value reference 
	{
		std::cout << "AutoPtr move assignment" << std::endl;

		if (&a == this)
			return *this;	// prevent self-assignment

		if (!m_ptr) delete m_ptr;

		// shallow copy
		// move semantics
		m_ptr = a.m_ptr;	// Resource�� assignment ȣ���� �ƴ϶� pointer�� �Ű��ִ� �۾�
		a.m_ptr = nullptr;  // really necessary? �������� ������ ǥ�����ش�. 

		return *this;
	}



	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }
	bool isNull() const { return m_ptr == nullptr; }
};
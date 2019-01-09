#include <iostream>
#include <memory>

using namespace std;

class A
{
public:
	~A()
	{
		throw "error";  // �ϸ� �� �Ǵ� ��. 
					    // �޸� �Ҵ� ���� �������� ���ܸ� ���������� ���� �� ���ٰ� �����Ϸ��� �ؼ��Ѵ�.
						// �����ε� ��Ÿ�� ������ ���.
	}
};

int main()
{
	// for�� �ȿ� ����ó���� ���� �ʴ´�. 
	// performance�� ���� ��������.
	// �ֱٿ� zero cost exception�� ������ �ϳ� ���������� runtime���� ��ȿ�����̶�� �Ѵ�.

	// ��� error�� ����ó�� ���� ���ƶ�.
	// ���������� �۵��ؾ��ϴ� �ڵ���� if�� �Ÿ��� (ex. ����� �Է� ��.)
	
	// ��Ʈ��ũ ��� �л� ó��, ���� ó�� Ȥ�� �ϵ������ I/O ����� ����ó���� Ȱ���Ѵ�.
	// �������� ��å�� �����ϱ� ����� ȯ�濡�� ����ó���� Ȱ���Ѵ�.

	try
	{
		int *i = new int[1000000];
		unique_ptr<int> up_i(i); // unique_ptr�� �ִٸ� ����ó���� ���� ����� �� �޸� �Ҵ��� �������ش�!!
								 // Smart pointer!!

		// do something with i
		throw "error";

		//delete[] i; // ������� ����. throw ������. �޸� ������ �߻��� �� �ִ�!!

		//A a;
	}
	catch(...)
	{
		cout << "Catch" << endl;
	}
	
	return 0;
}
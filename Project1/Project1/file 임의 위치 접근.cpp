#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

/*
	�̹� �����ϴ� ������ �߰� �κ� ����
	�ʿ��� �Ϻθ� �а� �ͱ⵵ ��.
	�̷� ������ ������ ��ġ ���� �ϴ� ����̴�.
*/

int main()
{
	const string filename = "my_file.txt";

	// make a file
	{
		ofstream ofs(filename);

		for (char i = 'a'; i <= 'z'; ++i)
			ofs << i;
		ofs << endl;
	}

	// read the file
	{
		ifstream ifs(filename);

		// file ó�� ���� 5 byte�� �̵��ؼ� read
		ifs.seekg(5); // ifs.seekg(5, ios::beg); // ���� ��ġ�� ���� 5 byte
		cout << (char)ifs.get() << endl;

		// ���� cursor ��ġ���� 5 byte �̵��ؼ� read
		ifs.seekg(5, ios::cur);
		cout << (char)ifs.get() << endl;

		// ������ ���� x byte
		ifs.seekg(0, ios::end);
		cout << ifs.tellg() << endl; // ��ġ�� ���ڷ� return

		// cursor ���� line read
		string str;
		getline(ifs, str); 

		cout << str << endl;
	}

	{ /* file�� �� �� ��� read/write �� �ϱ� */
		//fstream iofs(filename, ios::in | ios::out); // flag ������ ���������� ���� in/out �Ѵ� ����
		fstream iofs(filename);

		iofs.seekg(5);
		cout << (char)iofs.get() << endl; // read

		iofs.seekg(5);
		iofs.put('A'); // write
	}

	return 0;
}
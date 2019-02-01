#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // exit()
#include <sstream>

using namespace std;

int main()
{
	// writing
	if (true)
	{
		// ASCII , ios::app, ios::binary ,  ������ ���ٸ� ���� �����Ѵ�.
		//ofstream ofs("my_first_file.dat");
		//ofstream ofs("my_first_file.dat", std::ios::binary);
		ofstream ofs("my_first_file.dat", std::ios::app);

										 
		//ofs.open("my_first_file.dat");   // �����ڷ� �ϰų� open()���� �ҷ��´�.
										   // ASCII type�� text file�� �����Ѵ�. == �޸��� ���� ����
										   // ASCII�� ������ �ʹ� ����. �׷��� binary ������ �� ����
		

		if (!ofs)
		{
			cerr << "Couldn't open file" << endl;
			exit(1);
		}

		// ASCII writing type
		// stream�̱� ������ ������ stream ���� ���ó�� ��� �����ϴ�.
		ofs << "Line 1" << endl;
		ofs << "Line 2" << endl;


		// Binary writing type
		//const unsigned num_data = 10;
		//ofs.write((char*)&num_data, sizeof(num_data));

		//for (int i = 0; i < num_data; ++i)
		//	ofs.write((char*)&i, sizeof(i));


		// ofs.close(); // not necessary , ������ ������ �Ҹ��ڰ� �˾Ƽ� ������ �ݾ��ش�.
	}
									  
	// reading
	if (true)
	{
		ifstream ifs("my_first_file.dat");
		
		if (!ifs)
		{
			cerr << "Cannot open file" << endl;
			exit(1);
		}

		// ASCII reading type
		while (ifs) // ���� ������ �����ϸ� false return
		{
			std::string str;
			getline(ifs, str);

			std::cout << str << endl;
		}

		// Binary reading type
		//unsigned num_data = 0;
		//ifs.read((char*)&num_data, sizeof(num_data));

		//for (unsigned i = 0; i < num_data; ++i)
		//{
		//	int num;
		//	ifs.read((char*)&num, sizeof(num));

		//	std::cout << num << endl;
		//}
	}


	return 0;
}
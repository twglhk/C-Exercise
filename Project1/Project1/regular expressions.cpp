#include <iostream> 
#include <regex>

using namespace std;

/* 
	� ���ڿ��� ����ڰ� ���ϴ� ���Ŀ� ������ �ִ°� �ƴѰ� �Ǻ��ϴ� ���� 
	����� �����͸� ó���� �� �߿��� �����̴�.
 	ex) �̸���, ��й�ȣ �� �ּ����� ���Ŀ� �´°� �Ǻ��ؾ���.

	��ȿ�� �˻縦 ������ �����ϴ� ���� ���̴�. ���Խ��� ����ϸ� �����ϴ�

	Reference : 
	http://www.cplusplus.com/reference/regex/ECMAScript/
*/

int main()
{
	//regex re("\\d");  // \d�� �����ΰ� �Ǻ��ϴ� ���̴�. 
	//regex re("\\d+"); // +�� ���� �������� ���� �Էµ� ����
	//regex re("[ab]");	// a�� b�� ��. 1���ڸ� ����
	//regex re("[[:digit:]]{3}"); // �ٱ� �� ���ȣ ���� ���ڴ� ����̴�. �߰�ȣ�� ����
	//regex re("[A-Z]+");		  // A-Z ���� ���� ��� ���� ���
	//regex re("[A-Z]{1,5}");	  // A-Z ���� �ּ� 1��, �ִ� 5�� ���
	regex re("([0-9]{1})([-]?)([0-9]{1,4})"); // ?�� �־ �ǰ� ��� �ȴٴ� �ǹ�

	string str;

	while (true)
	{
		getline(cin, str);

		if (std::regex_match(str, re))
			cout << "Match" << endl;
		else
			cout << "No Match" << endl;

		// print matches
		{
			auto begin = std::sregex_iterator(str.begin(), str.end(), re);
			auto end = std::sregex_iterator();
			for (auto itr = begin; itr != end; ++itr)
			{
				std::smatch match = *itr;
				cout << match.str() << " ";
			}
			cout << endl;
		}

		cout << endl;
	}
}



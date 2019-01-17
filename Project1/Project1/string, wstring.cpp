#include <iostream>
#include <string>
#include <cstddef>
#include <locale>

int main()
{
	// c-style string example
	{
		char *strHello = new char[7];
		strcpy_s(strHello, sizeof(char) * 7, "hello!");
		std::cout << strHello << std::endl;
	}

	// basic_string<>, string, wstring
	{
		std::string string;
		std::wstring wstring;

		/*
		using string = basic_string<char, char_traits<char>, allocator<char>>;
		using wstring = basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t>>;
		
		���� basic_string������ �ٸ� instanciation
		*/

		wchar_t wc; // unsigned short
					// ������ ����� ���� �Դ� char ǥ���� �� ����.
					// wide-character/unicode
					// ���� ���� �� localization �� ���� �ʿ��ϴ�.
	}


	// wstring example
	{
		const std::wstring texts[] =
		{
			L"�ȳ��ϼ���?"
			// ��Ÿ �ٸ� ��� ���
		};

		std::locale::global(std::locale(""));
		std::wcout.imbue(std::locale()); // wide cout

		for (size_t i = 0; i < 1; ++i)
			std::wcout << texts[i] << std::endl;
	}


	return 0;
}
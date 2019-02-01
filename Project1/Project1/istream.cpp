#include <iostream>
#include <string>
#include <iomanip> // input/output manipulator

using namespace std;

int main()
{
char buf[5];

//cin >> buf;
cin >> setw(5) >> buf;	// �ִ� 10���ڸ� �Է� ���� �� �ְ� ���ش�.
					    // ��Ÿ�� ������ �߻���Ű�� �ʰ� 5���� ���.
						// input stream buffer���� ������ ������ char�� �����´�.
cout << buf << endl;

// �������� ���� �����ʹ� buffer�� �����ִ�. 
// �߰��� cin�� ����ϸ� buffer�� ���� �����͸� ��� �����´�.
cin >> setw(5) >> buf;
cout << buf << endl;

cin >> setw(5) >> buf;
cout << buf << endl;


// ������ ������.
char ch;
while (cin >> ch)
	cout << ch;

// cin.get()�� ����ϸ� ���鵵 ��� ����������.
char ch;
while (cin.get(ch))
	cout << ch;

// buffer���� �о�� �������� ����� ������ �� �ִ�. ���鵵 ����
// ���� buffer�� �����Ͱ� �������� �� �ִ�.
char buf[5];
cin.get(buf, 5);
cout << cin.gcount() << " " << buf << endl; // �� ���ڸ� �о����� count�Ѵ�.

// line ������ �о�´�. line�� ���� �б� ������ buffer�� �������.
// getline()�� �ٹٲ� char ���� ���� read�Ѵ�.
char buf[100];
cin.getline(buf, 100);
cout << cin.gcount() << " " << buf << endl;

cin.getline(buf, 100);
cout << cin.gcount() << " " << buf << endl;

// string ������ read�Ѵ�. buf ũ�⿡ ������ ����.
string buf;
getline(cin, buf);
cout << cin.gcount() << " " << buf << endl; // cin���� ���� ���� �ƴϱ� ������ count �� 0

// cin.ignore �� ���� ���ڸ� �Է��� ������ŭ �����Ѵ�.
char buf[1024];
cin.ignore(2);
cin >> buf;
cout << buf << endl;

// cin.peek()�� �ԷµǴ� ������ �� ���ڸ� �о���⸸ �Ѵ�.
char buf[1024];
cout << (char)cin.peek() << endl;
cin >> buf;
cout << buf << endl;

// unget()�� �������� ���� ���ڸ� �ٽ� buffer�� �ִ´�.
char buf[1024];
cin >> buf;
cout << buf << endl;
cin.unget();
cin >> buf;
cout << buf << endl;

// putback()�� buffer�� �ٽ� �����͸� �ִ´�.
char buf[1024];
cin >> buf;
cout << buf << endl;
cin.putback('A');
cin >> buf;
cout << buf << endl;


// �̷��� �����͸� �����ؼ� ���� �������� ���� �Է� ����
int i;
float f;

cin >> i >> f;
cout << i << " " << f << endl;
	
return 0;
}

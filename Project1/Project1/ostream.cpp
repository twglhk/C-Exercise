#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

	/* flag�� ������ ��� �ɼ� �����ϱ� */

	{ /* +��ȣ �Բ� ����ϱ� */
		cout.setf(std::ios::showpos);   // + ��ȣ�� ��µȴ�.
		cout << 108 << endl;

		cout.unsetf(std::ios::showpos); // + ��ȣ ��� ����
		cout << 200 << endl;
	}

	cout << endl;

	{ /* ���� mode �ٲٱ� */
		cout.unsetf(std::ios::dec); // hex�� ����ϱ� ���ؼ� 10���� ��� off
		cout.setf(std::ios::hex);   // 16���� ��� on
		cout << 108 << endl;

		cout.unsetf(std::ios::hex); // hex ����
		cout << 108 << endl;

		cout.setf(std::ios::hex, std::ios::basefield); // basefield�� hex�� �ٲ��ش�.
		cout << 108 << endl;

		cout.unsetf(std::ios::hex);	// hex ����


		// �� �����ϰ� mode ��ȯ�ϱ�
		cout << std::hex;
		cout << 108 << endl;
		cout << 109 << endl;

		cout << std::dec;
		cout << 108 << endl;
	}

	cout << endl;

	{/* �빮�� ����ϱ� */
		cout << std::hex << std::uppercase; // #include <iomanip>
		cout << 108 << endl;

		cout << std::dec;
	}

	cout << endl;

	{/* boolalpha ����ϱ� */
		cout << std::boolalpha;
		cout << true << " " << false << endl;
	}
	
	cout << endl;

	{/* �Ҽ��� ���е� �����ϱ� */
		cout << std::defaultfloat;	// �⺻ type. �ִ� �״�� ���
		cout << 123.456 << endl;

		cout << std::showpoint;						// �Ҽ��� ��� (�Ʒ� �ڸ��� ���)
		cout << setprecision(3) << 123.456 << endl;	// ���ʺ��� �ִ� 3�ڸ� ���ڱ��� ǥ�� (123)
		cout << setprecision(4) << 123.456 << endl; // 4�ڸ����� ǥ��. �� 123.5 (�ݿø�)
		cout << setprecision(5) << 123.456 << endl;
		cout << setprecision(6) << 123.456 << endl;
		cout << setprecision(7) << 123.456 << endl;
		cout << setprecision(8) << 123.456 << endl;

		cout << std::fixed;			// �Ҽ��� �ڸ��� ����
		cout << setprecision(3) << 123.456 << endl;
		cout << setprecision(4) << 123.456 << endl;
		cout << setprecision(5) << 123.456 << endl;

		// �� ���ڸ� ���� ���� ���ڵ��� ���� ��ŭ �Ҽ��� ����.
		cout << std::scientific << std::uppercase;    
		cout << setprecision(3) << 123.456 << endl;
		cout << setprecision(4) << 123.456 << endl;
		cout << setprecision(5) << 123.456 << endl;
	}

	cout << endl;

	{ /* setw()�� ��ĭ ����� */
		cout << -12345 << endl;
		cout.fill('*');	// ����� ��ĭ�� ���� ä���ش�.
		cout << std::setw(10) << -12345 << endl;
		cout << std::setw(10) << std::left << -12345 <<  endl;
		cout << std::setw(10) << std::right << -12345 << endl;
		cout << std::setw(10) << std::internal << -12345 << endl;	// ��ȣ�� ���� ���̿� ��ĭ
	}

	return 0;
}
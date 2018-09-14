#include <iostream>
#include <fstream>

using namespace std;

class Point
{
private:
	double m_x, m_y, m_z;

public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0) 
		: m_x(x), m_y(y), m_z(z)
	{

	}

	double getX() { return m_x; }
	double getY() { return m_y; }
	double getZ() { return m_z; }


	// ���� ����� �̷��� �ϴµ� ���ŷο� �� �ִ�.
	/*void Print()
	{
		cout << m_x << " " << m_y << " " << m_z;
	}*/


	// ����� overloading
	friend std::ostream& operator << (std::ostream& out, const Point& point)
	{
		out << point.m_x << " " << point.m_y << " " << point.m_z;
		return out; // �� return�� �ϴ� ������ chaining �����̴�. ���޾� �ٸ� ���� ����� �� �ʿ��ϴ�. 
	}

	friend std::istream& operator >> (std::istream& in, Point& point)
	{
		in >> point.m_x >> point.m_y >> point.m_z;
		return in; // �� return�� �ϴ� ������ chaining �����̴�. ���޾� �ٸ� ���� �Է��� �� �ʿ��ϴ�. 
	}
};

int main()
{
	//Point p1(0.0, 0.1, 0.2), p2(3.4, 1.5, 2.0);
	Point p1, p2;

	// Output stream�� ����. ���� ��µ� �״�� �����ϴ�.
	ofstream of("text.txt");
	
	// Input file stream
	ifstream ifs("text.txt", std::ifstream::in); // 2��° param�� mode�� ���� ���̴�. in�� ���� input operation mode


	// �Լ� ȣ��� print �ϱ�
	/*p1.Print(); 
	cout << "// ";
	p2.Print();*/

	// Operator overloading 
	cin >> p1 >> p2;
	cout << p1 << " / " << p2 << endl;

	// File writing
	of << p1 << " " << p2 << endl; // �̷� ������ ���� ��µ� �����ε����� �����ϰ� ����.

    // File Reading
	ifs >> p1 >> p2;
	cout << p1 << " / " << p2;
	
	of.close();
	ifs.close();

	return 0;
}
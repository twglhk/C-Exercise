#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main()
{
	vector<int> container;
	list<int> li;

	for (int i = 0; i < 10; ++i)
		container.push_back(i);

	auto iter = min_element(container.begin(), container.end());
	cout << *iter << endl;

	iter = max_element(container.begin(), container.end());
	cout << *iter << endl;

	cout << endl;

	// find�� user defined container���� ����ϰ� �ʹٸ� �� ������ �����ε��� �ʿ��ϴ�.
	iter = find(container.begin(), container.end(), 3);
	container.insert(iter, 128);
	for (const auto& e : container)
		cout << e << " ";
	cout << endl;


	// list�� vector�� ���� �����ѵ� �ٸ� sort�� reverse�� ��� �Լ��� �����Ǿ� �ִ�.
	li.sort();
	sort(container.begin(), container.end());
	for (const auto& e : container)
		cout << e << " ";
	cout << endl;

	li.reverse();
	reverse(container.begin(), container.end());
	for (const auto& e : container)
		cout << e << " ";
	cout << endl;



	return 0;
}
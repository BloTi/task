#include <iostream>
#include <vector>
#include <functional>
using namespace std;

using comparator = std::function<bool(int a, int b)>;

void booble(vector<int>& vec, unsigned int size, comparator comp)
{
	int temp = 0;
	
	for (int j(0); j < size - 1; ++j)
	{
		for (int i(0); i < size - j - 1; ++i)
		{
			if (comp(vec.at(i), vec.at(i + 1)))
			{
				temp = vec.at(i);
				vec.at(i) = vec.at(i+1);
				vec.at(i+1) = temp;
			}
		}
	}
}

int main()
{
	vector<int> vec;
	for (int i(0); i < 10; ++i)
		vec.push_back(rand() % 20);

	int size = vec.end() - vec.begin();

	for (auto it : vec)
		cout << it << " ";
	cout << endl;


	booble(vec, size, [](int a, int b) {return a > b; });

	for (auto it : vec)
		cout << it << " ";
	cout << endl;

	system("pause");
	return 0;
}
#include <iostream>
using namespace std;

template<typename T>
void sort(T* arr, const int size)
{
	unsigned int min;
	T temp;
	for (int j(size - 1); j >= 0; --j)
	{
		temp = arr[(size - 1) - j];
		min = (size - 1) - j;
		for (int i((size - 1) - j); i < size; ++i)
		{			
			if (arr[i] < arr[min])
				min = i;
		}
		arr[(size - 1) - j] = arr[min];
		arr[min] = temp;
	}
}

int main()
{
	const int size = 10;
	double doub_arr[size] = { 13, 5, 3.2, 0.05, 80, -931.23, -2, 0, 74, -0.31 };
	char ch_arr[size] = { 'A', 'f', 'c', 'v', 'r', 'R', 'Y', 'l', 'b', 'A' };

	for (int i(0); i < size; ++i)
		cout << doub_arr[i] << " ";
	cout << endl;

	for (int i(0); i < size; ++i)
		cout << ch_arr[i] << " ";
	cout << endl;

	sort(doub_arr, size);

	sort(ch_arr, size);

	for (int i(0); i < size; ++i)
		cout << doub_arr[i] << " ";
	cout << endl;

	for (int i(0); i < size; ++i)
		cout << ch_arr[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}
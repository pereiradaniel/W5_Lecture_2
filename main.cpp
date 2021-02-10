#include <iostream>
using namespace std;

void display(int* arr, size_t size)
{
	cout << arr[0];
	for (auto i = 1u; i < size; ++i)
		cout << ", " << arr[i];
	cout << endl;
}

bool asc(int a, int b)
{
	// Should the values be switched?
	return a > b;
}

bool desc(int a, int b)
{
	return a < b;
}

void bubbleSort(int* arr, size_t n, bool (*cmp)(int, int))
{
	for (auto i = 0u; i < n - 1; ++i)
		for (auto j = i + 1; j < n; ++j)
			if (cmp(arr[i], arr[j])) // Should I switch them?
			{
				// switch
				auto tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
}

int main()
{
	bool (*cmpF)(int, int) = nullptr; // pointer to a function that returns bool.

	char choice = '\0';
	cout << "Asc/Desc?: ";
	cin >> choice;

	if (choice == 'a')
		cmpF = asc;
	else
		cmpF = desc;

	int arr[]{ 4, 6, 98, 1, -5, 5, 78 };
	display(arr, sizeof (arr) / sizeof (arr[0]));

	bubbleSort(arr, 7, cmpF);
	display(arr, 7);
}
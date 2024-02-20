#include <iostream>
#include <string>
using namespace std;

void arr_generator(string* const arr, const int size);
void arr_printer(const string* const arr, const int size);
void add_in_arr(string*& arr, int& size, int& number, const string value);

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите размер массива: ";
	int size;
	cin >> size;
	string* arr = new string[size];
	arr_generator(arr, size);
	arr_printer(arr, size);
	cout << "Введите номер добовляемого элемента: ";
	int number;
	cin >> number;
	number--;
	cout << "Введите значение добовляемого элемента: ";
	string value;
	cin >> value;
	add_in_arr(arr, size, number, value);
	arr_printer(arr, size);
	delete[] arr;
	return 0;
}

void arr_generator(string* const arr, const int size)
{
	cout << "Введите элемента массива:\n";
	for (int i = 0; i < size; i++)
		cin >> arr[i];
}

void arr_printer(const string* const arr, const int size)
{
	cout << "Наш массив:\n";
	for (int i = 0; i < size; i++)
		cout << arr[i] << "\t";
	cout << endl;
}

void add_in_arr(string*& arr, int& size, int& number, const string value)
{
	size++;
	string* new_array = new string[size];
	for (int i = 0; i < number; i++)
		new_array[i] = arr[i];
	new_array[number] = value;
	for (int i = number + 1; i < size; i++)
		new_array[i] = arr[i - 1];
	delete[] arr;
	arr = new_array;
}


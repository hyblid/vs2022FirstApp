#include <iostream>

template<typename T, typename V>
V linear_search(const T arr[], int size, V value_to_find) {
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value_to_find)
		{
			return i;
		}
	}
	return -1;
}

template<typename T, typename V>
V binary_search(const T arr[], int size, V value_to_find) {
	int first = 0;
	int middle = 0;
	int last = size - 1;
	while (first <= last)
	{
		middle = (first + last) / 2;
		if (arr[middle] == value_to_find) {
			return middle;
		}
		else if (arr[middle] > value_to_find) {
			last = middle - 1;
		}
		else {
			first = middle + 1;
		}
	}
	return -1;
}

template<typename T>
void bubble_sort(T arr[], T size) {
	bool is_swap;
	T temp;
	do {
		is_swap = false;
		for (int i = 0; i < (size - 1); i++)
		{
			if (arr[i] > arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				is_swap = true;
			}
		}
	} while (is_swap);
}

template<typename T>
void selection_sort(T arr[], T size) {
	T min_index, min_value;
	for (int i = 0; i < (size - 1); i++)
	{
		min_index = i;
		min_value = arr[i];
		for (int j = (i + 1); j < size; j++)
		{
			if (arr[j] < min_value)
			{
				min_index = j;
				min_value = arr[j];
			}
		}
		arr[min_index] = arr[i];
		arr[i] = min_value;
	}
}

const int item_length = 15;
void alpha_sort(char items[][item_length], int size) {
	bool is_swap;
	char temp[item_length] = "";
	do {
		is_swap = false;
		for (int i = 0; i < (size - 1); i++)
		{
			if (strcmp(items[i], items[i + 1]) > 0)
			{
				strncpy(temp, items[i], item_length - 1);
				strncpy(items[i], items[i + 1], item_length - 1);
				strncpy(items[i + 1], temp, item_length - 1);
				is_swap = true;
			}
		}
	} while (is_swap);
}
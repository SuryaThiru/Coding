#include "merge_sort.h"

#include <iostream>

using namespace std;

int main() {
	int len;
	cout << "length of array : ";
	cin >> len;
	int arr[len];

    for (int i(0); i < len; i++)
        cin >> arr[i];

    cout << "input array:" << endl;
	for (int i : arr) 
		cout << i << " ";
	cout << endl;
	
	mergeSort(arr, 0, len-1);

	cout << "array after sort:" << endl;
	for (int i : arr)
		cout << i << " ";
	cout << endl;
}

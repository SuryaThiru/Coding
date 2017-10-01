#pragma once

#include <iostream>
using namespace std;


void merge(int *arr, int left, int mid, int right) {
	int len1 { mid - left + 1 }, len2 { right - mid };
	int *newArr1 = new int[len1];
	int *newArr2 = new int[len2];

	for (int i(left); i <= mid; i++)
		newArr1[i - left] = arr[i];

	for (int i(mid+1); i <= right; i++)
		newArr2[i - mid - 1] = arr[i];

	int m(0), n(0);

	for (int i = 0; i < len1 + len2; i++) {
		if ((m == len1) && (n != len2))
			arr[i+left] = newArr2[n++];

		else if ((n == len2) && (m != len1))
			arr[i + left] = newArr1[m++];

		else {
			if (newArr1[m] < newArr2[n])
				arr[i + left] = newArr1[m++];
			else
				arr[i + left] = newArr2[n++];
		}
	}

	delete[] newArr1;
	delete[] newArr2;
}


void mergeSort(int *arr, int left, int right) {
	if (left < right) {
		int mid = (right + left) / 2;

		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

/* 
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/

#include <bits/stdc++.h>
using namespace std;

/* Standard Binary Search function*/
int LowIndexbinarySearch(int arr[], int low,
						 int high, int key)
{
	printf("\nLow index search: Low = %d High=%d key=%d", low, high, key);
	if (high < low)
		return -1;

	int mid = (low + high) / 2; /*low + (high - low)/2;*/
	if (key == arr[mid])
	{
		int lowIndex = mid;
		int moreLowIndex = LowIndexbinarySearch(arr, low, mid - 1, key);

		if (moreLowIndex != -1 && moreLowIndex < lowIndex)
			lowIndex = moreLowIndex;

		return lowIndex;
	}

	else if (key < arr[mid])
	{
		return LowIndexbinarySearch(arr, low, mid - 1, key);
	}
	else if (key > arr[mid])
	{
		return LowIndexbinarySearch(arr, mid + 1, high, key);
	}
	else
	{
		return -1;
	}
}

int HighIndexbinarySearch(int arr[], int low,
						  int high, int key)
{
	printf("\nHigh Index Search: Low = %d High=%d key=%d", low, high, key);
	if (high < low)
		return -1;

	int mid = (low + high) / 2; /*low + (high - low)/2;*/
	if (key == arr[mid])
	{
		int highIndex = mid;
		int moreHightIndex = HighIndexbinarySearch(arr, mid+1, high, key);

		if (moreHightIndex != -1 && moreHightIndex > highIndex)
			highIndex = moreHightIndex;

		return highIndex;
	}

	else if (key < arr[mid])
	{
		return HighIndexbinarySearch(arr, low, mid - 1, key);
	}
	else if (key > arr[mid])
	{
		return HighIndexbinarySearch(arr, mid + 1, high, key);
	}
	else
	{
		return -1;
	}
}

/* Driver program to check above functions */
int main()
{
	// Let us search 3 in below array
	int arr1[] = {5,7,7,8,8,10};
	int n = sizeof(arr1) / sizeof(arr1[0]);
	int key = 6;

	// Function calling
	cout << "\nLow Index of the element is : " << LowIndexbinarySearch(arr1, 0, n - 1, key) << endl;
	cout << "\nHigh Index of the element is : " << HighIndexbinarySearch(arr1, 0, n - 1, key) << endl;

	return 0;
}
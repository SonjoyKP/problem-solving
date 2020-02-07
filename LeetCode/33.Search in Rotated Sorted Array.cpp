/* C++ Program to search an element 
   in a sorted and pivoted array
https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
https://leetcode.com/problems/search-in-rotated-sorted-array/
*/



#include <bits/stdc++.h>
using namespace std;

/* Standard Binary Search function*/
int binarySearch(int arr[], int low,
				 int high, int key)
{
	printf("\nLow = %d High=%d key=%d", low, high,key);
	if (high < low)
		return -1;

	int mid = (low + high) / 2; /*low + (high - low)/2;*/
	if (key == arr[mid])
		return mid;
	else if (arr[low] <= arr[mid])
	{
		if( arr[low] <= key &&  key <= arr[mid])
			return binarySearch(arr, low, mid, key);
		else
			return binarySearch(arr, mid+1, high, key);
		
	}
	else
	{
		if( arr[mid+1] <= key && key <= arr[high])
			return binarySearch(arr, mid+1, high, key);
		else
			return binarySearch(arr, low, mid, key);
	}
}

/* Searches an element key in a pivoted 
   sorted array arr[] of size n */
int pivotedBinarySearch(int arr[], int n, int key)
{
	return binarySearch(arr, 0, n - 1, key);
}

/* Driver program to check above functions */
int main()
{
	// Let us search 3 in below array
	int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
	int n = sizeof(arr1) / sizeof(arr1[0]);
	int key = 3;

	// Function calling
	cout << "\nIndex of the element is : " << pivotedBinarySearch(arr1, n, key) << endl;

	return 0;
}
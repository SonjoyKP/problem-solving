#include <bits/stdc++.h>
using namespace std;

int binarySqrt(int x, int low, int high)
{
	if (high <= low)
		return low;

	long long int mid = (low + high) / 2;

	if (mid * mid <= x && (mid + 1) * (mid + 1) > x)
	{
		return mid;
	}
	else if (mid * mid > x)
	{
		return binarySqrt(x, low, mid - 1);
	}
	else
	{
		return binarySqrt(x, mid + 1, high);
	}
}

int mySqrt(int x)
{
	return binarySqrt(x, 0, x);
}

int main()
{
	int x = 10;

	printf("Square Root=%d\n", mySqrt(x));

	return 0;
}
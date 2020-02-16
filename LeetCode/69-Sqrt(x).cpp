#include <bits/stdc++.h>
using namespace std;

double binarySqrt(int x, double low, double high)
{
	if (high <= low)
		return low;

	double mid = (low + high) / 2;

	if (mid * mid <= x && (mid + .001) * (mid + .001) > x)
	{
		return mid;
	}
	else if (mid * mid > x)
	{
		return binarySqrt(x, low, mid - .001);
	}
	else
	{
		return binarySqrt(x, mid + .001, high);
	}
}

double mySqrt(int x)
{
	return binarySqrt(x, 0, x);
}

int main()
{
	int x = 10;

	printf("Square Root=%f\n", mySqrt(x));

	return 0;
}

/*
Accepted code:
class Solution {
public:
double myPow(double x, long long int n) {
        if(n==0)
            return 1;
        
        if(n==1)
            return x;
        
        if(n < 0)
            return 1/myPow(x, -n);
        
		//printf("x= %lf n= %d , n/2= %d\n",x, n, n/2);
        double a = myPow(x, n/2);
		//printf("a= %lf\n", a);
        
        if(n%2==0)
            return a*a;
        else
            return (a*a)*x;
    }
};

*/


#include <bits/stdc++.h>
using namespace std;



double myPow(double x, long long int n) {
        if(n==0)
            return 1;
        
        if(n==1)
            return x;
        
        if(n < 0)
            return 1/myPow(x, -n);
        
		//printf("x= %lf n= %d , n/2= %d\n",x, n, n/2);
        double a = myPow(x, n/2);
		//printf("a= %lf\n", a);
        
        if(n%2==0)
            return a*a;
        else
            return (a*a)*x;
    }

int main()
{
	double a = 2.0000;
	int n = -2;

	printf("Power=%f\n", myPow(a,n));

	return 0;
}
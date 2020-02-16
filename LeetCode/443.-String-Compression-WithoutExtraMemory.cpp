#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution
{
public:
	int compress(vector<char> &chars)
	{
		if (chars.size() == 0)
		{
			return 0;
		}

		int anchor=0, write = 0;
		for (int  read = 0; read < chars.size(); read++)
		{
			if((read+1) == chars.size() || chars[read+1] != chars[read])
			{
				chars[write] = chars[anchor];
				write++;

				if(read > anchor)
				{
					int count = read - anchor + 1;
					string s = to_string(count);
					for(int i=0; i< s.size() ; i++)
					{
						chars[write] = s[i];
						write++;
					}
				}
				anchor = read +1;
			}
		}
		return write;
	}
};

int main()
{
	string inputString = "aaabbccc";
	vector<char> chars(inputString.begin(), inputString.end());
	Solution vSolution;
	int newLength = vSolution.compress(chars);
	cout << "New Lenght= " << newLength << endl; 
	string newString(chars.begin(), chars.end());
	cout << "Output String : " << newString << endl;
	return 0;
}
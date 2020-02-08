#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution
{
public:
	int compress(vector<char> &chars)
	{
		if (chars.size() == 0)
			return 0;

		char tempChar = chars[0];

		vector<char> newChars;
		newChars.push_back(tempChar);
		int count = 1;
		for (int i = 1; i < chars.size(); i++)
		{
			if (tempChar == chars[i])
			{
				count++;
				if(i == chars.size()-1)
				{
					string sNumber = to_string(count);
					newChars.insert(newChars.end() ,sNumber.begin(), sNumber.end());
				}
			}			
			else if (tempChar != chars[i])
			{
				if (count > 1)
				{
					string sNumber = to_string(count);
					newChars.insert(newChars.end() ,sNumber.begin(), sNumber.end());
				}

				tempChar = chars[i];
				count = 1;
				newChars.push_back(tempChar);
			}
			
		}
		chars = newChars;
		return chars.size();
	}
};

int main()
{
	string inputString = "aabbccc";
	vector<char> chars(inputString.begin(), inputString.end());
	Solution vSolution;
	int newLength = vSolution.compress(chars);
	cout << "New Lenght= " << newLength << endl; 
	string newString(chars.begin(), chars.end());
	cout << "Output String : " << newString << endl;
	return 0;
}
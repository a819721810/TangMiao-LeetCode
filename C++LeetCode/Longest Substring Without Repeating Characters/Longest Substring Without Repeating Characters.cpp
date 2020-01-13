#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s == "")
		{
			return 0;
		}
		if (s == " ")
		{
			return 1;
		}
		std::unordered_set<char> hashSet;
		int maxLen = 1;
		for (int i = 0; i < s.size(); i++)
		{
			int start = i;
			for (; start < s.size(); start++)
			{
				if (hashSet.find(s[start]) == hashSet.end())
				{
					hashSet.emplace(s[start]);
				}
				else
				{
					if (hashSet.size() > maxLen)
					{
						maxLen = hashSet.size();
					}
					hashSet.clear();
					break;
				}
			}
		}
		return maxLen;
	}
};
void cinString(string &s)
{
	cin >> s;
}
int main()
{
	while (true)
	{
		string s;
		cinString(s);
		Solution solution;
		std::cout << solution.lengthOfLongestSubstring(s) << std::endl;
	}
	return 0;
}
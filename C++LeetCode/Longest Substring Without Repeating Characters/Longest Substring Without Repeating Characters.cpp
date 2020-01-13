#include<iostream>
#include<string>
#include<unordered_set>
#include<unordered_map>
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
		std::unordered_map<char,int> hashmap;
		int maxLen = 1;
		int start = 0;
		for (int i = 0; i < s.size(); i++)
		{
			for (; start < s.size(); start++)
			{
				auto iter = hashmap.find(s[start]);
				if (iter == hashmap.end())
				{
					hashmap.emplace(s[start], i);
				}
				else
				{
					if (hashmap.size() > maxLen)
					{
						maxLen = hashmap.size();
					}
					start = iter->second + 1;
					hashmap.clear();
					break;
				}
			}
		}
		if (hashmap.size() > maxLen)
		{
			maxLen = hashmap.size();
		}
		hashmap.clear();
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
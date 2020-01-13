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
		std::unordered_set<char> hashset;
		int start = 0, end = 0;
		int maxLen = 0;
		for (; end < s.size(); )
		{
			if (hashset.find(s[end])==hashset.end())
			{
				hashset.emplace(s[end]);
				end++;
				//如果没有新增i是不需要前进的，只需要滑动窗口前面缩小就行了
				//i++;
				auto sLen = end - start;
				if (sLen > maxLen)
				{
					maxLen = sLen;
				}
			}
			else
			{
				
				hashset.erase(s[start]);
				start++;
				
			}
		}
		hashset.clear();
		return maxLen;
	}
};
void cinString(string &s)
{
	std::cout << "请输入要查找的无重复的最长子串的字符串" << std::endl;
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
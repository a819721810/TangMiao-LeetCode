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
		std::unordered_map<char, int> hashmap;
		int start = 0, end = 0;
		int maxLen = 0;
		for (; end < s.size(); )
		{
			auto iter = hashmap.find(s[end]);
			//每次找到了并且找到的在start的前面，比如abcb,第4个b找到时应该更新start到c的位置
			if (iter != hashmap.end() && iter->second >=start)
			{
				start = iter->second + 1;
			}
			//否则就一直添加
			else
			{
				//这里不能用hashmap.emplace不然aaa这样的没法处理，
				//每次查找都查找到第一个a，要改变下次查找a的位置
				hashmap[s[end]] = end;
				end++;
				auto sLen = end - start;
				if (sLen > maxLen)
				{
					maxLen = sLen;
				}
			}
			//如果改成这种，那么aaa判断不来
			//if (iter == hashmap.end()||iter->second<start)
			//{
			//	hashmap.emplace(s[end], end);
			//	end++;
			//	//如果没有新增i是不需要前进的，只需要滑动窗口前面缩小就行了
			//	//i++;
			//	auto sLen = end - start;
			//	if (sLen > maxLen)
			//	{
			//		maxLen = sLen;
			//	}
			//}
			//else
			//{
			//	if (hashmap[s[end]]>=start)
			//	{
			//		start = hashmap[s[end]] + 1;
			//	}
			//	/*auto it = iter++;
			//	hashmap.erase(hashmap.begin(), iter);*/
			//}
		}
		hashmap.clear();
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
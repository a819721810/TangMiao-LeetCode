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
			//ÿ���ҵ��˲����ҵ�����start��ǰ�棬����abcb,��4��b�ҵ�ʱӦ�ø���start��c��λ��
			if (iter != hashmap.end() && iter->second >=start)
			{
				start = iter->second + 1;
			}
			//�����һֱ���
			else
			{
				//���ﲻ����hashmap.emplace��Ȼaaa������û������
				//ÿ�β��Ҷ����ҵ���һ��a��Ҫ�ı��´β���a��λ��
				hashmap[s[end]] = end;
				end++;
				auto sLen = end - start;
				if (sLen > maxLen)
				{
					maxLen = sLen;
				}
			}
			//����ĳ����֣���ôaaa�жϲ���
			//if (iter == hashmap.end()||iter->second<start)
			//{
			//	hashmap.emplace(s[end], end);
			//	end++;
			//	//���û������i�ǲ���Ҫǰ���ģ�ֻ��Ҫ��������ǰ����С������
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
	std::cout << "������Ҫ���ҵ����ظ�����Ӵ����ַ���" << std::endl;
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
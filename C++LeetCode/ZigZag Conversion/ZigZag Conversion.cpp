#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//这个题解非常棒
	//https://leetcode-cn.com/problems/zigzag-conversion/solution/zzi-xing-bian-huan-by-jyd/
	string convert(string s, int numRows) {
		int len = s.size();
		if (numRows == 1 || len <= numRows)
		{
			return s;
		}
		int flag = -1;
		int tag = 0;
		vector<string> rows(min(numRows, len));
		for (int i = 0; i < len; i++)
		{
			if ((i % (numRows - 1)) == 0)
			{
				flag = -flag;
			}
			rows[tag] = rows[tag]+ s[i];
			tag = tag + flag;
		}
		string res = "";
		for (int i = 0; i < rows.size(); i++)
		{
			res += rows[i];
		}
		return res;
	}
};

int main()
{
	Solution solution;
	string s = solution.convert("PAYPALISHIRING",3);
	return 0;
}

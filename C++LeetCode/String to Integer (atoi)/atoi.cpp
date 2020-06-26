#include<iostream>
#include <sstream>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int len = str.size();
		if (str == "" || len == 0)
		{
			return 0;
		}
		long long result = 0;
		int jinwei = 10;
		bool flag = false;
		bool isFirst = true;
		for (int i = 0; i < len; i++)
		{
			char t = str[i];
			if (t == ' '&&isFirst)
			{
				continue;
			}
			if (isFirst)
			{
				isFirst = false;
				if (isdigit(t) != 0)
				{
					result = t - '0';
				}
				else if (t == '+' || t == '-')
				{
					if (t == '-')
					{
						flag = true;
					}
					continue;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				//²»ÊÇÊý×Ö
				if (isdigit(t) == 0)
				{
					break;
				}
				if (result >= INT_MAX)
				{
					if (flag)
					{
						return INT_MIN;
					}
					return INT_MAX;
				}

				result = result*jinwei + t - '0';
			}
		}
		if (flag)
		{
			result = -result;
		}
		if (result >= INT_MAX)
		{
			return INT_MAX;
		}
		if (result<= INT_MIN)
		{
			return INT_MIN;
		}
		return result;
	}
};
int main() {
	Solution s;
	std::cout << s.myAtoi("2147483648") << std::endl;
	return 0;
}
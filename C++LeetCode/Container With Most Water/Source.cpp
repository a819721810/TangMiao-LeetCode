#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int calculateArea(int start, int end, int sHeight, int eHeight) {
		int len = end - start;
		int height = min(sHeight,eHeight);
		return len*height;
	}
	int maxArea(vector<int>& height) {
		int result = -1;
		int size = height.size();
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				int area = calculateArea(i, j, height[i], height[j]);
				if (area > result)
				{
					result = area;
				}
			}
		}
		return result;
	}
};

int main() {
	std::vector<int> v = { 1,8,6,2,5,4,8,3,7 };
	Solution s;
	std::cout<<s.maxArea(v);
	return 0;
}
#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		std::vector<int> finalVec;
		std::multiset<int> temps;
		for (const auto &num : nums1)
		{
			temps.emplace(num);
		}
		for (const auto &num : nums2)
		{
			temps.emplace(num);
		}
		for (const auto &temp : temps)
		{
			finalVec.emplace_back(temp);
		}
		auto finalVecSize = finalVec.size();
		if (finalVecSize % 2 == 1)
		{
			return finalVec[finalVecSize / 2];
		}
		else
		{
			return (finalVec[finalVecSize / 2 - 1] + finalVec[finalVecSize / 2]) / 2.0;
		}
	}
};

void cinVector(vector<int>& nums1, vector<int>& nums2)
{
	std::cout << "请输入第一个有序的vector的元素以回车结束" << std::endl;
	int val;
	do {
		std::cin >> val;
		nums1.emplace_back(val);
	} while (cin.get() != '\n');
	std::cout << "请输入第二个有序的vector的元素以回车结束" << std::endl;
	do {
		std::cin >> val;
		nums2.emplace_back(val);
	} while (cin.get() != '\n');
}

void coutVector(const vector<int>& nums1, const vector<int>& nums2)
{
	for (auto num1 : nums1)
	{
		std::cout << num1 << " ";
	}
	std::cout << std::endl;
	for (auto num2 : nums2)
	{
		std::cout << num2 << " ";
	}
	std::cout << std::endl;

}

int main()
{

	while (true)
	{
		vector<int> nums1;
		vector<int> nums2;
		cinVector(nums1, nums2);
		//coutVector(nums1, nums2);
		Solution solution;
		std::cout << solution.findMedianSortedArrays(nums1, nums2) << std::endl;
	}
	return 0;
}
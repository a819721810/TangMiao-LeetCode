#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int getKth(const vector<int>& nums1, int start1, int end1, const vector<int>& nums2, int start2, int end2, int K)
{
	int len1 = end1 - start1 + 1;
	int len2 = end2 - start2 + 1;
	//让 len1 的长度小于 len2，这样就能保证如果有数组空了，一定是 len1 
	if (len1 > len2) return getKth(nums2, start2, end2, nums1, start1, end1, K);

	if (len1 == 0) return nums2[start2 + K - 1];
	if (K == 1) return std::min(nums1[start1], nums2[start2]);

	int i = start1 + std::min(len1, K / 2) - 1;
	int j = start2 + std::min(len2, K / 2) - 1;
	if (nums1[i] > nums2[j]) {
		return getKth(nums1, start1, end1, nums2, j + 1, end2, K - (j - start2 + 1));
	}
	else {
		return getKth(nums1, i + 1, end1, nums2, start2, end2, K - (i - start1 + 1));
	}
}


class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();
		int left = (n + m + 1) / 2;
		int right = (n + m + 2) / 2;
		return (getKth(nums1, 0, n - 1, nums2, 0, m - 1, left) + getKth(nums1, 0, n - 1, nums2, 0, m - 1, right)) * 0.5;
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
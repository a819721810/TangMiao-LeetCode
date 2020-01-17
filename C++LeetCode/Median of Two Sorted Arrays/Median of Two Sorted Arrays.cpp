#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int nums1Size = nums1.size();
		int nums2Size = nums2.size();
		int allSize = nums1Size + nums2Size;
		int midNum = allSize / 2;
		int count = 0;
		bool isOddNumber = true;
		int midFirst = 0, midSecond = 0;
		if (allSize % 2 == 0)
		{
			isOddNumber = false;
		}
		int i = 0, j = 0;
		while (i < nums1Size || j < nums2Size)
		{
			if (isOddNumber)
			{
				if (i < nums1Size && j < nums2Size)
				{
					if (nums1[i] > nums2[j])
					{
						if (count == midNum)
						{
							return nums2[j];
						}
						count++;
						j++;
					}
					else
					{
						if (count == midNum)
						{
							return nums1[i];
						}
						count++;
						i++;
					}
				}
				else if (i < nums1Size)
				{
					if (count == midNum)
					{
						return nums1[i];
					}
					count++;
					i++;
				}
				else
				{
					if (count == midNum)
					{
						return nums2[j];
					}
					count++;
					j++;
				}
			}
			//1 2 3 4 第一个target是4/2 -1 第二个是4/2
			else
			{
				if (i < nums1Size && j < nums2Size)
				{
					if (nums1[i] > nums2[j])
					{
						if (count == midNum - 1)
						{
							/*return nums2[j];*/
							midFirst = nums2[j];
						}
						else if (count == midNum)
						{
							midSecond = nums2[j];
							return (midFirst + midSecond) / 2.0;
						}
						count++;
						j++;
					}
					else
					{
						if (count == midNum - 1)
						{
							/*return nums2[j];*/
							midFirst = nums1[i];
						}
						else if (count == midNum)
						{
							midSecond = nums1[i];
							return (midFirst + midSecond) / 2.0;
						}
						count++;
						i++;
					}
				}
				else if (i < nums1Size)
				{
					if (count == midNum - 1)
					{
						/*return nums2[j];*/
						midFirst = nums1[i];
					}
					else if (count == midNum)
					{
						midSecond = nums1[i];
						return (midFirst + midSecond) / 2.0;
					}
					count++;
					i++;
				}
				else
				{
					if (count == midNum-1)
					{
						midFirst = nums2[j];
						//return nums2[j];
					}
					else if (count == midNum)
					{
						midSecond = nums2[j];
						return (midFirst + midSecond) / 2.0;
					}
					count++;
					j++;
				}
			}
		}
		return (midFirst + midSecond) / 2.0;
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
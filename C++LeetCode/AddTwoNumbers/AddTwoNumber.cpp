//https://leetcode-cn.com/problems/add-two-numbers/
#include<iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* mergeHeadNode = new ListNode(0);
		ListNode* mergeMoveNode = new ListNode(0);
		ListNode* TempNode;
		bool isFirst = true;
		bool isAddOne = false;
		while (l1 != NULL || l2 != NULL)
		{
			int x = (l1 != NULL) ? l1->val : 0;
			int y = (l2 != NULL) ? l2->val : 0;
			auto addResult = x + y;
			if (isAddOne)
			{
				addResult = addResult + 1;
			}
			if (addResult < 10)
			{
				isAddOne = false;
				TempNode = new ListNode(addResult);
				mergeMoveNode->next = TempNode;
				mergeMoveNode = TempNode;
			}
			else
			{
				isAddOne = true;
				TempNode = new ListNode(addResult - 10);
				mergeMoveNode->next = TempNode;
				mergeMoveNode = TempNode;
			}
			if (isFirst)
			{
				mergeHeadNode = mergeMoveNode;
				isFirst = false;
			}
			if (l1 != NULL) l1 = l1->next;
			if (l2 != NULL) l2 = l2->next;
		}

		/*while (l1 != NULL)
		{
		auto addResult = l1->val;
		if (isAddOne)
		{
		addResult = addResult + 1;
		}
		if (addResult < 10)
		{
		isAddOne = false;
		TempNode = new ListNode(addResult);
		mergeMoveNode->next = TempNode;
		mergeMoveNode = TempNode;
		}
		else
		{
		isAddOne = true;
		TempNode = new ListNode(addResult - 10);
		mergeMoveNode->next = TempNode;
		mergeMoveNode = TempNode;
		}
		if (isFirst)
		{
		mergeHeadNode = mergeMoveNode;
		isFirst = false;
		}
		l1 = l1->next;
		}
		while (l2 != NULL)
		{
		auto addResult = l2->val;
		if (isAddOne)
		{
		addResult = addResult + 1;
		}
		if (addResult < 10)
		{
		isAddOne = false;
		TempNode = new ListNode(addResult);
		mergeMoveNode->next = TempNode;
		mergeMoveNode = TempNode;
		}
		else
		{
		isAddOne = true;
		TempNode = new ListNode(addResult - 10);
		mergeMoveNode->next = TempNode;
		mergeMoveNode = TempNode;
		}
		if (isFirst)
		{
		mergeHeadNode = mergeMoveNode;
		isFirst = false;
		}
		l2 = l2->next;
		}*/
		//特殊情况，如5+5=10
		if (isAddOne)
		{
			TempNode = new ListNode(1);
			mergeMoveNode->next = TempNode;
			mergeMoveNode = TempNode;
		}
		return mergeHeadNode;
	}
};

void cinNode(ListNode* &l1, ListNode* &l2)
{
	std::cout << "请输入第一个链表的元素且最后一个元素为0按回车键结束" << std::endl;
	int val;
	ListNode* l1Head = new ListNode(0);
	ListNode* l2Head = new ListNode(0);
	bool isL1First = true;
	bool isL2First = true;
	while (std::cin >> val&&val != 0)
	{
		ListNode* TempNode = new ListNode(val);
		if (isL1First)
		{
			l1Head = TempNode;
			l1 = l1Head;
			isL1First = false;
		}
		else
		{
			l1->next = TempNode;
			l1 = TempNode;
		}
	}
	l1 = l1Head;
	std::cout << "请输入第二个链表的元素且最后一个元素为0按回车键结束" << std::endl;
	while (std::cin >> val&&val != 0)
	{
		ListNode* TempNode = new ListNode(val);
		if (isL2First)
		{
			l2Head = TempNode;
			l2 = l2Head;
			isL2First = false;
		}
		else
		{
			l2->next = TempNode;
			l2 = TempNode;
		}
	}
	l2 = l2Head;
}

void printNode(ListNode* node)
{
	while (node&&node->next)
	{
		std::cout << node->val << "-->";
		node = node->next;
	}
	std::cout << node->val;
	std::cout << std::endl;
}

int main()
{
	while (true)
	{
		ListNode* l1, *l2;
		cinNode(l1, l2);
		printNode(l1);
		printNode(l2);
		Solution solution;
		auto addResultNode = solution.addTwoNumbers(l1, l2);
		printNode(addResultNode);
		delete l1, l2, addResultNode;
	}
	return 0;
}

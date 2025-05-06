/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *vectorToList(const std::vector<int> &nums)
{
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;

    for (int num : nums)
    {
        current->next = new ListNode(num);
        current = current->next;
    }

    return dummy->next;
}

vector<int> listToVector(ListNode *head)
{
    vector<int> result;

    while (head != nullptr)
    {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    vector<int> result = {};
    vector<int> nums1 = listToVector(l1);
    vector<int> nums2 = listToVector(l2);

    int maxSize = max(nums1.size(), nums2.size());
    int carry = 0;

    for (int i = 0; i < maxSize || carry; i++)
    {
        int val1 = (i < nums1.size()) ? nums1[i] : 0;
        int val2 = (i < nums2.size()) ? nums2[i] : 0;

        cout << val1 << val2;
        int sum = val1 + val2 + carry;

        carry = sum / 10;

        result.push_back(sum % 10);
    }

    return vectorToList(result);
}

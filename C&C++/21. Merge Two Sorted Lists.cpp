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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* merge;
        ListNode* first;

        if(list1 == nullptr) 
        {
            first = list2;
            return first;
        }
        else if(list2 == nullptr) 
        {
            first = list1;
            return first;
        }
        else if(list1->val <= list2->val)
        {
            first = list1;
            merge = list1;
            list1 = list1->next;
        }
        else
        {
            first = list2;
            merge = list2;
            list2 = list2->next;
        }

        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val <= list2->val)
            {
                merge->next = list1;
                merge = merge->next;
                list1 = list1->next;
            }
            else
            {
                merge->next = list2;
                merge = merge->next;
                list2 = list2->next;
            }
        }

        if(list1 == nullptr) merge->next = list2;
        else merge->next = list1;


        return first;
    }

};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* merge;
    struct ListNode* first;

    if(list1 == NULL) 
    {
        first = list2;
        return first;
    }
    else if(list2 == NULL) 
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

    while(list1 != NULL && list2 != NULL)
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

    if(list1 == NULL) merge->next = list2;
    else merge->next = list1;

    return first;
}

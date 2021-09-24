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

//naive solution:
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first_copy = head;
        ListNode *second_copy = new ListNode(0);
        second_copy->next = head;
        int counter=0;
        while (first_copy!=nullptr){
            counter++;
            first_copy = first_copy->next;
        }
        first_copy = second_copy;
        while(counter > n){
            counter--;
            first_copy = first_copy->next;
        }
        if (counter<1){
            return nullptr;
        }
        first_copy->next = first_copy->next->next;
        return second_copy->next;
    }
};

//optimized solution:
//turns out the run time and space used on this is the same as the un-optimized one;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *copy_list = new ListNode(0);
        copy_list->next = head;
        ListNode *slow_ptr = copy_list;
        ListNode *fast_ptr = copy_list;
        
        for(int i=0; i<=n;i++){
            fast_ptr = fast_ptr->next;
        }
        
        while(fast_ptr != nullptr){
            fast_ptr = fast_ptr->next;
            slow_ptr = slow_ptr->next;
        }
        slow_ptr->next = slow_ptr->next->next;
        return copy_list->next;
    }
};

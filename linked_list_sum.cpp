#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    vector<int> find_number(ListNode* l){
        int result = 0;
        int counter = 0;
        vector<int> return_vec;
        while(l!=nullptr){
            result = result*10 + l->val;
            counter++;
            l=l->next;
        }
        return_vec.push_back(result);// so return_vec[0] is the number and return_vec[1] is the tens power
        return_vec.push_back(counter);
        return return_vec;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1 = find_number(l1)[0];
        int num2 = find_number(l2)[0];
        int tens_power1 = find_number(l1)[1];
        int tens_power2 = find_number(l2)[1];

        ListNode* return_list;

        int num_to_insert;
        while(tens_power1>tens_power2){
            num_to_insert = num1%(10^tens_power1);
            return_list->val = num_to_insert;
            return_list = return_list->next;//not sure if this is the way to get to the next node in a list
            tens_power1 --;
        }
        while(tens_power1>0){
            num_to_insert = (num1%(10^tens_power1))+num2%(10^tens_power2);
            return_list -> val = num_to_insert;
            return_list = return_list->next;
            tens_power1 --;
            tens_power2 --;
        }
        return return_list;
    }
};

//  Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

//it is a given that all values are unique 
// fast solution:
void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

//slow but more readable solution:
void deleteNode(struct ListNode* node) {
    int tempVal = node->next->val;
    struct ListNode *tempNode = node->next->next;
    node->val = tempVal;
    node->next = tempNode;
}

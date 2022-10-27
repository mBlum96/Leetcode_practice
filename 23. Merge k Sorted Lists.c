/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//implement merge of two lists and then link every two lists in the list array
//copying what I wrote as comments to that solution as well:
//We need a comperator func to tell which of the values is larger (in case it is not int)
//I want to create a new node that will point to the minimum node from the two lists we get
//I will then make the next node in the new list point to the next smallest value and continue
//until no nodes are left from the original two lists
//if one list empties first, just add all the nodes that are left in the second list to the return list

// struct ListNode* compare(struct ListNode* l1, struct ListNode *l2){//I could'nt get it to run so I dropped the functional implementation
//     struct ListNode *temp;
//     if(l1->val < l2->val){
//         temp = l1;
//         l1 = l1->next;
//     }else{
//         temp = l2;
//         l2 = l2->next;
//     }
//     return temp;
// }

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode head;
    struct ListNode *h=&head;
    while(list1 && list2){
        if(list1->val < list2->val){
            h->next = list1;
            list1 = list1->next;
        }else{
            h->next = list2;
            list2 = list2->next;
        }
        // h->next = compare(list1,list2);
        h=h->next;
    }
    if(list1){
        h->next = list1;
    }else{
        h ->next = list2;
    }
    return head.next;
}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize==0){
        return NULL;
    }else if(listsSize==1){
        return lists[0];
    }
    for(int i=1;i<listsSize;i++){
        lists[0]=mergeTwoLists(lists[0],lists[i]);
    }
    return lists[0];
}
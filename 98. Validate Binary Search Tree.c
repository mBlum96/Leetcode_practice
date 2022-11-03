#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>


//  Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// //messy solution that I wrote alone (DFS sorta)

// void isSubBST(struct TreeNode* root, bool *answer, long min, long max){
//     if (*answer==false){
//         return;
//     }
//     if(root->left!=NULL){
//         if(root->left->val <= min){
//             *answer = false;
//         }
//         isSubBST(root->left, answer,min,root->val);
//     }
//     if(root->right!=NULL){
//         if(root->right->val>=max){
//             *answer = false;
//         }
//         isSubBST(root->right, answer,root->val,max);
//     }
//     if(root->right!=NULL){
//         if(root->right->val<=root->val){
//             *answer= false;
//         }
//     }
//     if(root->left!=NULL){
//         if(root->left->val>=root->val){
//             *answer= false;
//         }
//     }


// }

// bool isValidBST(struct TreeNode* root){
//     bool answer = true;
//     long min = LONG_MIN;
//     long max = LONG_MAX;
//     isSubBST(root,&answer,min,max);
//     return answer;
// }

//elegant solution that I wrote after seeing the answer (DFS)


bool isSubBST(struct TreeNode* root, long min, long max){
    if(root == NULL){//termination condition
        return true;
    }
    if(root->val>=max || root->val <= min){
        return false;
    }
    return isSubBST(root->left,min,root->val) && isSubBST(root->right,root->val,max);

}

bool isValidBST(struct TreeNode* root){
    long min = LONG_MIN;
    long max = LONG_MAX;
    return isSubBST(root,min,max);
}
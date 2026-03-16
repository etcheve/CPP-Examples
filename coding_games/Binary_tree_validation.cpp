// https://leetcode.com/problems/validate-binary-search-tree/description/
//98. Validate Binary Search Tree

/*

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:
*/

using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution {
public:
    TreeNode* prev = nullptr;

    bool isValidBST(TreeNode* root) {
        bool vleft, vright,valid = true;
        if (root == nullptr){
            return true ;
        }
        if (!isValidBST(root->left))  {
            return false;
        }
        if (prev && prev->val >= root->val){
             return false;
        }
        prev = root;
        return  isValidBST(root->right)  ;        
    }
};
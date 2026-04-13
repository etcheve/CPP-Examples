// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/


/**
 * Definition for singly-linked list.
 * 
 * */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*  right = head ;
        ListNode*  left = head ;
        for (int i = 0 ; i < n && right != nullptr; ++i){
            right = right->next;
        }
        if (right == nullptr){
               return head->next;  
        }
        right = right->next;
        while (right!=nullptr){
            right=right->next;
            left = left->next;
        }

        if (left->next==nullptr){
            return head;
        }
        left->next = left->next->next;
        return head;
        
    }
};
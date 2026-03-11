// https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

/* Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
*/
#include <iostream>
using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr){
            return head;
        }
        if (head->next == nullptr){
           return head;
        }
        if (head->next->val == head->val){
            head->next = head->next->next;
            deleteDuplicates(head);
        }
        deleteDuplicates(head->next);
        return head;

        
    }
};
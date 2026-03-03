// https://leetcode.com/problems/add-two-numbers/description/
/* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/



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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode* current = nullptr;

        int rest=0;
        while (l1 != nullptr || l2 != nullptr || rest != 0) {
           int newval = rest +  
           ( l1 == nullptr ? 0 : l1->val) +
            (l2 == nullptr ? 0 : l2->val);
            rest = 0;
            if (newval >= 10){
                rest=1;
                newval = newval%10;
            }
            // create new node link to previus 
            auto newNode = new ListNode(newval);
            if (result == nullptr){
                result = newNode;
                current = newNode;
            }else{
                current->next = newNode;
                current = newNode;
            }
        if (l1 != nullptr){
            l1 = l1->next;}
       if(l2 != nullptr){ 
        l2 = l2->next;}

        }
        return result;
    }
};
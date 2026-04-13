// https://leetcode.com/problems/reorder-list/description/


/**
 * Definition for singly-linked list.
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
    void reorderList(ListNode* head) {
            if (head == nullptr || head->next == nullptr){
                return;
            }
           ListNode* middle = head;
           ListNode* fast = head->next; 
           // find the middle
           while (fast != nullptr && fast->next != nullptr){
            middle = middle->next;
            fast = fast->next->next;
           }

           // reverse list after middle
           ListNode* next = nullptr;
            ListNode* prev  = nullptr;

           while(middle != nullptr){
            next = middle->next;
            middle->next = prev;
            prev= middle;
            middle = next;
           }

            // prev containes the last element 
            ListNode* l2  = prev;
            ListNode* next2=nullptr;
            while (head != nullptr){
                next=head->next;
                head->next= l2;
                next2 = l2->next;
                l2->next = next;
                head = next;
                l2= next2;

            }
        
    }
};
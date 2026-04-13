// https://leetcode.com/problems/reverse-linked-list/description/


 struct ListNode {
     int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* next =nullptr;
    if (head == nullptr){
        return head;
    }
    while(head->next != nullptr){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head->next = prev;
    return head;
       
    }
};
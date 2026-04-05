// https://leetcode.com/problems/linked-list-cycle/description/

/**
 * Definition for singly-linked list.
 * **/
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        ListNode* tor=head;
        ListNode* rab =head->next;
        while (rab!= nullptr and tor != nullptr) {
            if (rab == tor){
                return true;
            }
            tor = tor->next;
            if(rab->next == nullptr){
                return false;
            }
            rab = rab->next->next;

        }
        return false;
        
    }
};
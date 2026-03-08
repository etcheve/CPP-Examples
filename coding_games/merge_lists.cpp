// https://leetcode.com/problems/merge-two-sorted-lists/description/



 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
      };
 


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head =nullptr;
        ListNode* CurrentNode=nullptr;
        if(list1 != nullptr && (
                    list2 == nullptr || 
                    list1->val <= list2->val )){
                    CurrentNode = list1;
                    head =list1; 
                    list1 = list1->next;
        }else if(list2 != nullptr){
                    CurrentNode = list2;
                    head =list2; 
                    list2 = list2->next;
               }else{
                    return nullptr;
                }
        while(list1 != nullptr || list2 != nullptr){
                if(list1 != nullptr && (
                    list2 == nullptr || 
                    list1->val <= list2->val )){
                    CurrentNode->next = list1;
                    CurrentNode =list1; 
                    list1 = list1->next;
                }else{
                    CurrentNode->next = list2;
                    CurrentNode =list2; 
                    list2 = list2->next;
                }
            }
        return head;
    }
};
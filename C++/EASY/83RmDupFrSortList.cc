#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)return nullptr;
        int val=head->val;
        ListNode* ptr=head->next;
        ListNode* pre=head;
        while(ptr){
            if(ptr->val==val){
                pre->next=ptr->next;
                ptr=ptr->next;
            }
            else{
                val=ptr->val;
                pre=pre->next;
                ptr=ptr->next;
            }
               
        }
        return head;
    }
};
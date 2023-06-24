/**
 * Definition for singly-linked list.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode*reverseLL(ListNode*head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode*temp=reverseLL(head->next);
        head->next->next=head;
        head->next=NULL;
        return temp;
    }
    ListNode*mid(ListNode*head){
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            return false;
        }
        if(head->next==NULL){
            return true;
        }
        ListNode*midnode=mid(head);
        midnode=midnode->next;
        ListNode*reversedmid=reverseLL(midnode);
        ListNode*temp=head;
        while(temp!=midnode && reversedmid!=NULL){
            if(temp->val!=reversedmid->val){
                return false;
            }
            temp=temp->next;
            reversedmid=reversedmid->next;
        }
        return true;
    }
};
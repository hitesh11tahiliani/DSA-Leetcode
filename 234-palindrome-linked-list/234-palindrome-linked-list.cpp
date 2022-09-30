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
    bool isPalindrome(ListNode* head) {
        vector<ListNode*> temp;
        
        while(head!=NULL){
            temp.push_back(head);
            head=head->next;
        }
        
        int j=temp.size()-1;
        
        for (int i=0; i<temp.size()/2; i++){
            if (temp[i]->val!=temp[j]->val)
                return false;
            j--;
        }
        return true;
    }
};
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
    
    int find(ListNode* temp)
    {
        int reqval = temp->val;
        
        temp = temp->next;
        while(temp!=NULL)
        {
            if(temp->val > reqval)
            {
                return temp->val;
            }
            temp = temp->next;
        }
        
        return 0;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        
      vector<int> ans;
        ListNode* temp = head;
        
        while(temp!=NULL)
        {
            int result = find(temp);
            ans.push_back(result);
            temp = temp->next;
        }
        
        
        return ans;
        
        
    }
};
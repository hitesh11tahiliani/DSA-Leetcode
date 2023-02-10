class Solution {
public:
    
    ListNode* merge(ListNode* a,ListNode* b) {
        if(!a) return b;
        if(!b) return a;
        ListNode* temp=NULL;
        if(a->val<=b->val) 
        {
            temp =a;
            temp->next = merge(a->next,b);
        }
        else 
        {
            temp = b;
            temp->next = merge(a,b->next);
        }
        return temp;        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
        ListNode* ans=NULL;
        for(auto l : lists) 
        {
            ans = merge(ans,l);
        }
        return ans;
    }
};
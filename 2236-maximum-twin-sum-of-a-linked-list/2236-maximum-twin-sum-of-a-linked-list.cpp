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
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode* curr=head;
        int present=0, sum =0, maxSum =0;
        int size=0;
        while(curr!=NULL){
            curr = curr->next;
            size++;
        }
        curr = head ;
        int i=0;
        while(curr!=NULL){
            if(i<size/2){
                st.push(curr->val);
            }
            if(i>=size/2){
                present = st.top();
                st.pop();
                sum = present + curr->val;
                cout<<sum;
                maxSum = max(sum, maxSum);
            }
            curr = curr->next;
            i++;
        }
        return maxSum;
    }
};
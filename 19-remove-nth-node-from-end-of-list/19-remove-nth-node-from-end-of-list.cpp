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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp=head;
        int countNodes=0;
        while (temp!=NULL){
            countNodes++;
            temp=temp->next;
        }
        
         //Checking the edge case when the 'n' i.e. node to be deleted
      //from end of the list is equal to the number of nodes in the 
      //linked list.
      /*For Example :- 
                       Input : [7,4] , n=2
                       Output: [4]
      */
       
         if (countNodes==n){
             ListNode *node=head;
             head=head->next;
             return head;
         }
        
        //If the node to be deleted is not the head of the list then we have 
      //to reach one node before it.         
      int difference = countNodes - n;
      int counter=1;
      temp=head;
      while(counter!=difference)
      {
          counter++;
          temp=temp->next;
      }
        
      //The main logic to delete the nth node from the end.       
      ListNode *node=temp->next;
      temp->next=node->next;
      delete node;
        
      return head;
        
        
        
    }
};
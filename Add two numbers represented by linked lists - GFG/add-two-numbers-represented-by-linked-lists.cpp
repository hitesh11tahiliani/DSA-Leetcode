//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node* reverse (Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* forward  = NULL;
        
        while (curr!=NULL){
            forward = curr->next;
            curr->next = prev;
            
            prev=curr;
            curr=forward;
        }
        
        return prev;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first = reverse (first);
        second = reverse (second);
        
        struct Node* fHead = new Node(0);
        struct Node* fTail = fHead;
        
        int carry=0;
        
        while(first || second || carry){
            int sum = (first ? first->data:0) + (second ? second->data:0) + carry;
            
            carry = sum/10;
            struct Node* temp = new Node(sum%10);
            fTail -> next = temp;
            fTail = fTail->next;
            
            if (first)
                first = first->next;
                
            if (second)
                second = second->next;
        }
        
        return reverse(fHead->next);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
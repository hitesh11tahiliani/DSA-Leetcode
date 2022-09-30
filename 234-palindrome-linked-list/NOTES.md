Naive approch, pushing all the elements in vector and cheack if they are palindrome or not
​
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
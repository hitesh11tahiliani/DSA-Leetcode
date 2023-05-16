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
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         ListNode* dummy = new ListNode();
//         dummy->next = head;
//         ListNode* prev = dummy;
//         ListNode* curr = head;

//         while(curr && curr->next){
//             prev = curr->next->val;
//             prev->next =  curr->val;
//             curr = curr->next->next;
//         }
//         return dummy;
//     }
// };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head; // Set the dummy node's next pointer to the head

        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr && curr->next) {
            ListNode* nextNode = curr->next;
            curr->next = nextNode->next;
            nextNode->next = curr;
            prev->next = nextNode;

            prev = curr;
            curr = curr->next;
        }

        return dummy->next; // Return the updated head
    }
};

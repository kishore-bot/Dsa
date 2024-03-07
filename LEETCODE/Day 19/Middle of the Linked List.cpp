// Easy
// LINKED LIST
// https://leetcode.com/problems/middle-of-the-linked-list/description/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        for (ListNode* temp = head; temp != NULL; temp = temp->next) {
            count++;
        }
        
        int mid =  count / 2 ;
        
        ListNode* ans = head;
        for (int i = 0; i < mid; i++) {
            ans = ans->next;
        }
        
        return ans;
    }
};

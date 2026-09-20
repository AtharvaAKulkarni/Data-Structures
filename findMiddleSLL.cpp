class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        /*
            - fast traverses the linked list with 2x speed than the slow
            - if fast has traveresed the linked list, then slow has traversed only the half of it
            - for second middle stop when fast is NULL or reached the last node
            - for first middle stop when fast has reached the second last node (fast->next->next is NULL)
            - TC O(n)
            - SC O(1)
        */
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};

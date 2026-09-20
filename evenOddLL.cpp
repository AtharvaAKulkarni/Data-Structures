class Solution {
public:
    /*
        - Divide the linked list into 2 halves
        - Since the even is always ahead of odd, we will ue that to verify we are inside the LL
        - odd->next=even->next
        - move odd to next
        - even->next=odd->mext
        - move even to next
        - odd->next= even head
        - return head
    */
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenHead=even;

        while(even && even->next){
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next;
            even=even->next;
        }

        odd->next=evenHead;
        return head;
    }
};

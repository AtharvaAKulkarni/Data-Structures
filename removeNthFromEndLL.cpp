class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
            - Create a dummy node because we dont know which node is going to be the head
            - Move the right pointer n steps ahead
            - Keep the slow pointer at node before head
            - now until right reaches null, move both left and right
            - adjust left->next=left->next->next
            - return dummy->next
        */
        if(!head || !head->next) return nullptr;
        
        ListNode* dummy=new ListNode(0);
        dummy->next=head;

        ListNode* left=dummy;
        ListNode* right=head;
        
        for(int i=0;i<n;i++) right=right->next;

        while(right){
            left=left->next;
            right=right->next;
        }

        left->next=left->next->next;
        return dummy->next;
    }
};

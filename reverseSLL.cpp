class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        /*
            - Create a prev pointer which will point to the prev node of the curr node
            - store the next node of the curr node so we dont loose reference to it
            - curr node's next will be the prev (reversing)
            - the curr will become the new prev and the next will become the new curr
            - when the next becomes null i.e curr is the last element we do the swappings
            - the head will now point to the prev (as prev=curr)
            - TC O(n)
            - SC O(1)
        */
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
        return head;
    }
};

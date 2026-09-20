class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        /*
            - first we detect the loop (if fast==slow)
            - move one of fast or slow to head
            - move both by 1 until they meet
            - the position where they meet is the starting point
            - WHY?
            - Let the starting point of the loop be at a distance L1 from root
            - When slow reaches the starting point , fast is at a distance of L1 from slow (fast moves 2L1 distance from head)
            - the distance of slow from fast be d
            - the fast and slow pointer move to reduce the distance by 1 in every iteration
            - when d becomes 0, fast has moved 2d distance and slow has moved a distance of d
            - Now if slow has moved a distance of d, the distance of the starting point from the slow pointer has to be L1, since the length of the loop is L1+d
            - Hence we only need to travel a distance of L1 from the slow/fast pointer
            - Since the distance from the head and the starting point is also L1, we use this to eventually reach the starting point
        */
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) break;
        }
        if(!fast || !fast->next) return nullptr;
        fast=head;
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};

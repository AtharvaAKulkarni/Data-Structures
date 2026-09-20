class Solution {
public:
    bool hasCycle(ListNode *head) {
        /*
            - BRUTE- Hashmap of visited nodes, if we visit the same node twice there is a loop
            - Create the fast and slow pointer
            - If they are in a loop, the fast is trying to reach the slow pointer
            - In every iteration, the distance between the fast and slow decreases by 1
            - Fast is moving 2 steps , slow is moving one step in the same directon hence distance reduces by 1 (in a circle)
            - Hence the fast has to reach slow
            - TC O(n)
            - SC O(1)
        */
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast) return true;
        }        
        return false;
    }
};

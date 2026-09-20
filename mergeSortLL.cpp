class Solution {
public:

    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* mergeList(ListNode* l, ListNode* r) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(l && r) {
            if(l->val < r->val) {
                curr->next = l;
                l = l->next;
            }
            else {
                curr->next = r;
                r = r->next;
            }

            curr = curr->next;
        }

        curr->next = l ? l : r;

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {

        if(!head || !head->next)
            return head;

        // Find first middle
        ListNode* middle = findMiddle(head);

        // Split
        ListNode* left = head;
        ListNode* right = middle->next;

        middle->next = nullptr;

        // Sort both halves
        left = sortList(left);
        right = sortList(right);

        // Merge
        return mergeList(left, right);
    }
};

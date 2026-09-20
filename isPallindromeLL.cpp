class Solution {
public:
    /*
        - Find the middle of the LL
        - reverse the second hald
        - Compare each nodes val, if not equal return false
        - Return true at the end
        - This COMPLETELY DESTROYS THE LL, so we have to restore the LL, reverse the second half again and first->next=second
        - TC O(n)
        - SC O(1)
    */
    ListNode* reverse(ListNode* root){
        if(!root) return nullptr;
        ListNode* prev=nullptr;
        ListNode* curr=root;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }    
        
        ListNode* middle=slow;
        ListNode* right=middle->next;
        middle->next=nullptr;

        right=reverse(right);
        ListNode* temp=head;
        while(temp && right){
            if(temp->val!=right->val) return false;
            temp=temp->next;
            right=right->next;
        }

        return true;
    }
};

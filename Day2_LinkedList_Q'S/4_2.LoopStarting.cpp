class Solution {
public:
    ListNode *floyd(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow != NULL && fast != NULL && fast-> next != NULL){
            if(head == NULL){
                return NULL;
            }
            slow = slow -> next;
            fast = fast->next->next;

            if(slow == fast){
                return slow;
            }
        }
        return NULL;
        
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode* inter = floyd(head);
        if(inter == NULL){
            return NULL;
        }
        ListNode* slow = head;
        while(slow != inter){
            slow = slow->next;
            inter = inter->next;
        }
        return slow;
    }
};
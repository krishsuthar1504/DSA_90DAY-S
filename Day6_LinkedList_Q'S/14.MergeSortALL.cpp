/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findmid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergelist(ListNode* left , ListNode* right){
        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }

        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;

        //merge 2 sorted Linked List
        while(left != NULL && right != NULL){
            if(left -> val < right -> val){
                temp -> next = left;
                temp = left;
                left = left-> next;
            }
            else{
                temp -> next = right;
                temp = right;
                right = right-> next;
            }
        }
        while(right != NULL){
            temp -> next = right;
            temp = right;
            right = right-> next;
        }
        while(left != NULL){
            temp -> next = left;
            temp = left;
            left = left-> next;
        }
        
        ans = ans -> next;
        return ans;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* mid = findmid(head);
        ListNode* right;
        ListNode* left;
        right = mid -> next;
        mid -> next = NULL;
        left = head;

        left = sortList(left);
        right = sortList(right);
        ListNode* result = mergelist(left , right);

        return result;
    }
};
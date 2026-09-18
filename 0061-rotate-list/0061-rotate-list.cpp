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
    int getLen(ListNode* head){
        int cnt = 0;
        while(head){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0) return head;
        int len = getLen(head);
        k=k%len;
        int t = len - k -1;
        ListNode* newT=head;
        ListNode* newH;
        while(t--){
            newT = newT->next;
        }
        if(newT->next) newH=newT->next;
        else {newH=head;
            return newH;
        }
        ListNode* x = newH;
        while(x->next){
            x=x->next;
        }
        x->next = head;
        newT->next = nullptr;
        return newH;
    }
};
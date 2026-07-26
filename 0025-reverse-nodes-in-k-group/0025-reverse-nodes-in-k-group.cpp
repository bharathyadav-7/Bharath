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
ListNode* reversell(ListNode* temp){
    if(temp==NULL || temp->next==NULL) return temp;
    ListNode* newHead=reversell(temp->next);
    ListNode* front=temp->next;
    front->next=temp;
    temp->next=NULL;
    return newHead;
}
ListNode* findKth(ListNode* temp,int k){
    k -=1;
    while(temp != NULL && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevLast=NULL;
        while(temp !=  NULL){
            ListNode* kthNode=findKth(temp,k);
            if(kthNode==NULL){
                if(prevLast) prevLast->next=temp;
                break;
            }

            ListNode* next=kthNode->next;
            kthNode->next=NULL;
            reversell(temp);
            if(temp==head){
                head=kthNode;
            }else{
                prevLast->next=kthNode;
            }
            prevLast=temp;
            temp=next;
        }
        return head;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
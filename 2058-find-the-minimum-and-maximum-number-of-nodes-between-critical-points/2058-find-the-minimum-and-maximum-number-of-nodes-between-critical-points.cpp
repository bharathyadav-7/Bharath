class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL || head->next == NULL || head->next->next == NULL) return {-1,-1};
        int index=1;
        ListNode* prev=head;
        ListNode* curr=prev->next;
        int firstcritical=-1;
        int prevcritical=-1;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        while(curr->next != NULL){
            ListNode* next=curr->next;
            if(prev->val<curr->val && curr->val>next->val || prev->val>curr->val&&curr->val<next->val){
                if(firstcritical==-1){
                    firstcritical=index;
                    prevcritical=index;
                }else{
                    mini=min(mini,index-prevcritical);
                    maxi=index-firstcritical;
                    prevcritical=index;
                }
            }
            prev=curr;
            curr=next;
            index++;
        }
        if(firstcritical == -1 || firstcritical == prevcritical) return {-1,-1};
        return {mini,maxi};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
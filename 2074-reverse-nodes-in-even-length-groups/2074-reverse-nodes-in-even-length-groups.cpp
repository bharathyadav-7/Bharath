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
    ListNode* reverse(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (k--) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevTail = &dummy;
        ListNode* curr = head;

        int groupSize = 1;

        while (curr) {
            ListNode* temp = curr;
            int actualSize = 0;

            while (temp && actualSize < groupSize) {
                temp = temp->next;
                actualSize++;
            }
            if (actualSize % 2 == 0) {

                ListNode* newHead = reverse(curr, actualSize);

                prevTail->next = newHead;
                curr->next = temp;

                prevTail = curr;
                curr = temp;
            }
            else {

                prevTail = curr;

                for (int i = 1; i < actualSize; i++)
                    prevTail = prevTail->next;

                curr = temp;
            }

            groupSize++;
        }

        return dummy.next;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
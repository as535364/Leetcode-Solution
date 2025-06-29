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
private:
    ListNode *swapTwoNodes(ListNode *head) {
        if (head == nullptr || head -> next == nullptr) return head;

        ListNode *first = head, *second = head -> next;
        ListNode *remain = swapTwoNodes(second -> next);

        first -> next = remain;
        second -> next = first;
        return second;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        return swapTwoNodes(head);
    }
};
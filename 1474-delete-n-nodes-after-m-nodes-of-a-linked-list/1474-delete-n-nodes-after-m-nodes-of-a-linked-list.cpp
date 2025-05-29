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
    ListNode* deleteNodes(ListNode* head, int m, int n) {

        ListNode *node = head;

        while (node != nullptr) {
            for (int i = 0; i < m - 1 && node != nullptr; ++i) {
                node = node -> next;
            }
            if (node == nullptr) break;

            ListNode *nodeDel = node -> next;
            for (int i = 0; i < n - 1 && nodeDel != nullptr; ++i) {
                nodeDel = nodeDel -> next;
            }
            if (nodeDel == nullptr) {
                node -> next = nullptr;
                break;
            }
            node -> next = nodeDel -> next;
            node = node -> next;
        }
        return head;
    }
};
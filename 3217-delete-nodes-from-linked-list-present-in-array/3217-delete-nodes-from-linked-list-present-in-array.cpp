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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> hashSet(nums.begin(), nums.end());
        ListNode *dummyHead = new ListNode(0, head);
        for (ListNode *curr = head, *prev = dummyHead; curr != nullptr; curr = curr -> next) {
            if (hashSet.count(curr -> val)) {
                prev -> next = curr -> next;
                curr = prev;
            }
            prev = curr;
        }
        return dummyHead -> next;
    }
};
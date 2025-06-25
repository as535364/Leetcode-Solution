/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        stack<ImmutableListNode*> st;
        ImmutableListNode *node = head;
        
        while (node != nullptr) {
            st.push(node);
            node = node -> getNext();
        }
        
        while(!st.empty()) {
            auto currNode = st.top();
            st.pop();
            currNode -> printValue();
        }
    }
};
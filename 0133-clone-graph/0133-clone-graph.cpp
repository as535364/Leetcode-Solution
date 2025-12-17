/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> vis;
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return node;
        stack<Node*> st;
        st.push(node);
        vis[node] = new Node(node -> val);

        while (!st.empty()) {
            Node *nowNode = st.top(), *newNode = nullptr;
            st.pop();
            auto it = vis.find(nowNode);
            if (it == vis.end()) {
                newNode = new Node(nowNode -> val);
            }
            else {
                newNode = it -> second;
            }

            for (Node *neighbor : nowNode -> neighbors) {
                cout << neighbor -> val << " ";
                Node *newNeighborNode = nullptr;
                auto newNeighborNodeIt = vis.find(neighbor);
                if (newNeighborNodeIt == vis.end()) {
                    newNeighborNode = new Node(neighbor -> val);
                    vis[neighbor] = newNeighborNode;
                    st.push(neighbor);
                }
                else {
                    newNeighborNode = newNeighborNodeIt -> second;
                }
                newNode -> neighbors.push_back(newNeighborNode);
            }
        }
        return vis[node];
    }
};
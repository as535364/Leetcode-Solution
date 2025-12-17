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
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        queue<Node *> q;
        unordered_map<int, Node*> node_map;
        unordered_set<int> visit;

        Node *res_node = new Node(node -> val);
        node_map[node -> val] = res_node;
        visit.insert(node -> val);
        q.push(node);

        while (!q.empty()) {
            Node *curr_node = q.front();
            q.pop();
            cout << curr_node -> val << endl;

            Node *copy_node = nullptr;
            auto it = node_map.find(curr_node -> val);
            copy_node = it -> second;

            for (Node* neighbor_node : curr_node -> neighbors) {
                Node *copy_neighbor_node = nullptr;
                auto it = node_map.find(neighbor_node -> val);
                if (it == node_map.end()) {
                    copy_neighbor_node = new Node(neighbor_node -> val);
                    node_map[neighbor_node -> val] = copy_neighbor_node;
                }
                else {
                    copy_neighbor_node = it -> second;
                }
                copy_node -> neighbors.push_back(copy_neighbor_node);

                if (visit.find(neighbor_node -> val) != visit.end()) continue;
                visit.insert(neighbor_node -> val);
                q.push(neighbor_node);
            }
        }
        return res_node;
    }
};
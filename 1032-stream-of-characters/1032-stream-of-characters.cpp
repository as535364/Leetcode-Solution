class Node {
public:
    bool isEnd;
    unordered_map<char, Node*> next;
    Node (bool isEnd): isEnd(isEnd) {}
};

class Suffix {
private:
    Node *root;
public:
    Suffix() {
        root = new Node(false);
    }
    
    void add(string &s) {
        Node *curr = root;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (curr -> next[s[i]] == nullptr) curr -> next[s[i]] = new Node(false);
            curr = curr -> next[s[i]];
        }
        curr -> isEnd = true;
    }
    
    bool query(list<char> &ll) {
        Node *curr = root;
        for (auto it = ll.rbegin(); it != ll.rend(); ++it) {
            char c = *it;
            curr = curr -> next[c];
            if (curr == nullptr) return false;
            if (curr -> isEnd) return true;
        }
        return false;
    }
};

class StreamChecker {
private:
    int maxLen;
    Suffix suffix;
    list<char> curr;
public:
    StreamChecker(vector<string>& words) {
        for (string &word : words) {
            maxLen = max(maxLen, (int)word.length());
            suffix.add(word);
        }
    }
    
    bool query(char letter) {
        curr.push_back(letter);
        if (curr.size() > maxLen) curr.pop_front();
        return suffix.query(curr);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
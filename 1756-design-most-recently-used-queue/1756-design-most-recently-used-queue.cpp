class MRUQueue {
private:
    list<int> ll;
public:
    MRUQueue(int n) {
        for (int i = 1; i <= n; ++i) {
            ll.push_back(i);
        }
    }
    
    int fetch(int k) {
        auto it = ll.begin();
        while (--k) ++it;
        int res = *it;
        ll.erase(it);
        ll.push_back(res);
        return res;
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */
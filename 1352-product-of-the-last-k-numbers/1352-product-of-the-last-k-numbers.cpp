class ProductOfNumbers {
private:
    list<int> li;
public:
    ProductOfNumbers() {
    }
    
    void add(int num) {
        li.push_back(num);
    }
    
    int getProduct(int k) {
        int i = 0, res = 1;
        for (auto it = li.rbegin(); it != li.rend(); ++it) {
            if (i++ == k) break;
            res *= *it;
            if (res == 0) return 0;
        }
        return res;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
class Solution {
private:
    vector<int> power;
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }
    int convert(const vector<int>& digits) {
        return digits[0] + digits[1] * 10 + digits[2] * 100 + digits[3] * 1000;
    }
public:
    int minOperations(int n, int m) {
        if (isPrime(n) || isPrime(m)) return -1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> valCost;
        
        
        power.resize(4, 1);
        for (int i = 1; i < 4; ++i) {
            power[i] = 10 * power[i - 1];
        }
        

        valCost[n] = n;
        pq.push({n, n});
        
        while (!pq.empty()) {
            auto [cost, val] = pq.top();
            pq.pop();
            if (val == m) return cost;

            int mostSigBitSize = 1;
            for (int i = 3; i >= 0; --i) {
                if (val / power[i] != 0) {
                    mostSigBitSize = i + 1;
                    break;
                }
            }


            // min: 0001 max: 9999
            vector<int> digits(4);
            for (int i = 0; i < mostSigBitSize; ++i) {
                digits[i] = val / power[i] % 10;
            }
            for (int i = 0; i < mostSigBitSize; ++i) {
                // 4321
                int digitBak = digits[i];
                
                if (digits[i] != 0) {
                    digits[i] -= 1;
                    int newNum = convert(digits);
                    if (!isPrime(newNum) && (!valCost.count(newNum) || valCost[newNum] > cost + newNum)) {
                        valCost[newNum] = cost + newNum;
                        pq.push({cost + newNum, newNum});
                    }
                    digits[i] = digitBak;
                }
                if (digits[i] != 9) {
                    digits[i] += 1;
                    int newNum = convert(digits);
                    if (!isPrime(newNum) && (!valCost.count(newNum) || valCost[newNum] > cost + newNum)) {
                        valCost[newNum] = cost + newNum;
                        pq.push({cost + newNum, newNum});
                    }
                    digits[i] = digitBak;
                }
            }
        }
        return -1;
    }
};
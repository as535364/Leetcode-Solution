class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, unordered_set<string>> make;
        unordered_map<string, int> inDeg;
        unordered_set<string> recipesSet(recipes.begin(), recipes.end());

        for (int i = 0; i < recipes.size(); ++i) {
            for (int j = 0; j < ingredients[i].size(); ++j) {
                const string &from = ingredients[i][j];
                const string &to = recipes[i];
                make[from].insert(to);
                ++inDeg[to];
            }
        }

        vector<string> res;
        queue<string> q(supplies.begin(), supplies.end());
        while (!q.empty()) {
            string d = q.front();
            q.pop();
            if (recipesSet.count(d)) res.push_back(d);
            for (const string &to : make[d]) {
                if(--inDeg[to] == 0) q.push(to);
            }
        }
        return res;
    }
};
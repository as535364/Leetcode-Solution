class FoodRatings {
private:
    struct ratingComp {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
            return a.first == b.first ? a.second > b.second : a.first < b.first;
        }
    };
    unordered_map<string, set<pair<int, string>, ratingComp>> ratingsMap;
    unordered_map<string, string> food2Cusine;
    unordered_map<string, int> food2Rating;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            string &food = foods[i], &cuisine = cuisines[i];
            int rating = ratings[i];
            food2Cusine[food] = cuisine;
            food2Rating[food] = rating;
            ratingsMap[cuisine].insert({rating, food});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food2Cusine[food];
        int rating = food2Rating[food];
        auto it = ratingsMap[cuisine].find({rating, food});
        if (it != ratingsMap[cuisine].end()) {
            pair<int, string> newRecord = make_pair(newRating, food);
            ratingsMap[cuisine].erase(it);
            food2Rating[food] = newRating;
            ratingsMap[cuisine].insert(newRecord);
        }
    }
    
    string highestRated(string cuisine) {
        return ratingsMap[cuisine].rbegin() -> second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
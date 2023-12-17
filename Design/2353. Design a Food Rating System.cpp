class FoodRatings {
public:
    unordered_map<string, int> food_rating;
    unordered_map<string, string> food_cuisine;
    unordered_map<string, set<pair<int, string>>> cuisine_rating_food;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0;i<n;i++){
            cuisine_rating_food[cuisines[i]].insert({-1 * ratings[i], foods[i]});
            food_cuisine[foods[i]] = cuisines[i];
            food_rating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        int oldRating = food_rating[food];
        string cuisine = food_cuisine[food];

        food_rating[food] = newRating;
        cuisine_rating_food[cuisine].erase({-1 * oldRating, food});
        cuisine_rating_food[cuisine].insert({-1 * newRating, food});
    }
    
    string highestRated(string cuisine) {
        return begin(cuisine_rating_food[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

// Last updated: 4/3/2026, 1:53:37 PM
class FoodRatings {
    unordered_map<string, pair<string, int>> foodMap;
    unordered_map<string, set<pair<int, string>>> cuisineMap;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];
            foodMap[food] = {cuisine, rating};
            cuisineMap[cuisine].insert({-rating, food});
        }
    }

    void changeRating(string food, int newRating) {
        auto [cuisine, oldRating] = foodMap[food];
        cuisineMap[cuisine].erase({-oldRating, food});
        cuisineMap[cuisine].insert({-newRating, food});
        foodMap[food].second = newRating;
    }
    string highestRated(string cuisine) {
        return cuisineMap[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
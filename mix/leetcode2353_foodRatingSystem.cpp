


class FoodRatings {
public:
    #define P pair<int, string>

    // Comparator: higher rating first, then lexicographically smaller string
    struct cmp {
        bool operator()(const P& a, const P& b) const {
            if (a.first != b.first) 
                return a.first > b.first;
            return a.second < b.second;
        }
    };

    unordered_map<string, int> foodToIndex;
    unordered_map<string, set<P, cmp>> cuisinesToRatingFood;
    vector<int> ratings2;
    vector<string> cuisines2;
    int n;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        n = foods.size();
        ratings2 = ratings;
        cuisines2 = cuisines;

        for (int i = 0; i < n; i++) {
            foodToIndex[foods[i]] = i;
            cuisinesToRatingFood[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }

    int getRatings(int indx) {
        return ratings2[indx];
    }

    void changeRating(string food, int newRating) {
        int indx = foodToIndex[food];
        int oldRating = ratings2[indx];
        string cui = cuisines2[indx];

        // erase old
        auto& st = cuisinesToRatingFood[cui];
        st.erase({oldRating, food});

        // insert new
        st.insert({newRating, food});
        ratings2[indx] = newRating;
    }
    
    string highestRated(string cuisine) {
        auto& st = cuisinesToRatingFood[cuisine];
        return st.begin()->second;
    }
};




/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

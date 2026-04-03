// Last updated: 4/3/2026, 1:55:03 PM
class MovieRentingSystem {
    struct Entry {
        int price, shop, movie;
        bool operator<(const Entry& other) const {
            if (price != other.price)
                return price < other.price;
            if (shop != other.shop)
                return shop < other.shop;
            return movie < other.movie;
        }
    };

    unordered_map<int, set<pair<int, int>>> available;
    unordered_map<long long, int> priceMap;
    set<Entry> rented;

    long long encode(int shop, int movie) {
        return ((long long)shop << 17) | movie;
    }

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            priceMap[encode(shop, movie)] = price;
            available[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        auto& s = available[movie];
        for (auto it = s.begin(); it != s.end() && ans.size() < 5; ++it) {
            ans.push_back(it->second);
        }
        return ans;
    }

    void rent(int shop, int movie) {
        int price = priceMap[encode(shop, movie)];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = priceMap[encode(shop, movie)];
        rented.erase({price, shop, movie});
        available[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        for (auto it = rented.begin(); it != rented.end() && ans.size() < 5;
             ++it) {
            ans.push_back({it->shop, it->movie});
        }
        return ans;
    }
};

// Last updated: 4/3/2026, 1:58:26 PM
class StockSpanner {
public:
    stack<pair<int, int>> s;

    StockSpanner() {}

    int next(int price) {
        int span = 1;

        while (!s.empty() && s.top().first <= price) {
            span += s.top().second;
            s.pop();
        }

        s.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
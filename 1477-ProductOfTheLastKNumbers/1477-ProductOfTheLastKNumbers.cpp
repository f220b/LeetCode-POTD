// Last updated: 4/3/2026, 1:56:54 PM
class ProductOfNumbers {
public:
    vector<int> stream = {1};
    int n = 1;
    int lastZero = -1;
    ProductOfNumbers() {
        n = 1;
        lastZero = -1;
    }

    void add(int num) {
        if (num == 0) {
            lastZero = n;
        }
        if (stream.back() == 0) {
            stream.push_back(num);
        } else {
            stream.push_back(stream.back() * num);
        }
        n++;
    }

    int getProduct(int k) {
        if (lastZero >= n - k) {
            return 0;
        }
        if (stream[n - k - 1] == 0) {
            return stream[n - 1];
        }
        return stream[n - 1] / stream[n - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
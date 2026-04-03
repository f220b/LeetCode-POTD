// Last updated: 4/3/2026, 2:01:44 PM
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";

        string res;
        if ((numerator < 0) ^ (denominator < 0))
            res += "-";

        long long n = (long long)numerator;
        long long d = (long long)denominator;
        if (n < 0)
            n = -n;
        if (d < 0)
            d = -d;

        res += to_string(n / d);
        long long rem = n % d;
        if (rem == 0)
            return res;

        res += ".";
        unordered_map<long long, int> mp;

        while (rem != 0) {
            if (mp.count(rem)) {
                res.insert(mp[rem], "(");
                res += ")";
                break;
            }
            mp[rem] = res.size();
            rem *= 10;
            res += to_string(rem / d);
            rem %= d;
        }
        return res;
    }
};

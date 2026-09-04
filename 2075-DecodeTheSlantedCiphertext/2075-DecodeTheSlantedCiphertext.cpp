// Last updated: 9/5/2026, 12:24:13 AM
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();
        if (n == 0) return "";
        
        int cols = n / rows;
        string res = "";

        for (int j = 0; j < cols; ++j) {
            int r = 0, c = j;
            while (r < rows && c < cols) {
                res += encodedText[r * cols + c];
                r++;
                c++;
            }
        }

        while (!res.empty() && res.back() == ' ') {
            res.pop_back();
        }

        return res;
    }
};
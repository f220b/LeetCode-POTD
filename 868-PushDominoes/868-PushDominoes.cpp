// Last updated: 4/3/2026, 1:58:41 PM
class Solution {
public:
    void doubleDominoesPush(int start, int end, string& dominoes) {
        while (start < end) {
            dominoes[start++] = 'R';
            dominoes[end--] = 'L';
        }
    }
    void leftDominoesPush(int start, int end, string& dominoes) {
        while (start <= end) {
            dominoes[start++] = 'L';
        }
    }
    void rightDominoesPush(int start, int end, string& dominoes) {
        while (start <= end) {
            dominoes[start++] = 'R';
        }
    }
    string pushDominoes(string dominoes) {
        int lastL = -1, lastR = -1;
        int n = dominoes.size();

        for (int pos = 0; pos < n; pos++) {
            if (dominoes[pos] == '.')
                continue;

            if (dominoes[pos] == 'L') {
                if (lastL < lastR) {
                    doubleDominoesPush(lastR + 1, pos - 1, dominoes);
                } else if (lastL == -1 || lastL > lastR) {
                    leftDominoesPush(lastL + 1, pos - 1, dominoes);
                }
                lastL = pos;
            } else if (dominoes[pos] == 'R') {
                if (lastR > lastL) {
                    rightDominoesPush(lastR, pos, dominoes);
                }
                lastR = pos;
            }
        }

        if (lastR > lastL) {
            rightDominoesPush(lastR, n - 1, dominoes);
        }

        return dominoes;
    }
};

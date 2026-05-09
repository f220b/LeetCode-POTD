// Last updated: 9/5/2026, 8:04:30 pm
1class Solution {
2public:
3    vector<int> scoreValidator(vector<string>& events) {
4        int score = 0, counter = 0;
5        for (string event : events) {
6            if (counter == 10)
7                return {score, counter};
8
9            if (event == "W")
10                counter++;
11            else if (event == "WD" || event == "NB")
12                score++;
13            else
14                score += stoi(event);
15        }
16        return {score, counter};
17    }
18};
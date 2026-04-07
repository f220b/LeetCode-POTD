// Last updated: 7/4/2026, 11:48:56 pm
1class Robot {
2    int w, h, pos, total;
3    bool moved;
4
5public:
6    Robot(int width, int height) {
7        w = width;
8        h = height;
9        pos = 0;
10        total = 2 * (w + h) - 4;
11        moved = false;
12    }
13
14    void step(int num) {
15        moved = true;
16        pos = (pos + num) % total;
17    }
18
19    vector<int> getPos() {
20        if (pos < w)
21            return {pos, 0};
22        if (pos < w + h - 1)
23            return {w - 1, pos - (w - 1)};
24        if (pos < 2 * w + h - 2)
25            return {w - 1 - (pos - (w + h - 2)), h - 1};
26        return {0, h - 1 - (pos - (2 * w + h - 3))};
27    }
28
29    string getDir() {
30        if (!moved)
31            return "East";
32        if (pos > 0 && pos < w)
33            return "East";
34        if (pos >= w && pos < w + h - 1)
35            return "North";
36        if (pos >= w + h - 1 && pos < 2 * w + h - 2)
37            return "West";
38        if (pos >= 2 * w + h - 2 || pos == 0)
39            return "South";
40        return "East";
41    }
42};
43
44/**
45 * Your Robot object will be instantiated and called as such:
46 * Robot* obj = new Robot(width, height);
47 * obj->step(num);
48 * vector<int> param_2 = obj->getPos();
49 * string param_3 = obj->getDir();
50 */
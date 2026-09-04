// Last updated: 9/5/2026, 12:24:19 AM
class Robot {
    int w, h, pos, total;
    bool moved;

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        pos = 0;
        total = 2 * (w + h) - 4;
        moved = false;
    }

    void step(int num) {
        moved = true;
        pos = (pos + num) % total;
    }

    vector<int> getPos() {
        if (pos < w)
            return {pos, 0};
        if (pos < w + h - 1)
            return {w - 1, pos - (w - 1)};
        if (pos < 2 * w + h - 2)
            return {w - 1 - (pos - (w + h - 2)), h - 1};
        return {0, h - 1 - (pos - (2 * w + h - 3))};
    }

    string getDir() {
        if (!moved)
            return "East";
        if (pos > 0 && pos < w)
            return "East";
        if (pos >= w && pos < w + h - 1)
            return "North";
        if (pos >= w + h - 1 && pos < 2 * w + h - 2)
            return "West";
        if (pos >= 2 * w + h - 2 || pos == 0)
            return "South";
        return "East";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
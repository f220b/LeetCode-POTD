// Last updated: 4/3/2026, 1:50:28 PM
class Solution {
public:
    bool checkLineIntersections(vector<pair<int, int>> coordinates) {
        int lines = 0, overlap = 0;
        for (int i = 0; i < coordinates.size(); i++) {
            if (coordinates[i].second == 1) {
                overlap++;
            } else {
                overlap--;
            }
            if (overlap == 0) {
                lines++;
            }
            if (lines >= 3) {
                return true;
            }
        }
        return false;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> xCoordinates, yCoordinates;
        for (auto& rectangle : rectangles) {
            xCoordinates.push_back({rectangle[0], 1});
            yCoordinates.push_back({rectangle[1], 1});
            xCoordinates.push_back({rectangle[2], 0});
            yCoordinates.push_back({rectangle[3], 0});
        }
        sort(xCoordinates.begin(), xCoordinates.end());
        sort(yCoordinates.begin(), yCoordinates.end());
        return checkLineIntersections(yCoordinates) ||
               checkLineIntersections(xCoordinates);
    }
};
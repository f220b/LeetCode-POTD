// Last updated: 4/3/2026, 1:54:16 PM
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size(), n = bank[0].size();
        vector<int> numberOfDevices(m, 0);

        for (int i = 0; i < m; i++) {
            string s = bank[i];
            int count = 0;
            for (char c : s)
                if (c == '1')
                    count++;
            numberOfDevices[i] = count;
        }
        int prevDevice = numberOfDevices[0];
        int total = 0;
        for(int i = 1; i < m; i++) {
            int currDevice = numberOfDevices[i];
            if(currDevice == 0)
                continue;
            total += (prevDevice * currDevice);
            prevDevice = currDevice;
        }
        return total;
    }
};
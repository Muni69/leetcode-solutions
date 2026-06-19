class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> altitude(gain.size() + 1);

        altitude[0] = 0;

        // Build altitude array
        for (int i = 0; i < gain.size(); i++) {
            altitude[i + 1] = altitude[i] + gain[i];
        }

        // Find maximum altitude
        int highest = altitude[0];
        for (int i = 0; i < altitude.size(); i++) {
            highest = max(highest, altitude[i]);
        }

        return highest;
    }
};
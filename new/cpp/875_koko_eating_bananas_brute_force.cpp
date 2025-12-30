class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // idea: brute force
        // from speed = 1 to until the max(piles), try everything and choose the minimum speed
        int speed = 1;
        while (true) {
            long long totalHours = 0;
            for (int bananas: piles) {
                totalHours += (bananas + speed - 1) / speed;
                // in c++ "/" always does integer division and rounds down.
                // so this is the trick we do to ceil up. same as ceil(bananas / speed) in python. 
                // give enough numerator for the denominator to give correct value ceiled up. 
            }

            if (totalHours <= h) {
                return speed;
            }

            speed += 1;
        }

        return speed;
    }
    // time: O(m * n) = where m = max(piles) and n = length of piles
    // space: O(1)
};

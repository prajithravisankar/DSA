class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // idea: do binary search between 1 and max(piles) to find out the current speed and check if it complete
        // all bananas in a pile do this until we find min potential speed and update our potential speed
        // even if we find our current speed completes all bananas, there could be lesser speed, so move the right
        // pointer to the left of our current speed
        // if current speed does not complete all bananas in a pile, move the left pointer to the right of current speed
        // increasing current speed
        int left = 1;
        int right = *max_element(piles.begin(), piles.end()); // for list we have to use *max_element
        int potential_speed = right;

        while (left <= right) {
            long long total_hours = 0;
            int current_speed = left + (right - left) / 2;
            for (int bananas: piles) {
                total_hours += ceil(static_cast<double>(bananas) / current_speed);
            }

            if (total_hours <= h) {
                potential_speed = current_speed;
                right = current_speed - 1;
            } else {
                left = current_speed + 1;
            }
        }

        return potential_speed;
    }

    // time: O(nlogm), n - length of the piles (inner loop), and m - maximum bananas in a pile, doing binary search 
    // (outer loop) between 1 and m takes logm time. 
    // space: O(1)
};

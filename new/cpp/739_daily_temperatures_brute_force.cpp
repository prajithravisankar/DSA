class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // idea: brute force
        // find temp > curr temp in the given list, if not found add 0. 
        // track how many days it take to reach temp > curr temp from the curr day. 
        int n = temperatures.size();
        vector<int> until(n);
        for (int i = 0; i < temperatures.size(); i++) {
            int j = i + 1;
            int count = 1;
            while (j < n) {
                if (temperatures[j] > temperatures[i]) {
                    break;
                }
                count++;
                j++;
            }
            until[i] = (j == n) ? 0 : count;
        }

        return until;
    }
    // time: O(n^2)
    // space: O(n)
};

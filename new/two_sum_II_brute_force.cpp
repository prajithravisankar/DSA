class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // idea: brute force
        for (int i = 0; i < numbers.size(); i++) {
            for (int j = i + 1; j < numbers.size(); j++) {
                if (numbers[i] + numbers[j] == target) {
                    return {i + 1, j + 1};
                }
            }
        }

        return {};
    }
    // time: O(n^2)
    // space: O(1)
};

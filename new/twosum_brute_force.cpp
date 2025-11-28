class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // go through the loop, and for each element go through the loop again starting
        // next element, if they add up to target, return list of indices, else 
        // return empty array
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    vector<int> indices = {i, j};
                    return indices;
                }
            }
        }

        return {};
        // time: O(n^2)
        // space: O(1)
    }
};

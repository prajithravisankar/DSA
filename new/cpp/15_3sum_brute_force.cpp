class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // idea: brute force
        // create a set that tracks the set of triplets that add up to 0
        // brute force loop the given list to find combinations of triplets that adds up to 0. 
        if (nums.size() < 3) {
            return {};
        }

        sort(nums.begin(), nums.end());
        set<vector<int>> result; // in c++ set can have unhashables inside it. But it will
        // still make sure all the list inside are unique. 
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        result.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        return vector<vector<int>>(result.begin(), result.end());
    }
    // time: O(n^3), where n is the number of elements in the input list
    // space: O(m), where m is the number of triplets in the set. 
};

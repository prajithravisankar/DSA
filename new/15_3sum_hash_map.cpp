class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // idea: hash map
        // 2 iterations, get two numbers from these two iterations, and see if the target is in 
        // the frequency_counter, where target = -(first number + second number). If it is 
        // in the frequency_counter, then we have a valid triplet. 
        sort(nums.begin(), nums.end());
        unordered_map<int, int> frequency_counter;

        for (int i = 0; i < nums.size(); i++) {
            frequency_counter[nums[i]]++;
        }

        vector<vector<int>> valid_triplet;
        for (int i = 0; i < nums.size(); i++) {
            frequency_counter[nums[i]]--; // because we are currently visiting this value
            if (i > 0 && nums[i] == nums[i - 1]) continue; // because current value
            // and previous value are same, so we can safely assume we have iterated for
            // previous value, if that iteration had any valid triplets it must have been added
            // in other words this prevents duplicates
            for (int j = i + 1; j < nums.size(); j++) {
                frequency_counter[nums[j]]--;
                if (j - 1 > i && nums[j] == nums[j - 1]) continue;
                int target = -(nums[i] + nums[j]);
                if (frequency_counter[target] > 0) {
                    valid_triplet.push_back({nums[i], nums[j], target});
                }
            }

            for (int k = i + 1; k < nums.size(); k++) {
                frequency_counter[nums[k]]++; // restore all the used values from the previous
                // iteration (jth iteration)
            }
        }

        return valid_triplet;
    }
    // time: O(n^2)
    // space: O(m)
};

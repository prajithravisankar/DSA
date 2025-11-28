class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // idea: two pointer
        // get the firs value (should not be positive, because in a sorted list of numbers, 
        // if the first num is +ve, the second and third will also be +ve, and
        // no sum of 3 positive numbers will be 0). 
        // iterate after the first value and get two more values (second and third num)
        // using two pointer method. If the sum adds up to 0, we have a valid triplet.
        sort(nums.begin(), nums.end());
        vector<vector<int>> valid_triplets;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];
                if (total > 0) {
                    right -= 1;
                } else if (total < 0) {
                    left += 1;
                } else {
                    valid_triplets.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (right > left && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }

        return valid_triplets;
    }
    // time: O(n^2)
    // space: O(1 or n) depending on the sorting algorithm, O(m) for extra space for the output
    // where m is the length of number of triplets that are valid. 
};

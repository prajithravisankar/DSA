/*
nums.begin()  → &nums[0]
nums.end()    → &nums[nums.size()]   // one past the end
*/


class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // O(nlogn)

        for (int i = 1; i < nums.size(); i++) { // O(n)
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }

        return false;
        // time : O(nlogn) + O(n) = O(nlogn)
        // space : O(1) because of in place sorting, if not O(n)
    }
};

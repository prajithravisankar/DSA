class Solution {
public:
    int search(vector<int>& nums, int target) {
        // idea: use built in functions (iterators)

        // this will find out the first lowest address where we can insert the target
        auto iterator = lower_bound(nums.begin(), nums.end(), target);
        return ((iterator != nums.end() && *iterator == target) ? iterator - nums.begin() : - 1);
    }
    // time: O(logn)
    // space: O(1)
};

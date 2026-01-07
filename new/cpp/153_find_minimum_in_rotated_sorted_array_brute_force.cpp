class Solution {
public:
    int findMin(vector<int>& nums) {
        // idea: use brute force (in-built)
        return *min_element(nums.begin(), nums.end());
    }
    // time: O(n)
    // space: O(1)
};

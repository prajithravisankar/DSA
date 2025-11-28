class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // optimal approach is using prefix and postfix in place of the output
        // array and updating it with the product of postfix with prefix (already
        // in the output array after 1st go) in the output array
        int prefix = 1;
        vector<int> output(nums.size(), 1); // not counted as O(n) as per qn. 
        for (int i = 1; i < nums.size() + 1; i++) {
            output[i - 1] = prefix;
            prefix = prefix * nums[i - 1];
        }

        int postfix = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            output[i] = postfix * output[i];
            postfix = postfix * nums[i]; 
        }

        return output;
        // time: O(n)
        // space: O(1)
    }
};

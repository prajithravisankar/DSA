class Solution {
public:
    int findMin(vector<int>& nums) {
        // idea: binary search
        // split the given array into two parts, find which part is not sorted, then that part has
        // the LOW or the BREAKING POINT
        // the low or the breaking point is the places where the rotation happens. It won't happen at the part
        // where if the part is already sorted, it will happen on the part that is not sorted
        int min_element = nums[0];
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            if (nums[left] < nums[right]) {
                min_element = min(min_element, nums[left]);
                break;
            }

            int middle_index = left + (right - left) / 2;
            min_element = min(min_element, nums[middle_index]);

            if (nums[left] <= nums[middle_index]) {
                // this part is sorted
                left = middle_index + 1;
            } else {
                right = middle_index - 1;
            }
        }

        return min_element;
    }
    // time: O(logn)
    // space: O(1)
};

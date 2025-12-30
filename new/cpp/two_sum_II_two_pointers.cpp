class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // idea: use two pointer
        // track left and right numbers
        // if they add up to target, return their indices (+ 1)
        // if their sum < target, increase left pointer, if their sum > target, decrease right pointer
        // do this until left < right
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int val = numbers[left] + numbers[right];
            if (val < target) {
                left++;
            } else if (val > target) {
                right--;
            } else {
                return {left + 1, right + 1};
            }
        }
        return {};
    }
    // time: O(n)
    // space: O(1)
};


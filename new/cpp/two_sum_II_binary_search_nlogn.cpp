class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // idea: binary search
        // for every number (our current number) in the numbers, 
        // do binary search from the next number till the end, until we find the complement of our current number
        // such that our current number and complement add up to the target. 
        for (int i = 0; i < numbers.size(); i++) {
            int left = i + 1;
            int right = numbers.size() - 1;
            int value_to_find = target - numbers[i];
            while (left <= right) {
                int middle = left + (right - left) / 2;
                if (numbers[middle] == value_to_find) {
                    return {i + 1, middle + 1};
                } else if (numbers[middle] < value_to_find) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
        }

        return {};
    }
    // time: O(nlogn)
    // space: O(1)
};

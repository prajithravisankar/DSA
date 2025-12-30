class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // idea: hashmap one go
        // iterate through each number (our current number)
        // for each number find the complement that adds up to the target
        // if the complement exists in the hashmap, return the complement's and then the current number's index (i + 1)
        // else add the current number to the hashmap (so when we go for numbers down the array, this will
        // potentially show up as a complment for our current number at that time). 
        unordered_map<int, int> val_to_index;
        for (int i = 0; i < numbers.size(); i++) {
            int complement = target - numbers[i];
            if (val_to_index.count(complement)) {
                return {val_to_index[complement], i + 1};
            }
            val_to_index[numbers[i]] = i + 1;
        }
        return {};
    }
    // time: O(n)
    // space: O(n)
};

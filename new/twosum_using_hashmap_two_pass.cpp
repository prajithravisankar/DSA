class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // create a hashmap and put the value and index from the list of num into the hashmap so we don't have any duplicates. 
        // hashmap will be like this-> val : index. The index will be the most recent index visited in the list during iteration. 
        // go through the list again and find difference between the target and the current val, and see if that is present
        // in the hashmap, and also check if the diff is present it is not our current value, it is not the one with the same index
        // as current value, this is to check if we are seeing the current value and don't add current value twice to the output
        // if not present return empty list
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i++) {
            hashMap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums[i]; 
            if (hashMap.count(difference) && hashMap[difference] != i) { // hashMap.count(val) returns either 0 or 1 because there are no duplicates in map. 
                return {min(i, hashMap[difference]), max(i, hashMap[difference])};
            }
        }

        return {};
    }

    // time: O(n)
    // space: O(n) hashMap could contain all the values from nums b/c nums didn't have no duplicates
};

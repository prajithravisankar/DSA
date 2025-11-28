class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // create an unordered_set for the nums with nums.begin() -> first element
        // to the one after last element nums.end() -> points one next to last element
        // get the size of the set, it should have size of set with no duplicates. 
        // if that size is less than size of list, then we have duplicate. 
        return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
        // time: O(n) for checking if each item already exists in unordered set, if not creating and putting it in hash map. 
        // space: O(n) for internal hashmap by undordered_set
    }
};

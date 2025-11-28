class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // create an unordered_set for tracking seen items
        // if seen return true, else return false
        unordered_set<int> seen;
        for (int num: nums) {
            if (seen.count(num)) {
                // seen.count(num) returns either 0 or 1 always
                // because of unordered_set
                return true;
            }

            seen.insert(num);
        }

        return false;
        // time complexity : O(n)
        // space complexity : O(n)
    }
};

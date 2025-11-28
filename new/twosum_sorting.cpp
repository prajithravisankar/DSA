class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // create a master list of pairs of <val, index> and sort them based on val. 
        // track and loop with start and end pointers. 
        // if start's val and end's val's sum == target, return their indices
        // if start's val and end's val's sum > target, reduce the end pointer to left by one
        // if start's val and end's val's sum < target, move the start pointer to the right by one
        // at the very end return empty vector
        vector<pair<int, int>> master; // pair access is done by pair.first, pair.second not pair[0] or pair[1]
        for (int i = 0; i < nums.size(); i++) {
            master.push_back({nums[i], i});
        }

        sort(master.begin(), master.end()); // this will sort based on lexicological order
        // sorts based on master[0], master[1], ..., master[n], but if two things are same
        // it will then sort by comparing master[x][1] master[y][1] where master[x] == master[y]

        int start = 0;
        int end = master.size() - 1;

        while (start < end) {
            int mySum = master[start].first + master[end].first;
            if (mySum == target) {
                return {min(master[start].second, master[end].second), max(master[start].second, master[end].second)};
            } else if (mySum > target) {
                end -= 1;
            } else {
                start += 1;
            }
        }

        return {};
    }

    // time: O(nlogn) due to sorting
    // space: O(n) due to additional creation of master arrays
};

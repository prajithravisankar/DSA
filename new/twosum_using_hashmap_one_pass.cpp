class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // create a hashmap of previously visited values and indices. 
        // if the difference between target and current value is in the previously visited hashmap return 
        // the indices, if not return empty list. 
        unordered_map<int, int> previouslyVisited;
        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums[i];
            if (previouslyVisited.count(difference)) {
                return {previouslyVisited[difference], i};
            }
            previouslyVisited[nums[i]] = i;
        }

        return {};
    }

    // time: O(n)
    // space: O(n)
};

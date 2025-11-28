class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> path;
        vector<int> result;
        explore(nums, target, 0, path, result);
        return result;
    }

private:
    void explore(vector<int>& nums, int target, int start, vector<int>& path, vector<int>& result) {
        if (path.size() == 2) {
            int sum = nums[path[0]] + nums[path[1]];
            if (sum == target) {
                result = path;
            }
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (!result.empty()) return;

            path.push_back(i);
            explore(nums, target, i + 1, path, result);
            path.pop_back();
        }
    }
};

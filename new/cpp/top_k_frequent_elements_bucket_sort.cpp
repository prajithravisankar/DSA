class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // create a frequency map
        // create a list of n + 1 buckets (array) representing frequency. Each bucket represents potential frequency. 
        // why n + 1, because the most a number can be frequent in the given nums is nums. 
        // meaning: [1, 1, 1, 1] this is len 4, and 1 can be atmost 4 frequent. [[] [] [] [1]]
        // iterate in reverse order and get k elements from the bucket and put it in a result list and return the list
        unordered_map<int, int> freq;
        vector<vector<int>> buckets(nums.size() + 1);

        for (int num: nums) {
            freq[num]++;
        }

        for (const auto &pair: freq) {
            buckets[pair.second].push_back(pair.first);
        }

        vector<int> result;
        for (int i = buckets.size() - 1; i > 0; i--) {
            for (int num: buckets[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }

    // time: O(n)
    // space: O(n)
};

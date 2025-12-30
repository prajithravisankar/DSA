class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // create a frequncy map
        // make an array out of the frequency map of frequncy, val. 
        // sort the array
        // get the last k elements
        unordered_map<int, int> frequency_map;
        for (const auto &num: nums) {
            frequency_map[num]++;
        }

        vector<pair<int, int>> arr;
        for (const auto &pair: frequency_map) {
            arr.push_back({pair.second, pair.first});
        }

        sort(arr.rbegin(), arr.rend());

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(arr[i].second);
        }

        return result;
    }   

    // time: O(nlogn) for sorting
    // space: O(n)
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // create a frequency map
        // make a heap (frequency, num) out of the frequency map only retaining k elements that are most
        // frequent on each iteration by removing least frequent element up until that point if len of heap
        // exceeds k. out of the remaining k elements from the heap, return the value of num. 
        unordered_map<int, int> frequency;
        for (int i = 0; i < nums.size(); i++) {
            frequency[nums[i]]++; // O(n) because each lookup or insertion is O(1) and we do this for n items. 
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        // priority_queue<data_type, underlying_container_that_holds_data_type, min_heap_or_max_heap>
        // by definition c++ priority queues are max heap unlike python
        for (auto &pair: frequency) { // O(nlogk), we push or pop for all n elements in the given list, by the end we have O(nlogk)
            // each heap push or pop is O(logk) where k is the number of elements in the heap
            min_heap.push({pair.second, pair.first}); // sort by freq first, if freq same, sort by num
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        vector<int> result;
        for (int i = 0; i < k; i++) {
            // O(k) for the push_back
            result.push_back(min_heap.top().second);
            // popping is O(logk)
            min_heap.pop(); // by definition heap.pop() won't return like in python, so we use top. 
        }

        return result;
    }
    // time: O(nlogk)
    // space: O(n + k) ~= O(n) for the frequency map
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // idea: sliding window optimal
        // instead of erasing left and moving one to the right each time, we can update left's position
        // this way: 
        // have a map that tracks previous position of the current value
        // if in the current iteration, right's value exists, update the left's position to 
        // either left itself (the right's value exists, but its position is before the left so we don't 
        // bother) 
        // or right's position + 1 (right's value exists in the map after left's position)
        unordered_map<char, int> char_index;
        int max_window_size = 0;

        int left = 0;
        int right = 0;

        while (right < s.size()) {
            if (char_index.find(s[right]) != char_index.end()) {
                left = max(left, char_index[s[right]] + 1);
            }
            max_window_size = max(max_window_size, right - left + 1);
            char_index[s[right]] = right;
            right++;
        }

        return max_window_size;
    }
    // time: O(n)
    // space: O(m)
};

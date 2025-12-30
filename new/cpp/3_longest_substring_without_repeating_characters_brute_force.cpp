class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // idea: brute force
        // for every character in the given string, iterate starting from the next character until the end
        // and find longest substring without repeating characters. 
        // use unordered_set to tract non-duplicate characters. 
        // if duplicate characters found, break and move to the next character. 

        int max_window_size = 0;

        for (int i = 0 ; i < s.size(); i++) {
            unordered_set<char> window;
            for (int j = i; j < s.size(); j++) {
                if (window.find(s[j]) != window.end()) {
                    // here set.find(something) == set.end(), it means it was not in the given set
                    break;
                }
                window.insert(s[j]);
            }

            max_window_size = max(max_window_size, (int)window.size());
            // window.size() return size_t, need to convert it to int to use with max otherwise throws error
        }

        return max_window_size;
    }
    // time: O(m * n)
    // space: O(m)
};

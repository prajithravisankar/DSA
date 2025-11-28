class Solution {
public:
    bool isAnagram(string s, string t) {
        // if both strings don't have same length, they cannot be anagram
        // create frequency map for first string
        // go throgugh the frequency map for every char in second string
        // if by the end the frequency map has any other number other than 0
        // they cannot be anagram return false
        // if all the characters have 0, return true
        if (s.size() != t.size()) {
            return false;
        }
        map<char, int> frequency_counter;
        for (int i = 0; i < s.size(); i++) {
            if (frequency_counter.count(s[i]) > 0) {
                frequency_counter[s[i]] += 1;
            } else {
                frequency_counter[s[i]] = 1;
            }
        }

        for (int j = 0; j < t.size(); j++) {
            if (frequency_counter.count(t[j]) > 0) {
                frequency_counter[t[j]] -= 1;
            } else {
                return false;
            }
        }

        for (auto& pair: frequency_counter) {
            if (pair.second != 0) {
                return false;
            }
        }

        return true;
        // time complexity: O(n)
        // space complexity: O(1) if fixed alphabets if any type of characters O(n)
    }
};

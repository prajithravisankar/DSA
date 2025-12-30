class Solution {
public:
    bool isAnagram(string s, string t) {
        // check if they don't have same length
        // create hash table and increment for each char in s, and decrement for each char in t
        // if by end the hash table has any other val other than 0, return false
        if (s.size() != t.size()) {
            return false;
        }

        vector<int> hashTable(26, 0);
        // can also do int hashTable[26]; // static array

        for (int i = 0; i < s.size(); i++) {
            hashTable[s[i] - 'a']++;
            hashTable[t[i] - 'a']--;
        }

        for (int val: hashTable) {
            if (val != 0) {
                return false;
            }
        }

        return true;
    }

    // time: O(n + m) => O(n)
    // space: O(1) because we only do this for 26 letters only for this solution
};

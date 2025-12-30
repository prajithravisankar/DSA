class Solution {
public:
    bool isAnagram(string s, string t) {
        // if they don't have same length return false
        // sort them and check if they are equal
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> s_map; // we are using unordered_map because lookup is O(1)
        unordered_map<char, int> t_map; // for normal map in c, it is O(logn) for lookup

        for (int i = 0; i < s.size(); i++) {
            // each lookup is O(1) and there could be n look ups to be done. 
            s_map[s[i]]++; // we don't need to assign 0, because unordered_map[key] when accessed is automatically assigned 0
            t_map[t[i]]++;
        }

        return s_map == t_map; // comparison takes O(n)
        // time: O(n) 
        // space: O(1) for lowercase alphabets or O(n) if any other type is used
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        // if they don't have same length return false
        // sort them and check if they are equal
        if (s.size() != t.size()) {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t; // comparison takes O(n) but sorting dominates so O(nlogn)
        // time: O(nlogn) because sorting in c++ is nlogn
        // space: O(1) or O(n) depending on sorting type
    }
};

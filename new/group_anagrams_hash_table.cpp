class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // create hash table to store values of stringed<frequency counter> : list of strings
        // we create a vector frequency counter to count each char for each string, and string this frequency counter. because vector is not hashable in c++ we need something hashable to store as keys in our map. 
        // for each key, store relevant list of anagrams of strings as list
        // return the list of anagrams for each key as master list. 
        unordered_map<string, vector<string>> map;
        for (const auto &s: strs) {
            vector<int> frequency_counter(26, 0);
            for (auto c: s) {
                frequency_counter[c - 'a'] += 1;
            }

            // because vector is not hashable, we need to have something hashable for keys in a map
            string frequency_string = to_string(frequency_counter[0]);
            for (int i = 1; i < 26; i++) {
                frequency_string += "," + to_string(frequency_counter[i]);
            }

            map[frequency_string].push_back(s);
        }

        vector<vector<string>> result;
        for (const auto &pair: map) {
            result.push_back(pair.second);
        }

        return result;
    }
    // time: O(n * m) - n for each char in each string, m for each string in the original list
    // space: O(n * m) ~= O(m) because n is always 26 in alphabets. 
};

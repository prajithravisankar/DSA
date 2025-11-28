class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // create a unordered map to store sortedString: [...list of anagrams for that sorted string]
        // for each string in the given list, sort it, use it as key, and append the current original string
        // to the sorted string, for each sorted string, we have its list of anagrams from original list
        // by the end of the iteration
        // for each pair the map, append the second item to a master list of list of strings and return it. 

        unordered_map<string, vector<string>> map;
        for (const auto &s: strs) { // const means we promise we won't change the string
            string sortedString = s;
            sort(sortedString.begin(), sortedString.end());
            map[sortedString].push_back(s); // we can directly append the values
        }

        vector<vector<string>> master;
        for (auto &kvPair: map) { // each map element is some sort of key value pair of type 'pair'
            master.push_back(kvPair.second); // we can access keys with pair.first, which cannot be modified
            // we can access values with pair.second which can be modified
        }

        return master;
        // time: O(m * nlogn) - m for length of list, n for length of longest string (nlogn for sorting each string)
        // space: O(m * n) - for the map we could have m keys, and could have n list of strings for each key
    }
};

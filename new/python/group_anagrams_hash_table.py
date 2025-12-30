class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # create a hashmap to contain tuple: list of strings
        # we create the list then convert it to tuple when we use to index and append values
        # tuple is ideal because we are going to create a list of 26 positions for 26 chars
        # this tuple is like a frequency map
        # for each tuple we will append relevant string from origianl list to it
        # then return the list of values of the map
        map = defaultdict(list)  # we need to declare type of values for default dict
        for s in strs:
            char_frequency = [0] * 26
            for c in s:
                char_frequency[ord(c) - ord("a")] += 1

            tuple_char_frequency = tuple(
                char_frequency
            )  # because tuple is hashable in python and list not hashable in python
            map[tuple_char_frequency].append(s)

        return list(map.values())
        # time: O(m * n) because we are not sorting anything so no nlogn, we go through m strings in list, and for each string we go through n characters
        # space: O(m * n) ~= O(m) because we have constant space for the 26 character frequency list worst case we have m number of keys in the map and each one is unique.

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # create a default dictionary for map
        # loop through each string
        # sort each string based on lexical order
        # use sorted string as key and append the current original string in the value
        # for the key which is the sorted version of the current original string
        # loop the map, and get the values, which are list of original strings, grouped
        # together, and return the list
        map = defaultdict(list)  # we have to tell what the default type of values are
        for s in strs:
            # sorted(string) -> list of sorted characters, thus we use ''.join -> string that is sorted character wise
            # we can directly use append(s) because of defaultDict() if it is just dict() we would have to first check if the key exists if it is not, we have to initialize empty array first [] and then later append it.
            map["".join(sorted(s))].append(s)

        # map.values() gives view, not the list those are dictionary items
        # we have to convert them back to list.
        return list(map.values())
        # time: O(m * nlogn) - m for the length of the list, n for length of longest string in a list.
        # space: O(m * n) Each string’s sorted version (key) is length n → up to m unique keys → O(m × n).
        # Each original string (value) is stored once in the map → O(m × n) again.

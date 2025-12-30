class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # if length are not same then false
        # create two dict, update them for each char
        # if the 2 dict are same, return true

        if len(s) != len(t):
            return False

        s_dict, t_dict = {}, {}

        for i in range(len(s)):
            s_dict[s[i]] = (
                s_dict.get(s[i], 0) + 1
            )  # get s[i] if not there return 0 and add 1
            t_dict[t[i]] = t_dict.get(t[i], 0) + 1

        return s_dict == t_dict
        # time: O(n)
        # space: O(1) if we are only storing lowercase letters, O(n) if any other type of characters

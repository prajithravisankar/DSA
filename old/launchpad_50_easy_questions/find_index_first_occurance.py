class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        current_ans = []
        inside_for_loop = False
        for i in range(len(haystack)):
            if haystack[i] == needle[0]:
                temp_i = i
                for j in range(0, len(needle)):
                    inside_for_loop = True
                    if temp_i < len(haystack) and haystack[temp_i] == needle[j]:
                        temp_i += 1
                        current_ans.append(i)
                    else:
                        current_ans.clear()
                        break
                if inside_for_loop:
                    if len(current_ans) == 0:
                        continue
                    else:
                        return current_ans[0]

        if len(current_ans) == 0:
            return -1
        else:
            return current_ans[0]

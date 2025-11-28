class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # go through the list and create new pairs of num and its index and append it to
        # a master list, sort the master list, use pointers from the start and end of the
        # master list and compare if the first elment of start and first element of the end
        # is ==, <=, or > the target value, if our sum, > target, move end pointer to left
        # by one. if our sum <= move start pointer to right by one, if our sum == target,
        # return the indices.
        master = []
        for i, val in enumerate(nums):
            current = [val, i]
            master.append(current)

        master.sort()  # sorting is nlogn

        start = 0
        end = len(master) - 1
        while start < end:
            our_sum = master[start][0] + master[end][0]
            if our_sum == target:
                return [
                    min(master[start][1], master[end][1]),
                    max(master[start][1], master[end][1]),
                ]
            elif our_sum > target:
                end -= 1
            else:
                start += 1

        return []
        # time: O(nlogn) - due to sorting.
        # space: O(n) because we are creating a new master array

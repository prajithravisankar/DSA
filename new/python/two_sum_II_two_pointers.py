class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # idea: two pointers
        # track the left and right number
        # if the add up to target, return their index
        # if the sum is over the target, reduce the right pointer down by 1
        # if the sum is less than the target, increase the left pointer by 1
        # do this until left < right
        left = 0
        right = len(numbers) - 1
        while left < right:
            value = numbers[left] + numbers[right]
            if value == target:
                return [left + 1, right + 1]
            elif value < target:
                left += 1
            else:
                right -= 1
        return []
        # time: O(n)
        # space: O(1)

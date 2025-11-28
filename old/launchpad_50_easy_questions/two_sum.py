class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        current_items = []
        solution_items = []
        solution_items = self.explore(0, target, current_items, solution_items, nums)
        return solution_items

    def explore(self, start, target, current_items, solution_items, nums):
        if len(current_items) == 2:
            if nums[current_items[0]] + nums[current_items[1]] == target:
                solution_items = current_items[:]
                return solution_items
            return []

        for i in range(start, len(nums)):
            current_items.append(i)
            solution_items = self.explore(
                i + 1, target, current_items, solution_items, nums
            )
            current_items.pop()

            if solution_items:
                return solution_items

        return []

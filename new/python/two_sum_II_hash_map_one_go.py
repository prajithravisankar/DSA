class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # idea: using hashmap, one go
        # we are using hashmap of {current number: its' index, ...}
        # iterate through the given array
        # for every current number we are currently iterating through, check if the hashmap contains the complement,
        # if we have the complement, return the complement, and the current number.
        # if not add the current number and its index (i + 1) to the hashmap.
        seen = defaultdict(int)  # space: O(n)
        for i in range(len(numbers)):  # O(n)
            complement = target - numbers[i]
            if seen[complement]:  # O(1) hash look up O(1) on average
                return [seen[complement], i + 1]

            seen[numbers[i]] = i + 1
        return []
        # time: O(n)
        # space: O(n)

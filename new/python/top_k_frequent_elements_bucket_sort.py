class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # make a frequency map
        # create array of n + 1 buckets (empty arrays) to represent frequency. Each empty bucket represent
        # frequency. Why n + 1? the worst a number can be n times frequent n being size of given list.
        # iterate from back of the bucket (most frequent) to the front (least frequent), in each of the iteration
        # iterate through each bucket and add numbers from each bucket to result array until it reaches size k, if
        # it reaches size k return the result array
        freq = dict()
        buckets = [[] for i in range(len(nums) + 1)]

        for num in nums:
            freq[num] = 1 + freq.get(num, 0)
        for val, fq in freq.items():
            buckets[fq].append(val)

        result = []
        for i in range(len(buckets) - 1, 0, -1):  # iterate in reverse order
            for num in buckets[i]:
                result.append(num)
                if len(result) == k:
                    return result

        return result
        # time: O(n)
        # space: O(n)

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # create a frequency map
        # make a heap out of the frequency map only retaining the k frequent elements at a time
        #   - each iteration add a count, num to the heap
        #   - if the len(heap) > k, remove the least occuring element from the heap so we have
        #       k most frequent elements in the heap at a time
        # return the list of num from the remaining k elements in the heap as a list

        # make a frequency map
        frequency = dict()
        for num in nums:
            frequency[num] = 1 + frequency.get(num, 0)

        # make a heap out of the frequency map
        heap = []
        for num, freq in frequency.items():
            heapq.heappush(
                heap, (freq, num)
            )  # the heap push will be sorting heap based on freq, if two
            # things have same freq then based on num value.
            if (
                len(heap) > k
            ):  # if at any iteration the heap's length > k, then its time to throw out
                # the least occuring element out of the heap retaining k most occuring elems.
                heapq.heappop(heap)

        # from the remaining k elements in the heap, return the nums of the remaining k elements in the heap
        result = []
        for i in range(k):
            result.append(heapq.heappop(heap)[1])

        return result
        # time: O(nlogk): n for number of elements we have to iterate through in the given list and k
        # for length of the heap at a given time.
        # space: O(n + k)

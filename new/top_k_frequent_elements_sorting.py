class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # using sorting
        # create a frequency map: num: count
        # make a list out of the frequency map [[frequency, num], ...] and sort it.
        # get the last k items's 2nd item from the list, it will have our top k freq element
        map = {}
        for num in nums:
            map[num] = 1 + map.get(num, 0)

        arr = []
        for key, value in map.items():  # use map.items to get the key value pairs
            arr.append([value, key])
        arr.sort()

        result = []
        while len(result) < k:
            result.append(arr.pop()[1])

        return result

        # time: O(nlogn) for sorting
        # space: O(n)

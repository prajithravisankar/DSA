from typing import List


def mergeTwoHalves(nums: List[int], mid: int) -> List[int]:
    left = nums[:mid]
    right = nums[mid:]
    i = j = 0
    result = []

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    result.extend(left[i:])
    result.extend(right[j:])
    return result


def main():
    print(mergeTwoHalves([1, 3, 5, 2, 4, 6], 3))


main()

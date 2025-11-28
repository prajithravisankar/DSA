def count_cross_pairs_between_sorted_halves(nums: list[int], mid: int) -> int:
    right = mid
    #    pairs = []
    # the below looping not very efficient way to count
    #    for i in range(0, mid):
    #        while right < len(nums) and nums[i] > nums[right]:
    #            pairs.append((list[i], list[right]))
    #            right += 1
    #        right = mid
    count = 0
    for i in range(0, mid):
        while right < len(nums) and nums[i] > nums[right]:
            right += 1

        count += right - mid

    return count


def main():
    print(count_cross_pairs_between_sorted_halves([2, 4, 6, 1, 3, 5], 3))
    print(count_cross_pairs_between_sorted_halves([5, 6, 7, 1, 2, 3], 3))


main()

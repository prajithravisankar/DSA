def insert_into_sorted(nums: list[int], val: int) -> list[int]:
    nums.append(val)
    curr_index = len(nums) - 2
    while (curr_index >= 0 and nums[curr_index] > val):
        nums[curr_index + 1] = nums[curr_index]
        curr_index -= 1
    nums[curr_index + 1] = val
    return nums

def main():
    print(insert_into_sorted([1, 2, 3, 4, 6], 5))
    print(insert_into_sorted([0, 3, 5, 7, 9], 2))
    print(insert_into_sorted([0, 3, 5, 7, 9], 1))
    print(insert_into_sorted([1, 2, 3, 4, 6], 10))

main()

def kth_element_of_merged_halves(nums, mid, k):
    left_arr = nums[:mid]
    right_arr = nums[mid:]
    left_ptr = 0
    right_ptr = 0

    count = 0
    while left_ptr < len(left_arr) and right_ptr < len(right_arr):
        if left_arr[left_ptr] < right_arr[right_ptr]:
            val = left_arr[left_ptr]
            left_ptr += 1
        else:
            val = right_arr[right_ptr]
            right_ptr += 1

        if count == k:
            return val

        count += 1

    while left_ptr < len(left_arr):
        val = left_arr[left_ptr]
        if count == k:
            return val
        count += 1
        left_ptr += 1

    while right_ptr < len(right_arr):
        val = right_arr[right_ptr]
        if count == k:
            return val
        count += 1
        right_ptr += 1

    return None


def main():
    output = kth_element_of_merged_halves([1, 4, 7, 2, 3, 9], 3, 4)
    print(output)


main()

def shifts_so_far_insertion_sort(arr: list[int]) -> int:
    shifts_so_far = 0
    for i in range(1, len(arr)):
        prev_index = i - 1
        curr_val = arr[i]
        while (prev_index >= 0 and arr[prev_index] > curr_val):
            arr[prev_index + 1] = arr[prev_index]
            prev_index -= 1
            shifts_so_far += 1
        arr[prev_index + 1] = curr_val
    return shifts_so_far

def main():
    shifts = shifts_so_far_insertion_sort([3, 2, 1, 5, 4])
    print(shifts)

main()

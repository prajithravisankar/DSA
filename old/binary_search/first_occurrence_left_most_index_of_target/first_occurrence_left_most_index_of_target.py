import random


def binary_search_left_first_occurance(arr, val):
    left = 0
    right = len(arr) - 1
    lowest_index = -1

    while left <= right:
        middle = left + (right - left) // 2
        if arr[middle] < val:
            left = middle + 1
        elif arr[middle] > val:
            right = middle - 1
        else:
            lowest_index = middle
            right = middle - 1

    return lowest_index


def main():
    arr = [1, 2, 2, 3, 3, 3, 4, 5, 6, 7, 7, 8, 8, 8]
    val = random.randint(1, 10)
    index = binary_search_left_first_occurance(arr, val)
    print(arr)
    if index == -1:
        print("not found")
        return
    else:
        print(f"found {val} in index: {index}")


main()

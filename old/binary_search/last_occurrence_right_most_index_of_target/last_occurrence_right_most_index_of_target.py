import random


def binary_search_right_most_index(arr, val):
    left = 0
    right = len(arr) - 1
    right_most_index = -1

    while left <= right:
        middle = left + (right - left) // 2
        if arr[middle] < val:
            left = middle + 1
        elif arr[middle] > val:
            right = middle - 1
        else:
            right_most_index = middle
            left = middle + 1

    return right_most_index


def main():
    input = [1, 2, 3, 3, 3, 4, 5, 6, 6, 6, 7, 7, 8, 8, 8]
    print(input)
    findVal = random.randint(0, 10)
    index = binary_search_right_most_index(input, findVal)
    if index == -1:
        print(f"cannot find {findVal}")
    else:
        print(f"{findVal} is found in the index: {index}")


main()

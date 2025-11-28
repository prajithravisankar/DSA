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


def binary_search_left_most_index(arr, val):
    left = 0
    right = len(arr) - 1
    left_most_index = -1

    while left <= right:
        middle = left + (right - left) // 2
        if arr[middle] < val:
            left = middle + 1
        elif arr[middle] > val:
            right = middle - 1
        else:
            left_most_index = middle
            right = middle - 1

    return left_most_index


def main():
    input = [0, 1, 1, 1, 2, 3, 3, 3, 3, 4, 5, 5, 5, 5, 5, 5, 6, 7, 8, 8, 10]
    print(input)
    find_val = random.randint(0, 10)
    print(f"we are finding: {find_val}")
    left_index = binary_search_left_most_index(input, find_val)
    right_index = binary_search_right_most_index(input, find_val)
    if left_index != -1 and right_index != -1:
        print(f"[{left_index}, {right_index}]")
        return
    elif left_index != -1:
        print(f"[{left_index}, {left_index}]")
        return
    else:
        print(f"[{right_index}, {right_index}]")
        return


main()

import random


def binary_search(arr, val):
    low = 0
    high = len(arr) - 1

    while low <= high:
        middle = low + (high - low) // 2
        if arr[middle] < val:
            low = middle + 1
        elif arr[middle] > val:
            high = middle - 1
        else:
            return middle

    return low  # because after low <= high loop, low will be either in val or more than val


def main():
    arr = [1, 3, 5, 7, 9]
    val = random.randint(0, 10)
    found_or_insert_index = binary_search(arr, val)
    print(
        f"{val} can be found or inserted at index {found_or_insert_index} in the array: {arr}"
    )


main()

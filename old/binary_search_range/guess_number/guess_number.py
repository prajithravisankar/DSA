import random


def guess_number(guess, val):
    if guess == val:
        return 0
    elif guess > val:
        return 1
    else:
        return -1


def binary_search(arr, val):
    left = 0
    right = len(arr) - 1
    while left <= right:
        mid = left + (right - left) // 2
        if guess_number(arr[mid], val) == 1:
            right = mid - 1
        elif guess_number(arr[mid], val) == -1:
            left = mid + 1
        else:
            return mid

    return -1


def main():
    input = [1, 2, 3, 4, 5]
    val = random.randint(1, 5)
    print(input)
    index = binary_search(input, val)
    print(f"found {val} in index: {index}")


main()

def classic_binary_search(arr, val):
    left = 0
    right = len(arr) - 1

    while left <= right:
        middle = left + (right - left) // 2
        if arr[middle] < val:
            left = middle + 1
        elif arr[middle] > val:
            right = middle - 1
        else:
            return middle
    return -1


def main():
    sorted_arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    print(sorted_arr)
    find_val = 19
    output = classic_binary_search(sorted_arr, find_val)
    if output == -1:
        print("not found")
        return
    print(f"found {find_val} in index: {output}")


main()

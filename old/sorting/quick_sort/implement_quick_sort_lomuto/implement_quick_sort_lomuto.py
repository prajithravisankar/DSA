def quick_sort_lomuto(arr, start, end):
    if start >= end:
        return

    left = start
    pivot = arr[end]

    for i in range(start, end):
        if arr[i] < pivot:
            temp = arr[left]
            arr[left] = arr[i]
            arr[i] = temp
            left += 1

    arr[end] = arr[left]
    arr[left] = pivot

    quick_sort_lomuto(arr, start, left - 1)
    quick_sort_lomuto(arr, left + 1, end)


def main():
    input = [1, 3, 2, 5, 4, 7, 8, 6, 9, 10]
    print(input)
    quick_sort_lomuto(input, 0, 9)
    print(input)


main()

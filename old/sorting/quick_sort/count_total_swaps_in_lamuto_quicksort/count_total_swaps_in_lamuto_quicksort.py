def lamuto_partition(arr, start, end, count):
    left = start
    pivot = arr[end]

    for i in range(start, end):
        if arr[i] < pivot:
            arr[i], arr[left] = arr[left], arr[i]
            left += 1
            count += 1

    arr[end] = arr[left]
    arr[left] = pivot
    count += 1

    return arr, left, count


def lamuto_quick_sort(arr, start, end, count):
    if start >= end:
        return count
    else:
        arr, lamuto_partition_index, count = lamuto_partition(arr, start, end, count)
        count = lamuto_quick_sort(arr, start, lamuto_partition_index - 1, count)
        count = lamuto_quick_sort(arr, lamuto_partition_index + 1, end, count)
        return count


def main():
    input = [3, 2, 1, 4, 5, 6]
    print(input)
    swapCount = lamuto_quick_sort(input, 0, len(input) - 1, 0)
    print(input)
    print(swapCount)


main()

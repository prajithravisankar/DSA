def lomutu_partition(arr, start, end):
    left = start
    pivot = arr[end]

    for i in range(start, end):
        if arr[i] < pivot:
            arr[i], arr[left] = arr[left], arr[i]
            left += 1

    arr[end] = arr[left]
    arr[left] = pivot

    return arr, left


def lomuto_quick_select(arr, start, end, k):
    if start >= end:
        return arr[k]

    arr, partition_index = lomutu_partition(arr, start, end)

    if partition_index == k:
        return arr[partition_index]
    elif partition_index > k:
        return lomuto_quick_select(arr, start, partition_index - 1, k)
    else:
        return lomuto_quick_select(arr, partition_index + 1, end, k)

    return arr[k]


def main():
    input = [7, 10, 4, 3, 20, 15]
    nth_smallest_element_index = 4
    output = lomuto_quick_select(input, 0, len(input) - 1, nth_smallest_element_index)
    print(output)


main()

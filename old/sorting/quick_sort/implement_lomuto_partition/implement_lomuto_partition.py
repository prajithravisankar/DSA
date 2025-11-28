def lomuto_quick_sort_index(arr, start, end):
    left = start
    pivot = arr[end]

    for i in range(start, end):
        if arr[i] < pivot:
            arr[i], arr[left] = arr[left], arr[i]
            left += 1

    arr[end] = arr[left]
    arr[left] = pivot

    return left


def main():
    input = [3, 2, 1, 5, 4]
    output = lomuto_quick_sort_index(input, 0, 4)
    print(output)


main()

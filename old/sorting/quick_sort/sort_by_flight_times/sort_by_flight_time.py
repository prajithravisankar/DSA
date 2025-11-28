def lomuto_partition(arr, start, end):
    left = start
    pivot = arr[end]

    for i in range(start, end):
        if arr[i][2] < pivot[2]:
            arr[i], arr[left] = arr[left], arr[i]
            left += 1

    arr[end] = arr[left]
    arr[left] = pivot

    return arr, left


def lomuto_quick_sort(arr, start, end):
    if start >= end:
        return arr
    arr, partition_index = lomuto_partition(arr, start, end)
    arr = lomuto_quick_sort(arr, start, partition_index - 1)
    arr = lomuto_quick_sort(arr, partition_index + 1, end)
    return arr


def main():
    flights = [
        ("chennai", "trichy", 10),
        ("california", "seattle", 20),
        ("mumbai", "delhi", 5),
        ("london", "paris", 60),
        ("newyork", "boston", 45),
        ("dubai", "doha", 30),
        ("tokyo", "osaka", 25),
        ("berlin", "munich", 55),
        ("sydney", "melbourne", 70),
        ("singapore", "kuala lumpur", 35),
    ]

    print(flights)
    print("==== SORTING ====")
    flights = lomuto_quick_sort(flights, 0, len(flights) - 1)

    print(flights)


main()

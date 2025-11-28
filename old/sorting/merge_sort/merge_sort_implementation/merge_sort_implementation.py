def merge(sorted_left_array: list[int], sorted_right_array) -> list[int]:
    sorted_list = []
    left_index = 0
    right_index = 0

    # merge into the sorted_list until we get out of the loop from the sorted left or sorted right or both
    while left_index < len(sorted_left_array) and right_index < len(sorted_right_array):
        if sorted_left_array[left_index] < sorted_right_array[right_index]:
            sorted_list.append(sorted_left_array[left_index])
            left_index += 1
        else:
            sorted_list.append(sorted_right_array[right_index])
            right_index += 1

    # if we still have things left in the sorted left array
    while left_index < len(sorted_left_array):
        sorted_list.append(sorted_left_array[left_index])
        left_index += 1
    while right_index < len(sorted_right_array):
        sorted_list.append(sorted_right_array[right_index])
        right_index += 1

    return sorted_list


def merge_sort(numbers: list[int]) -> list[int]:
    # if the list contains only one number return the list it is already sorted
    if len(numbers) <= 1:
        return numbers

    # else find the middle index
    middle_index = len(numbers) // 2

    # sort the left array upto middle index and right array from middle index to end and merge the sorted left and right arrays
    sorted_left_array = merge_sort(numbers[:middle_index])
    sorted_right_array = merge_sort(numbers[middle_index:])
    return merge(sorted_left_array, sorted_right_array)


def main():
    sorted_list = merge_sort([1, 3, 5, 2, 4, 6])
    print(sorted_list)


main()

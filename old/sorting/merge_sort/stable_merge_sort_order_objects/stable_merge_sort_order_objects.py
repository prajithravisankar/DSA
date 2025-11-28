def merge(left_sorted_list_of_objects, right_sorted_list_of_objects):
    left_index = 0
    right_index = 0
    sorted = []

    while left_index < len(left_sorted_list_of_objects) and right_index < len(
        right_sorted_list_of_objects
    ):
        if (
            left_sorted_list_of_objects[left_index][0]
            <= right_sorted_list_of_objects[right_index][0]
        ):
            sorted.append(left_sorted_list_of_objects[left_index])
            left_index += 1
        else:
            sorted.append(right_sorted_list_of_objects[right_index])
            right_index += 1

    while left_index < len(left_sorted_list_of_objects):
        sorted.append(left_sorted_list_of_objects[left_index])
        left_index += 1

    while right_index < len(right_sorted_list_of_objects):
        sorted.append(right_sorted_list_of_objects[right_index])
        right_index += 1

    return sorted


def stable_merge_sort_order_objects(listOfObjects):
    if len(listOfObjects) <= 1:
        return listOfObjects
    else:
        mid = len(listOfObjects) // 2
        left_sorted_list_of_objects = stable_merge_sort_order_objects(
            listOfObjects[:mid]
        )
        right_sorted_list_of_objects = stable_merge_sort_order_objects(
            listOfObjects[mid:]
        )
        return merge(left_sorted_list_of_objects, right_sorted_list_of_objects)


def main():
    output = stable_merge_sort_order_objects([(2, 0), (1, 1), (2, 2), (1, 3)])
    print([j for i, j in output])


main()

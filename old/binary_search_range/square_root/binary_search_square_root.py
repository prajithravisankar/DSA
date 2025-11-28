import random


def binary_search(find_root_of):
    low = 0
    high = find_root_of
    valid_candidate = -1

    while low <= high:
        middle = low + (high - low) // 2
        if middle**2 < find_root_of:
            valid_candidate = middle
            low = middle + 1
        elif middle**2 > find_root_of:
            high = middle - 1
        else:
            valid_candidate = middle
            return valid_candidate

    return valid_candidate


def main():
    input = random.randint(1, 100)
    largest_root_floored = binary_search(input)
    print(
        f"found the floored largest root in the range of 1, {input}: {largest_root_floored}"
    )


main()

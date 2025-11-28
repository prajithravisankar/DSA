def is_valid(current_set, final_set):
    # should not contain duplicates in the current set
    # example: [1, 1] or [1, 2, 1]
    # and should not contain mirrors
    # example: current = [3, 1] and in the final_set = [[1, 2], [1, 3]]

    if len(current_set) != len(set(current_set)):
        return False

    current_set_set = set(current_set)
    for existing in final_set:
        if set(existing) == current_set_set:
            return False

    return True


def explore(start, n, current_set, final_set):
    if len(current_set) >= 0 and is_valid(current_set, final_set):
        final_set.append(current_set[:])

    if len(current_set) == n:
        return

    for val in range(start, n + 1):
        current_set.append(val)
        if is_valid(current_set, final_set):
            explore(val + 1, n, current_set, final_set)

        current_set.pop()


def k_combinations(n):
    start = 1
    current_set = []
    final_set = []
    explore(start, n, current_set, final_set)
    return final_set


def main():
    n = int(input("enter n to find sets of k combinations from 1 to n: "))
    print(k_combinations(n))


main()

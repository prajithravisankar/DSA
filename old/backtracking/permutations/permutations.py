def explore(n, current_set, final_set):
    if len(current_set) == n:
        final_set.append(current_set[:])
        return

    for val in range(1, n + 1):
        if val in current_set:
            continue
        current_set.append(val)
        explore(n, current_set, final_set)
        current_set.pop()


def permutations(n):
    current_set = []
    final_set = []
    explore(n, current_set, final_set)
    return final_set


def main():
    n = int(input("enter number of permutations for n numbers from 1: "))
    print(permutations(n))


main()

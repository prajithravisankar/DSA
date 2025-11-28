def combine(n, k):
    result = []
    current = []
    result = backtrack(1, n, k, current, result)
    return result


def backtrack(start, n, k, current, result):
    if len(current) == k:
        result.append(current[:])
        return result

    for i in range(start, n + 1):
        current.append(i)
        result = backtrack(i + 1, n, k, current, result)
        current.pop()

    return result


def main():
    result = combine(5, 3)
    print(result)


main()

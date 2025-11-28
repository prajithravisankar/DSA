def is_valid(current_binary_digits):
    for i in range(1, len(current_binary_digits)):
        if current_binary_digits[i - 1] == 1 and current_binary_digits[i] == 1:
            return False

    return True


def explore(
    n, current_binary_digits, final_list_of_binary_digits_without_consecutive_ones
):
    if len(current_binary_digits) == n and is_valid(current_binary_digits):
        final_list_of_binary_digits_without_consecutive_ones.append(
            current_binary_digits[:]
        )
        return

    # explore 0
    current_item = 0
    current_binary_digits.append(current_item)
    explore(
        n, current_binary_digits, final_list_of_binary_digits_without_consecutive_ones
    )
    current_binary_digits.pop()

    # explore 1
    current_item = 1
    current_binary_digits.append(current_item)
    if is_valid(current_binary_digits):
        explore(
            n,
            current_binary_digits,
            final_list_of_binary_digits_without_consecutive_ones,
        )
    current_binary_digits.pop()


def generate_binary_strings_without_consecutive_1s(n):
    current_binary_digits = []
    final_list_of_binary_digits_without_consecutive_ones = []
    explore(
        n, current_binary_digits, final_list_of_binary_digits_without_consecutive_ones
    )
    return final_list_of_binary_digits_without_consecutive_ones


def main():
    n = int(
        input(
            "enter n so we can find a combination of n numbers, without consecutive 1s: "
        )
    )
    ans = generate_binary_strings_without_consecutive_1s(n)
    print(["".join(map(str, each_list)) for each_list in ans])


main()

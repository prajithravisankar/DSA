def convert_to_bits_in_list(x, y):
    remaining_x = x
    remaining_y = y
    bit_x = []
    bit_y = []
    while remaining_x > 0:
        reminder_x = remaining_x % 2
        bit_x.append(reminder_x)
        remaining_x = remaining_x // 2

    while remaining_y > 0:
        reminder_y = remaining_y % 2
        bit_y.append(reminder_y)
        remaining_y = remaining_y // 2

    max_len = max(len(bit_x), len(bit_y))

    while len(bit_x) < max_len:
        bit_x.append(0)

    while len(bit_y) < max_len:
        bit_y.append(0)

    bit_x.reverse()
    bit_y.reverse()

    return bit_x, bit_y


def hammingDistance(x, y):
    bit_x, bit_y = convert_to_bits_in_list(x, y)
    count = 0
    for i, j in zip(bit_x, bit_y):
        if i != j:
            count += 1

    return count


def main():
    print(hammingDistance(1, 4))  # Expected 2
    print(hammingDistance(3, 1))  # Expected 1
    print(hammingDistance(2, 1))  # Expected 2


main()

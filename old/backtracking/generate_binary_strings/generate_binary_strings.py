def generate_binary_string(n):
    final_result = []
    current_level = []

    def backtrack(current_level, explore=None):
        # if current level is part of solution
        if len(current_level) == n:
            print(
                f"since {current_level} has reached size {n}, going to add it to {final_result}"
            )
            final_result.append("".join(str(bit) for bit in current_level))
            print(
                f"after adding it to final result, final result looks like this: {final_result}"
            )
            print("\n")
            return

        # explore
        explore = 0
        print(f"exploring: {explore}")
        current_level.append(explore)
        print(f"current_level: {current_level}")
        print(f"going to backtrack: backtrack({current_level}, {explore})")
        backtrack(current_level, explore)
        print(
            f"from {current_level} we are going to pop the last value which is {current_level.pop()}"
        )
        print(f"now our current level looks like this: {current_level}")
        print("\n")

        # explore
        explore = 1
        print(f"exploring: {explore}")
        current_level.append(explore)
        print(f"current_level: {current_level}")
        print(f"going to backtrack: backtrack({current_level}, {explore})")
        backtrack(current_level, explore)
        print(
            f"from {current_level} we are going to pop the last value which is {current_level.pop()}"
        )
        print(f"now our current level looks like this: {current_level}")
        print("\n")

    print(f"current_level: {current_level}")
    print(f"going to backtrack: backtrack({current_level}, None)")
    backtrack(current_level)

    return final_result


def main():
    n = int(input("enter n to generate all combinations of bits of size n: "))
    print(generate_binary_string(n))


main()

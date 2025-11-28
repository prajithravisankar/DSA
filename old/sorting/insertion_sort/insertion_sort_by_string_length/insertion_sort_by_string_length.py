def insertion_sort_by_string_length(words: list[int]) -> list[int]:
    for i in range(1, len(words)):
        curr_word  = words[i]
        prev_word_index = i - 1
        while (prev_word_index >= 0 and len(words[prev_word_index]) > len(curr_word)):
            words[prev_word_index + 1] = words[prev_word_index]
            prev_word_index -= 1
        words[prev_word_index + 1] = curr_word
    return words
            
def main():
    print(insertion_sort_by_string_length(["code","a","be","go"]))

main()

class Solution {
public:
    bool isValid(string s) {
        // idea: loop through the string and see if you find {}, or (), or []. If we find this pair, 
        // remove it from the string. Do this until all the pairs of the above types are gone. 
        // if the resulting string is empty, return true, else return false. 
        while (true) {
            size_t position = string::npos; // size_t is unsigned integer. 
            // npos means 'no position' or cannot find or largest index (used to compare with the string.find()) method
            position = s.find("()");
            if (position != string::npos) {
                s.erase(position, 2);
                continue;
            }

            position = s.find("[]");
            if (position != string::npos) {
                s.erase(position, 2);
                continue;
            }

            position = s.find("{}");
            if (position != string::npos) {
                s.erase(position, 2);
                continue;
            }

            break;
        }

        return s.empty();
    }
    // Time Complexity: O(n^2)
    // In each iteration, s.find() takes O(n) time. 
    // s.erase() also takes O(n) because characters after the erased part must be shifted.
    // The while loop may run up to O(n) times (removing one pair at a time).
    // So total time = O(n) * O(n) = O(n^2).

    // Space Complexity: O(n)
    // The string 's' itself takes O(n) space. 
    // erase() modifies the string in-place and does not allocate a new string.
    // No extra data structures are used, so total space is O(n).
    // If we don’t create a new string, shouldn’t space be O(1)? =>>>>> Space complexity always includes the space needed to store the input if it is 
    // modified. Even if you modify the string in place, the string itself takes O(n) space.
};

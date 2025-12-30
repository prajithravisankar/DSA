class Solution {
public:
    bool isPalindrome(string s) {
        /*
        # method 1: reverse the given string stripping away all the non alnum chars
        # checkking if the reversed string is the same as the original string w/o
        # all the alnum chars. time: O(n) and space: O(n) because we are storing 
        # extra string (reversed string). 

        # method 2: using two pointers
        # if the current left pointer and right pointer points to same char
        # do this while left and right don't meet. if not alnum, skip it. 
        */ 

        // method 1: reverse string
        // string reverse = "";
        // for (char c: s) {
        //     if (isalnum(c)) {
        //         reverse += tolower(c);
        //     }
        // }

        // return reverse == string(reverse.rbegin(), reverse.rend());
        // time: O(n), space: O(n)

        // method 2: using two pointers
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            while (left < right && !isAlphaNumeric(s[left])) {
                left++;
            } 

            while (right > left && !isAlphaNumeric(s[right])) {
                right--;
            }

            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;

    }
    // time: O(n)
    // space: O(1)


    bool isAlphaNumeric(char c) {
        return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c && c <= '9'));
    }
};

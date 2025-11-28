#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int guessNumber(int guess, int val) {
    if (guess == val) {
        return 0;
    } else if (guess > val) {
        return 1;
    } else {
        return -1;
    }
    
    return 0;
}

int binarySearch(vector<int>& arr, int val) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (guessNumber(arr[mid], val) == 1) {
            right = mid - 1;
        } else if (guessNumber(arr[mid], val) == -1) {
            left = mid + 1; 
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {
    srand(time(0));
    vector<int> input = {1, 2, 3, 4, 5};
    for (int val: input) {
        cout << val << " ";
    }
    int val = (rand() % 5) + 1;
    int index = binarySearch(input, val);
    cout << "found " << val << " at index: " << index << endl; 
    return 0;
}

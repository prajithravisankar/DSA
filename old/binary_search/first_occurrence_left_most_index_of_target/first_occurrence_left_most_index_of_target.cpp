#include <iostream>
#include <vector>

using namespace std;

int binarySearchFirstOccurrence(vector<int>& arr, int val) {
    int left = 0;
    int right = arr.size() - 1;
    int currIndex = -1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (arr[middle] < val) {
            left = middle + 1;
        } else if (arr[middle] > val) {
            right = middle - 1;
        } else {
            currIndex = middle;
            right = middle - 1;
        }

    }
    return currIndex;
}

int main() {
    vector<int> sortedArr = {1, 2, 2, 3, 3, 3, 4, 5, 6, 7, 8, 8, 8, 8, 9};
    for (int val: sortedArr) {
        cout << val << " ";
    }
    cout << endl;
    int findVal = 100;
    int index = binarySearchFirstOccurrence(sortedArr, findVal);
    if (index == -1) {
        cout << "not found" << endl;
        return 0;
    }

    cout << "first index that we found the val: " << findVal << " is in index: " << index << endl;
    return 0;
}

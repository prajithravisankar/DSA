#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int binarySearchRightMostOccurrence(vector<int>& arr, int val) {
    int left = 0;
    int right = arr.size() - 1;
    int rightMostIndex = -1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (arr[middle] < val) {
            left = middle + 1;
        } else if (arr[middle] > val) {
            right = middle - 1;
        } else {
            rightMostIndex = middle;
            left = middle + 1;
        }
    }

    return rightMostIndex;
}

int main() {
    srand(time(0));

    vector<int> sortedArr = {1, 1, 1, 2, 3, 4, 5, 5, 5, 6, 7, 8, 8, 8, 9};
    for (int val: sortedArr) {
        cout << val << " ";
    }
    cout << endl;
    int findVal = (rand() % 10) + 1;
    int index = binarySearchRightMostOccurrence(sortedArr, findVal);
    if (index == -1) {
        cout << "val: " << findVal << endl;
        cout << "not found" << endl;
        return 0;
    }

    cout << "val: " << findVal << " is found in index: " << index << endl;
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int kth_element_of_merged_halves(vector<int> arr, int mid, int k) {
    vector<int> leftArr(arr.begin(), arr.begin() + mid);
    vector<int> rightArr(arr.begin() + mid, arr.end());
    vector<int> sortedArr;
    int leftPtr = 0;
    int rightPtr = 0;

    while (leftPtr < leftArr.size() && rightPtr < rightArr.size()) {

        if (leftArr[leftPtr] < rightArr[rightPtr]) {
            sortedArr.push_back(leftArr[leftPtr]);
            leftPtr += 1;
        } else {
            sortedArr.push_back(rightArr[rightPtr]);
            rightPtr += 1;
        }
    }


    while (leftPtr < leftArr.size()) {
        sortedArr.push_back(leftArr[leftPtr]);
        leftPtr += 1;
    }


    while (rightPtr < rightArr.size()) {
        sortedArr.push_back(rightArr[rightPtr]);
        rightPtr += 1;
    }

    for (int i = 0; i < sortedArr.size(); i++) {
        if (i == k - 1) {
            return sortedArr[i];
        } 
    }

    return -1;
}

int main() {
    cout << kth_element_of_merged_halves({1, 3, 4, 2, 5, 6}, 3, 4);
    return 0;
}

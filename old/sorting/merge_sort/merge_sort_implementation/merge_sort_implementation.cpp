#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int>& sortedLeftArr, vector<int>& sortedRightArr) {
    vector<int> outputArr;
    int leftIndex = 0;
    int rightIndex = 0;

    while (leftIndex < sortedLeftArr.size() && rightIndex < sortedRightArr.size()) {
       if (sortedLeftArr[leftIndex] < sortedRightArr[rightIndex]) {
            outputArr.push_back(sortedLeftArr[leftIndex]);
            leftIndex += 1;
        } else {
            outputArr.push_back(sortedRightArr[rightIndex]);
            rightIndex += 1;
        } 
    }

    while (leftIndex < sortedLeftArr.size()) {
        outputArr.push_back(sortedLeftArr[leftIndex]);
        leftIndex += 1;    
    }


    while (rightIndex < sortedRightArr.size()) {
        outputArr.push_back(sortedRightArr[rightIndex]);
        rightIndex += 1;    
    }

    return outputArr;
}

vector<int> mergeSort(vector<int>& arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    int middleIndex = (arr.size() / 2);

    vector<int> leftArr(arr.begin(), arr.begin() + middleIndex);
    vector<int> rightArr(arr.begin() + middleIndex, arr.end());

    vector<int> sortedLeftArr = mergeSort(leftArr);
    vector<int> sortedRightArr = mergeSort(rightArr);
    return merge(sortedLeftArr, sortedRightArr);
}

int main() {
    vector<int> numbers = {5, 3, 8, 4, 2, 7, 1, 6};
    vector<int> sortedNumbers = mergeSort(numbers);

    cout << "Sorted: ";
    for (int num : sortedNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

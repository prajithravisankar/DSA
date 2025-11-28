#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>


using namespace std;

int binarySearchLeftMostIndex(vector<int>& arr, int val) {
    int left = 0;
    int right = arr.size() - 1;
    int leftMostIndex = -1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (arr[middle] < val) {
            left = middle + 1;
        } else if (arr[middle] > val) {
            right = middle - 1;
        } else {
            leftMostIndex = middle;
            right = middle - 1;
        } 
    }


    return leftMostIndex;
}

int binarySearchRightMostIndex(vector<int>& arr, int val) {
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

    vector<int> input = {0, 0, 0, 1, 1, 2, 3, 4, 4, 4, 5, 5, 5, 5, 5, 6, 7, 8, 10};
    for (int val: input) {
        cout << val << " ";
    }
    cout << endl;

    int findVal = rand() % 11; // from 0 to 11
    
    cout << "we are looking for: " << findVal << endl;


    int leftIndex = binarySearchLeftMostIndex(input, findVal);
    int rightIndex = binarySearchRightMostIndex(input, findVal);

    if (leftIndex == -1) {
        cout << "[-1, ";
    } else {
        cout << "[" << leftIndex << ", ";
    } 

         
    if (rightIndex == -1) {
        cout << "-1]"; 
    } else {
        cout << rightIndex << "]";
    }

    return 0;
}

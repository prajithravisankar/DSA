#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int binarySearchInsertionPosition(vector<int>& arr, int val) {
    int low = 0;
    int high = arr.size() - 1;
    
    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (arr[middle] < val) {
            low = middle + 1;
        } else if (arr[middle] > val) {
            high = middle - 1;
        } else {
            return middle;
        }
    }

    return low;
}

int main() {
    vector<int> input = {0, 2, 4, 6, 8, 10};
    for (int i: input) {
        cout << i << " ";
    }
    cout << endl;
    srand(time(0));
    int val = (rand() % 10) + 1;
    int insertOrFoundIndex = binarySearchInsertionPosition(input, val);
    cout << val << " can be found or inserted at index: " << insertOrFoundIndex << endl;
    return 0;
}

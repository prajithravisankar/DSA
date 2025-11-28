#include <iostream>
#include <vector>


using namespace std;

int countShiftsInsertionSort(vector<int>& arr) {
    int shiftSoFar = 0;
    for (int i = 1; i < arr.size(); i++) {
        int prevIndex = i - 1;
        int currVal = arr[i];
        while (prevIndex >= 0 && arr[prevIndex] > currVal) {
            arr[prevIndex + 1] = arr[prevIndex];
            prevIndex -= 1;
            shiftSoFar++;
        }
        arr[prevIndex + 1] = currVal;
    }
    return shiftSoFar;
}

int main() {
    vector<int> v = {3, 2, 1, 4, 5};   
    int shifts =  countShiftsInsertionSort(v);
    cout << shifts;
}

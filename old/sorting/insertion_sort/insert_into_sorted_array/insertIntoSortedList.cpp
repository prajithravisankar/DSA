#include<iostream>
#include<vector>
using namespace std;


// Helper function to print a vector
void printVector(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " "; 
    }
}


void insertIntoSortedArray(vector<int>& arr, int val) {
    arr.push_back(val);
    int currIndex = arr.size() - 2;
    while (currIndex >= 0 && arr[currIndex] > val) {
        arr[currIndex + 1] = arr[currIndex];
        currIndex -= 1;
    }
    arr[currIndex + 1] = val;
}


int main() {
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {0, 2, 4, 5};
    vector<int> v3 = {0, 2, 4, 5};
    printVector(v1);
    cout << endl;
    printVector(v2);
    cout << endl;
    printVector(v3);
    cout << endl;
    cout << "inserting" << endl;
    insertIntoSortedArray(v1, 1);
    insertIntoSortedArray(v2, 3);
    insertIntoSortedArray(v3, 1);
    printVector(v1);
    cout << endl;
    printVector(v2);
    cout << endl;
    printVector(v3);
    cout << endl;
    return 0;
}

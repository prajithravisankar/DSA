#include <iostream>
#include <vector>
using namespace std;

int countCrossPairsBetweenSortedHalves(vector<int> arr, int mid) {
    int right = mid;
    int count = 0;
    
    for (int i = 0; i < mid; i++) {
        while (right < arr.size() && arr[i] > arr[right]) {
            right += 1;
        }
        count += (right - mid);
    }

    return count;
}

int main() {
    vector<int> v = {3, 4, 5, 1, 2};
    int mid = 3; 
    int count = countCrossPairsBetweenSortedHalves(v, mid);
    cout << count << endl;
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> left, vector<vector<int>> right) {
    int leftPtr = 0;
    int rightPtr = 0;
    vector<vector<int>> sorted;

    while (leftPtr < left.size() && rightPtr < right.size()) {
        if (left[leftPtr][0] <= right[rightPtr][0]) {
            sorted.push_back(left[leftPtr]);
            leftPtr += 1;
        } else {
            sorted.push_back(right[rightPtr]);
            rightPtr += 1;
        }
    }


    while (leftPtr < left.size()) {
        sorted.push_back(left[leftPtr]);
        leftPtr += 1;
    }

    while (rightPtr < right.size()) {
        sorted.push_back(right[rightPtr]);
        rightPtr += 1;
    }
    
    return sorted;

}

vector<vector<int>> stableMergeSortListObject(vector<vector<int>> objects) {
    if (objects.size() <= 1) {
        return objects; 
    } else {
        int midIndex = objects.size() / 2;
        vector<vector<int>> leftObjects(objects.begin(), objects.begin() + midIndex);
        vector<vector<int>> rightObjects(objects.begin() + midIndex, objects.end());
        vector<vector<int>> leftSorted = stableMergeSortListObject(leftObjects);
        vector<vector<int>> rightSorted = stableMergeSortListObject(rightObjects);
        return merge(leftSorted, rightSorted); 
    } 
}

int main() {
    vector<vector<int>> items = {
        {5, 0},
        {3, 1},
        {5, 2},
        {-1, 3},
        {3, 4},
        {10, 5},
        {5, 6},
        {-1, 7}
    };

    vector<vector<int>> result = stableMergeSortListObject(items);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i][1] << " ";
    }
    return 0; 
}

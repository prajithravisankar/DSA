#include <iostream>
#include <vector>

using namespace std;

vector<int> merge_two_sorted_halves(const vector<int>& v, int middleIndex) {
    int left = 0;
    int right = middleIndex;
    vector<int> output;

    while (left < middleIndex && right < v.size()) {
        if (v[left] < v[right]) {
            output.push_back(v[left]);
            left++;
        } else {
            output.push_back(v[right]);
            right++;
        }
    }

    while (left < middleIndex) {
        output.push_back(v[left]);
        left++;
    }
    
    while (right < v.size()) {
        output.push_back(v[right]);
        right++;
    }

    return output; 
}

int main() {
    vector<int> v = {1, 4, 7, 2, 3, 5, 6};
    v = merge_two_sorted_halves(v, v.size() / 2);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}

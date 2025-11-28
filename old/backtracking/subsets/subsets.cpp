#include <iostream>
#include <vector>

using namespace std;

// Recursive function: for each number 1..n, decide to include or exclude it
void explore(int i, int n, vector<int>& currentSet, vector<vector<int>>& finalSet) {
    if (i > n) {
        finalSet.push_back(currentSet);
        return;
    }


    // explore the rejection branch
    explore(i + 1, n, currentSet, finalSet);

    // after exploring the rejection branch explore the acceptance branch
    currentSet.push_back(i);
    explore(i + 1, n, currentSet, finalSet);
    currentSet.pop_back();
}

vector<vector<int>> calculateSubset(int n) {
    vector<vector<int>> finalSet;
    vector<int> currentSet;
    explore(1, n, currentSet, finalSet);
    return finalSet;
}

int main() {
    int n;
    cout << "Enter n to find all subsets from 1 to n: ";
    cin >> n;

    vector<vector<int>> subset = calculateSubset(n);

    for (const auto& set : subset) {
        cout << "[";
        for (size_t i = 0; i < set.size(); ++i) {
            cout << set[i];
            if (i + 1 != set.size()) {
                cout << ", ";
            }
        }
        cout << "]\n";
    }

    return 0;
}


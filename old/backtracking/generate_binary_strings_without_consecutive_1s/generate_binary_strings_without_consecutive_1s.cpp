#include <iostream>
#include <vector>
#include <string>

using namespace std;

void explore(int n, vector<int>& current, vector<vector<int>>& final) {
    if (current.size() == n) {
        final.push_back(current);
        return;
    }

    int val = 0;
    current.push_back(val);
    explore(n, current, final);
    current.pop_back();

    val = 1;
    if (current.empty() || current.back() != 1) {
        current.push_back(val);
        explore(n, current, final);
        current.pop_back();
    }
}

vector<vector<int>> binaryStringWithNoConsecutiveOnes(int n) {
    vector<int> current;
    vector<vector<int>> final;
    explore(n, current, final);
    return final;
}

int main() {
    cout << "enter n such that binary string of size n of all combinations will be found: ";
    int n;
    cin >> n;
    vector<vector<int>> ans = binaryStringWithNoConsecutiveOnes(n);
    for (const auto& binary : ans) {
        for (int bit : binary) {
            cout << bit;
        }
        cout << endl;
    }
    return 0;
}

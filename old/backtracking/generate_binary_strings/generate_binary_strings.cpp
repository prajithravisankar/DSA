#include <iostream>
#include <vector>
#include <string>

using namespace std;

void backtrack(vector<vector<int>>& result, vector<int>& currentLevel, int n,  int explore) {
    // if our current level is part of solution, add it it our final result 
    if (currentLevel.size() == n) {
        result.push_back(currentLevel);
        return;
    }

    // explore
    explore = 0;
    currentLevel.push_back(explore);
    backtrack(result, currentLevel, n, explore);
    currentLevel.pop_back();

    explore = 1;
    currentLevel.push_back(explore);
    backtrack(result, currentLevel, n, explore);
    currentLevel.pop_back();
}


vector<vector<int>> binaryCombinations(int n) {
    vector<vector<int>> result;
    vector<int> currentLevel;
    
    backtrack(result, currentLevel, n, -1);

    return result;
}

int main() {
    int n;
    cout << "enter n to get all the combinations of n binary digits: ";
    cin >> n;
    vector<vector<int>> result = binaryCombinations(n);
    for (auto& combination : result) {
        for (int bit : combination) {
            cout << bit;
        }
        cout << " ";
    }
    return 0;
}

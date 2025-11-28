#include <iostream>
#include <vector>

using namespace std;

class Solution {

public: 
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(1, n, k, current, result);
        return result;
    }

private:
    void backtrack(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= n; i++) {
            current.push_back(i);
            backtrack(i + 1, n, k, current, result);
            current.pop_back();
        }
    }

};

int main() {
    Solution s;
    auto res = s.combine(5, 3);
    for (auto &comb : res) {
        cout << "[";
        for (size_t i = 0; i < comb.size(); ++i) {
            cout << comb[i] << (i+1<comb.size()? ",":"");
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

void print2DVector(const vector<vector<int>>& vec) {
    for (const auto& inner : vec) {
        cout << "[";
        for (size_t i = 0; i < inner.size(); ++i) {
            cout << inner[i];
            if (i + 1 != inner.size()) cout << ", ";
        }
        cout << "]\n";
    }
    cout << endl;
}

void print1DVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i + 1 != vec.size()) cout << ", ";
    }
    cout << "]\n";
}

void printBoolVector(const vector<bool>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << (vec[i] ? "true" : "false");
        if (i + 1 != vec.size()) cout << ", ";
    }
    cout << "]\n";
}

void explore(int n, vector<vector<int>>& finalSet, vector<int>& currentSet, vector<bool>& val_in_vector) {
    if (currentSet.size() == n) {
        finalSet.push_back(currentSet);
        cout << "✅ Final set after pushing current set:\n";
        print2DVector(finalSet);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (val_in_vector[i]) continue;

        cout << "➡️ Pushing i = " << i << " into currentSet\n";
        currentSet.push_back(i);
        cout << "   currentSet: ";
        print1DVector(currentSet);

        val_in_vector[i] = true;

        cout << "   Exploring with:\n";
        cout << "   finalSet:\n";
        print2DVector(finalSet);
        cout << "   currentSet: ";
        print1DVector(currentSet);
        cout << "   val_in_vector: ";
        printBoolVector(val_in_vector);
        cout << endl;

        explore(n, finalSet, currentSet, val_in_vector);

        cout << "🔄 Backtracking, popping from currentSet: ";
        print1DVector(currentSet);

        currentSet.pop_back();
        val_in_vector[i] = false;
    }
}

vector<vector<int>> allPermutations(int n) {
    vector<bool> val_in_vector(n + 1, false); // index 0 unused
    vector<vector<int>> finalSet;
    vector<int> currentSet;
    explore(n, finalSet, currentSet, val_in_vector);
    return finalSet;
}

int main() {
    int n;
    cout << "Enter n for which we will calculate all permutations of 1 to n: ";
    cin >> n;

    vector<vector<int>> permutations = allPermutations(n);

    cout << "\n✅ All permutations:\n";
    for (const auto& set : permutations) {
        cout << "[";
        for (size_t i = 0; i < set.size(); ++i) {
            cout << set[i];
            if (i + 1 != set.size()) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}


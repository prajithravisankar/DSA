#include <iostream>
#include <vector>
#include <string>

using namespace std;


void insertionSortByStringLength(vector<string>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        string currWord = arr[i];
        int prevWordIndex = i - 1;
        while (prevWordIndex >= 0 && arr[prevWordIndex].size() > currWord.size()) {
            arr[prevWordIndex + 1] = arr[prevWordIndex];
            prevWordIndex -= 1;
        }
        arr[prevWordIndex + 1] = currWord;
    }
}


int main() {
    vector<string> v = {"atodon", "beeeeeeeee", "todo", "coding"};
    insertionSortByStringLength(v);
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}

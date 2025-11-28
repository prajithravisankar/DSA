#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int isSquareLowOrHigh(int candidate, int findSquareRootOf) {

    if (candidate * candidate < findSquareRootOf) {
        return 1;
    } else if (candidate * candidate > findSquareRootOf) {
        return -1;
    } else {
        return 0;
    }

    return -1;
} 

int binarySearch(int findSquareRootOf) {
    if (findSquareRootOf == 0) return 0;
    int low = 1;
    int high = findSquareRootOf;
    int validCandidate = -1;

    while (low <= high) {
        int middle = low + (high - low) / 2;
        int lowOrHigh = isSquareLowOrHigh(middle, findSquareRootOf);
        if (lowOrHigh == 1) {
            // low
            validCandidate = middle;
            low = middle + 1;
        } else if (lowOrHigh == -1) {
            // high
            high = middle - 1;
        } else {
            // same
            validCandidate = middle;
            return validCandidate;
        }
    }


    return validCandidate;
}

int main() {
    srand(time(0));
    int findSquareRootOf = (rand() % 100) + 1;
    int largestSquareRootInRange = binarySearch(findSquareRootOf);
    cout << "found square floored root of " << findSquareRootOf << " in th range of 1 to " << findSquareRootOf << ": " << largestSquareRootInRange;
    cout << endl;
    findSquareRootOf = 100;
    largestSquareRootInRange = binarySearch(findSquareRootOf);
    cout << "found square floored root of " << findSquareRootOf << " in th range of 1 to " << findSquareRootOf << ": " << largestSquareRootInRange;
    return 0;
}

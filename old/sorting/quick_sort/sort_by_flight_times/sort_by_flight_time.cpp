#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Flight {
    string origin;
    string destination;
    int time;
};

int lomutoPartition(vector<Flight>& flights, int start, int end) {
    int left = start;
    Flight pivot = flights[end];

    for (int i = start; i < end; i++) {
        if (flights[i].time < pivot.time) {
            swap(flights[left], flights[i]);
            left += 1;
        } 
    }

    flights[end] = flights[left];
    flights[left] = pivot;
    
    return left;
}

void lomutoQuickSort(vector<Flight>& flights, int start, int end) {
    if (start >= end) {
        return;
    }

    int partitionIndex = lomutoPartition(flights, start, end);
    lomutoQuickSort(flights, start, partitionIndex - 1);
    lomutoQuickSort(flights, partitionIndex + 1, end);
}


int main() {

    vector<Flight> flights = {
        {"chennai","trichy",10},
        {"california","seattle",20},
        {"mumbai","delhi",5},
        {"london","paris",60},
        {"newyork","boston",45},
        {"dubai","doha",30},
        {"tokyo","osaka",25},
        {"berlin","munich",55},
        {"sydney","melbourne",70},
        {"singapore","kuala lumpur",35}
    };

    cout << "before sorting: " << endl;
    for (int i = 0; i < flights.size(); i++) {
        cout << flights[i].origin << " -> " 
         << flights[i].destination << " (" 
         << flights[i].time << ")" << endl;
    }

    cout << "===================== SORTING ======================" << endl; 

    lomutoQuickSort(flights, 0, flights.size() - 1);
    
    cout << "after sorting: " << endl;
    for (int i = 0; i < flights.size(); i++) {
        cout << flights[i].origin << " -> " 
             << flights[i].destination << " (" 
             << flights[i].time << ")" << endl;
    }
    
    return 0;
}

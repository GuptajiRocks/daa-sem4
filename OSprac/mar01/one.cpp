#include <bits/stdc++.h>
using namespace std;

struct Process {
    int PID, at, bt;
    int ct = 0;
    int tat = 0;
    int wt = 0;

    void setTat() {
        tat = ct - at;
    }

    void setWt() {
        wt = tat - bt;
    }
};


int main() {
    int n = 5;
    Process arr[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter PID: "; cin >> arr[i].PID;
        cout << "Enter Arrival Time: "; cin >> arr[i].at;
        cout << "Enter Burst Time: "; cin >> arr[i].bt;
    }

    int gtt = 0;
    int c = 0;

    while (c < n) {
        gtt = gtt + arr[c].bt;
        arr[c].ct = gtt;
        c++;
    }

    for (int i = 0; i < n; i++) {
        arr[i].setTat();
        arr[i].setWt();
    }

    cout << "PID     AT     BT     CT     TAT     WT" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i].PID << "     " << arr[i].at << "     " << arr[i].bt << "     " << arr[i].ct << "     " << arr[i].tat;
        cout << "     " << arr[i].wt << endl;
    }    

    return 0;
}
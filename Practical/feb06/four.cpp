#include <bits/stdc++.h>
using namespace std;

void printA(vector<int> lol) {
    for (int num : lol) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {65,70,75,80,85,60,55};
    int n = arr.size();
    int p = -1;

    
    
    // // finding pivot element
    // for (int i = 0; i < n; i++) {
    //     if (arr[i+1] > arr[i]) {
    //         continue;
    //     } else {
    //         p = i;
    //         break;
    //     }
    // }

    // swap(arr[p], arr[n-1]);

    // cout << p << endl;
    // printA(arr);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void printA(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10,15,1,2,9,16,11};
    int n = 7;
    int i = 0;
    int j = n-2;
    int p = arr[n-1];

    // while (i < j) {
    //     if (arr[i] > p) {
            
    //     }
    // }
    printA(arr, n);
}
// recursive bubble sort

#include <bits/stdc++.h>
using namespace std;
void printA(int l[], int n) {
    for (int i = 0; i < n; i++) {
        cout << l[i] << " ";
    }
    cout << endl;
}

void bubsort(int arr[], int n) {
    if (n <= 1) {
        return;
    }

    for (int j = 0; j < n-1; j++) {
        if (arr[j] > arr[j+1]) {
            swap(arr[j], arr[j+1]);
        }
        printA(arr, 5);
    }
    bubsort(arr, n-1);
}

int main() {
    int arr[] = {12,100,3,0,65};
    int n = 5;

    bubsort(arr, n);

    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    
    return 0;
}
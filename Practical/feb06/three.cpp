#include <bits/stdc++.h>
using namespace std;

void printA(vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void bubsort(vector<int>& arr, int n) {
    for (int i = 0; i < n-1; i++) {
        bool swapp = false;
        for (int j = 0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                printA(arr);
                swapp = true;
            }
        }

        if (!swapp) {
            break;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubsort(arr, n);
    return 0;
}
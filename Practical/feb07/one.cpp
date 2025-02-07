#include <bits/stdc++.h>
using namespace std;

void printA(vector<int> l) {
    for (int num : l) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10,15,2,60,45};
    int n = 5;

    int p = arr[n-1];
    int i = 0;
    int j = n-2;

    while (i < j) {
        if (arr[i] > p) {
            if (arr[j] < p) {
                j--;
                swap(arr[i], arr[j]);
                printA(arr);                
            }
            i++;
        }
    }
    return 0;
}
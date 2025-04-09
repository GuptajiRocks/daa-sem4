#include <bits/stdc++.h>
using namespace std;

pair<int, int> jesus(int blocksize[], int p, int n) {
    pair<int, int> res;
    int bs = 0;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (blocksize[i] >= p || blocksize[i] < bs) {
            bs = blocksize[i];
            idx = i;
            break;
        }
    }

    blocksize[idx] = blocksize[idx] - p;

    res.first = bs;
    res.second = idx;

    return res;    
}

int main() {
    int n;
    int p;
    cin >> n >> p;

    int blocksize[n];

    for (int i = 0; i < n; i++) {
        cin >> blocksize[i];
    }

    int psize[p];

    for (int i = 0; i < p; i++) {
        cin >> psize[i];
    }
    
    cout << "Process_no:\tProcess_size \tBlock_no:\tBlock_size:\tFragement\n";
    for (int i = 0; i < p; i++) {
        pair<int, int> res = jesus(blocksize, psize[i], n);
        cout << i << " " << psize[i] << " " << res.second << " " << res.first << " " << (res.first - psize[i]) << endl;       
    }

    return 0;
}
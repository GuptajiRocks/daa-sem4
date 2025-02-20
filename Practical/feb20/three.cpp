#include <bits/stdc++.h>
using namespace std;

string rev(string s) {
    string temp = "";
    for (int i = s.length(); i >= 0; i--) {
        if (s[i] == 'q') {
            temp = temp + "p";
        } else if (s[i] == 'w') {
            temp = temp + "w";
        } else if (s[i] == 'p') {
            temp = temp + "q";
        }
    }

    return temp;
}

int main() {
    int n;
    cin >> n;
    string arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<string> resA;

    for (int i = 0; i < n; i++) {
        resA.push_back(rev(arr[i]));
    }

    for (string s : resA) {
        cout << s << endl;
    }
    cout << endl;

    return 0;
}
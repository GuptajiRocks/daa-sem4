//
// Created by ariha on 06-01-2025.
//

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node() {
        next = nullptr;
    }

    Node(int c) {
        data = c;
        next = nullptr;
    }
};

void max_LL() {
    int n;
    cin >> n;

    cout << "Enter the elements?:\n";
    int tc;
    cin >> tc;

    Node* head = new Node(tc);
    Node* temp = head;

    for (int i = 0; i < n-1; i++) {
        cin >> tc;
        temp->next = new Node(tc);
        temp = temp->next;
    }

    Node* trav = head;
    int largest = 0;
    while (trav!=nullptr) {
        if (trav->data > largest) {
            largest = trav->data;
        }
        trav = trav->next;
    }

    cout << "Largest Element: " << largest << endl;
}



int main() {
    max_LL();
    return 0;
}

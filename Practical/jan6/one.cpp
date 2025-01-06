//
// Created by ariha on 06-01-2025.
//

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int c) {
        data = c;
        next = nullptr;
    }
};

void max_LL() {
    int n;
    cin >> n;

    Node* head = nullptr;
    cout << "Enter the elements: ";
    int tc;
    for (int i = 0; i < n; i++) {
        if (head == nullptr) {
            cin >> tc;
            head = new Node(tc);
        } else {
            cin >> tc;
            Node* temp = new Node(tc);
            head->next = temp;
            head = head->next;
        }
    }

    Node* trav = head;
    while (trav != nullptr) {
        cout << trav->data << endl;
        trav = trav->next;
    }
}

int main() {
    max_LL();
    return 0;
}

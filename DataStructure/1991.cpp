//
//  1991.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/24.
//

#include <iostream>
#include <iostream>
using namespace std;

int arr[26][26];

void preorder(int i) {
    if(i + 'A' == '.') return;
    cout << char(i + 'A');
    preorder(arr[i][0]);
    preorder(arr[i][1]);
}

void inorder(int i) {
    if(i + 'A' == '.') return;
    inorder(arr[i][0]);
    cout << char(i + 'A');
    inorder(arr[i][1]);
}

void postorder(int i) {
    if(i + 'A' == '.') return;
    postorder(arr[i][0]);
    postorder(arr[i][1]);
    cout << char(i + 'A');
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        
        arr[(int) a - 65][0] = (int) b - 65;
        arr[(int) a - 65][1] = (int) c - 65;
    }
    
    preorder(0);
    cout << endl;
    inorder(0);
    cout << endl;
    postorder(0);
}

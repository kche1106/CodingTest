//
//  1991.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/24.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> v[26];
int check[26];

void preorder(int x) {
    
    if(x == -1) return;
    
    cout << (char) (x + 'A');
    preorder(v[x][0]);
    preorder(v[x][1]);
}

void inorder(int x) {
    
    if(x == -1) return;

    inorder(v[x][0]);
    cout << (char) (x + 'A');
    inorder(v[x][1]);
}

void postorder(int x) {
    
    if(x == -1) return;
    
    postorder(v[x][0]);
    postorder(v[x][1]);
    cout << (char) (x + 'A');
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        
        int idx = (int) a - 65;
        
        if(b == '.') v[idx].push_back(-1);
        else v[idx].push_back((int)b - 65);
        
        if(c == '.') v[idx].push_back(-1);
        else v[idx].push_back((int)c - 65);
    }
    
    
    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    cout << '\n';
}

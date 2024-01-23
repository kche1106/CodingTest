//
//  9934.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/23.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int k;
int arr[10024];
vector<int> res[10];

void DFS(int depth, int x, int y) {
    if(x >= y) return;
    
    int mid = (x + y) / 2;
    res[depth].push_back(arr[mid]);
    DFS(depth+1, x, mid);
    DFS(depth+1, mid+1, y);
    
}

int main() {
    cin >> k;
    
    int n = pow(2, k) - 1;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    DFS(0, 0, n);
    
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

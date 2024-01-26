//
//  9934.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/23.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int k;
vector<int> v[10];
int arr[1024];

void preorder(int start, int end, int cnt) {
    if(cnt == k) return;
    
    int mid = (start + end) / 2;
    v[cnt].push_back(arr[mid]);
    preorder(start, mid-1, cnt+1);
    preorder(mid+1, end, cnt+1);
}

int main() {
    cin >> k;
    
    int n = pow(2, k) - 1;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    preorder(0, n, 0);
    
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

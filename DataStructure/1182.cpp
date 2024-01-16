//
//  1182.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/16.
//

#include <iostream>
using namespace std;

int arr[20], visited[20];
int n, s, res;

void DFS(int i, int sum) {
    
    if(i == n) return;
    if(sum + arr[i] == s) {
        res++;
    }
    
    DFS(i+1, sum+arr[i]);
    DFS(i+1, sum);
    
}

int main() {
    cin >> n >> s;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    DFS(0, 0);
    
    cout << res << endl;
}

//
//  2660.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/21.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int friends[50][50];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            friends[i][j] = 100;
        }
    }
    
    for(int i = 1; i <= n; i++) {
        friends[i][i] = 0;
    }
    
    while (true) {
        int a, b;
        cin >> a >> b;
        if(a == -1 && b == -1) break;
        
        friends[a][b] = 1;
        friends[b][a] = 1;
    }
 
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                if(friends[j][i] != 100 && friends[i][k] != 100)
                    friends[j][k] = min(friends[j][k], friends[j][i] + friends[i][k]);
            }
        }
    }
    
    int arr[50];
    for(int i = 1; i <= n; i++) {
        int tmp = 0;
        for(int j = 1; j <= n; j++) {
            if(friends[i][j] > tmp) tmp = friends[i][j];
        }
        arr[i] = tmp;
    }
    
    int min = 1000;
    for(int i = 1; i <= n; i++) {
        if(min > arr[i]) min = arr[i];
    }
    
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(min == arr[i]) cnt++;
    }
    
    cout << min << " " << cnt << endl;
    
    for(int i = 1; i <= n; i++) {
        if(min == arr[i]) cout << i << " ";
    }
}

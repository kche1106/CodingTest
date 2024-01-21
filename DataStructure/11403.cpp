//
//  11403.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/21.
//

#include <iostream>
#include <vector>
using namespace std;

int res[100][100];

int main() {
    int n;
    cin >> n;
    
    int graph[100][100];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
            
            if(graph[i][j] == 1) res[i][j] = 1;
        }
    }
    
    for(int i = 0; i < n; i++) {  //거쳐가는 정점
        for(int j = 0; j < n; j++) {  //출발
            for(int k = 0; k < n; k++) {  //도착
                    if(res[j][i] && res[i][k] == 1) res[j][k] = 1;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

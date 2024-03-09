//
//  2531.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/10.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int in;
        cin >> in;
        v.push_back(in);
    }
    
    int visited[3001];
    memset(visited, 0, sizeof(visited));
    vector<int> eat;
    int cnt = 0;
    int res = 0;
    for(int i = 0; i < n; i++) {
        
        int j = i;
        int r = 1;
        while(r <= k) {
            int type = v[j % n];
            if(visited[type] == 0 && type != c) {
                eat.push_back(type);
                visited[type] = 1;
            }
            r++;
            j++;
        }
        cnt = eat.size()+1;
        res = max(res, cnt);
        
        eat.clear();
        memset(visited, 0, sizeof(visited));
    }
    
    cout << res;
}

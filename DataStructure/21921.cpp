//
//  21921.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/20.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> vis;
    for(int i = 0; i < n; i++) {
        int v;
        cin >> v;
        vis.push_back(v);
    }
    
    vector<int> sumv;
    int sum = 0;
    for(int i = 0; i < x; i++) sum += vis[i];
    int max = sum;
    sumv.push_back(sum);
    
    for(int i = x; i < n; i++) {
        sum = sum + vis[i] - vis[i-x];
        sumv.push_back(sum);
        if(max < sum) max = sum;
    }
    
    if(max == 0) {
        cout << "SAD";
        return 0;
    }
    
    int cnt = 0;
    for(int i = 0; i < sumv.size(); i++) {
        if(sumv[i] == max) cnt++;
    }
    
    
    cout << max << "\n" << cnt;
}

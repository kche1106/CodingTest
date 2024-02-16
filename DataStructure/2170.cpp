//
//  2170.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/16.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end());
    
    int s = v[0].first;
    int e = v[0].second;
    int res = e - s;
    for(int i = 1; i < v.size(); i++) {
        int ns = v[i].first;
        int ne = v[i].second;
        
        if(ns <= e) {
            if(ne > e) {
                res += (ne - e);
                e = ne;
            }
            else continue;
        }
        
        else {
            res += ne - ns;
            s = ns;
            e = ne;
        }
    }
    
    cout << res;
}

//
//  19637.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/24.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, string>> nick;
    for(int i = 0; i < n; i++) {
        string s;
        int num;
        cin >> s >> num;
        nick.push_back({num, s});
    }
    
    
    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;
        
        int start = 0;
        int end = n-1;
        int mid = 0;
        while(start <= end) {
            mid = (start + end) / 2;
            
            if(num <= nick[mid].first) end = mid-1;
            else start = mid+1;
        }
        
        if(num > nick[mid].first) cout << nick[mid+1].second << "\n";
        else cout << nick[mid].second << "\n";
    }
}

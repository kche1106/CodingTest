//
//  11501.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/29.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> v;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        
        int max = v.back();
        long long res = 0;
        for(int i = v.size() - 2; i >= 0; i--) {
            if(max < v[i]) max = v[i];
            else res += max - v[i];
        }
        
        cout << res << "\n";
    }
}

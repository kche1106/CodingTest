//
//  1289.cpp
//  SWEA
//
//  Created by 김채은 on 2023/11/06.
//

#include <iostream>
using namespace std;

vector<int> v;

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        int res = 0;
        
        string s;
        cin >> s;
        
        for(int i = 0; i < s.length(); i++) {
            v.push_back(s[i] - '0');
        }
        
        for(int i = 0; i < v.size(); i++) {
            if(v[i] == 1) {
                res++;
                for(int j = i; j < v.size(); j++) {
                    if(v[j] == 1) v[j] = 0;
                    else if(v[j] == 0) v[j] = 1;
                }
            }
        }
        
        cout << "#" << i+1 << " " << res << endl;
    }
}

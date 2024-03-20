//
//  6249.cpp
//  softeer
//
//  Created by 김채은 on 2024/03/19.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> str;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        str.push_back(s);
    }
    
    vector<string> ans;
    ans.push_back(str[0]);
    for(int i = 1; i < n; i++) {
        string s = str[i];
        
        bool flag = true;
        for(int j = 0; j < ans.size(); j++) {
            string comp = ans[j];
            
//            cout << "s = " << s << ", comp = " << comp << endl;
            
            flag = true;
            for(int k = 0; k < m; k++) {
                if(comp[k] == '.' || s[k] == '.') continue;
                else if(comp[k] != s[k]) {
                    flag = false;
                    break;
                }
            }
            
            if(flag) {
                for(int k = 0; k < m; k++) {
                    if(comp[k] == '.' && s[k] != '.') comp[k] = s[k];
                }
                ans[j] = comp;
//                cout << "comp = " << comp << endl;
                break;
            }
        }
        if(!flag) {
//            cout << "ans push " << s << endl;
            ans.push_back(s);
        }
    }
    
//    for(auto a : ans) cout << a << " ";
    cout << ans.size();
}

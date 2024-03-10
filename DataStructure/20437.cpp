//
//  20437.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/10.
//

#include <iostream>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        string w;
        int k;
        cin >> w >> k;
        
        map<char, int> m;
        for(int i = 0; i < w.length(); i++) {
            m[w[i]]++;
        }
        
        int mini = 1e9+10;
        int maxi = 0;
        for(int i = 0; i < w.length(); i++) {
            if(m[w[i]] < k) continue;
            string temp = "";
            temp += w[i];
            int cnt = 1;
            for(int j = i+1; j <= w.length(); j++) {
                if(cnt == k) {
                    int len = temp.length();
//                    cout << temp << endl;
                    mini = min(mini, len);
                    break;
                }
                temp += w[j];
                if(w[j] == w[i]) cnt++;
            }
            
            string temp2 = "";
            temp2 += w[i];
            int cnt2 = 1;
            for(int j = i+1; j <= w.length(); j++) {
                if(cnt2 == k) {
                    int len = temp.length();
                    if(temp2[temp2.length()-1] == w[i]) {
//                        cout << temp2 << endl;
                        maxi = max(maxi, len);
                    }
                    break;
                }
                if(m[w[i]] < k) continue;
                temp2 += w[j];
                if(w[j] == w[i]) cnt2++;
            }
        }
        
        if(mini == 1e9+10 && maxi == 0) cout << -1 << "\n";
        else cout << mini << " " << maxi << "\n";
    }
}

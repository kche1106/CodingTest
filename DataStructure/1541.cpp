//
//  1541.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/02.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    vector<string> v;
    string num = "";
    string op = "";
    for(int i = 0; i < s.length(); i++) {
        if(isdigit(s[i])) num += s[i];
        else {
            v.push_back(num);
            op += s[i];
            v.push_back(op);
            num = "";
            op = "";
        }
        
        if(i == s.length()-1) v.push_back(num);
    }
        
    bool minus = false;
    int res = stoi(v[0]);
    for(int i = 1; i < v.size(); i++) {
        if(v[i] == "-")  minus = true;
            
        if(i % 2 == 0){
            if(minus) res -= stoi(v[i]);
            else res += stoi(v[i]);
        }
    }
    
    cout << res;
}

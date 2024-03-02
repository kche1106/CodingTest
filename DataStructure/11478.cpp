//
//  11478.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/02.
//

#include <iostream>
#include <map>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    map<string, int> m;
    
    for(int i = 0; i < s.length(); i++) {  //문자열 시작
        for(int j = 1; j <= s.length(); j++) {  //개수
            string tmp = s.substr(i, j);
            m.insert({tmp, 1});
        }
    }
    
    cout << m.size();
}

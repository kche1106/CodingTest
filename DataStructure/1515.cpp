//
//  1515.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/20.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string num;
    cin >> num;
    
    int n = 0;
    int p = 0;
    while(true) {
        if(p == num.length()) break;
        n++;
        
        string str = to_string(n);
        
        for(int i = 0; i < str.length(); i++) {
            if(num[p] == str[i]) {
                p++;
            }
        }
    }
    
    cout << n;
}

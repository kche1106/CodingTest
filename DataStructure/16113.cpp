//
//  16113.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/03.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    map<string, int> m =
    {
        {"####.##.##.####",0},
        {"###..#####..###", 2},
        {"###..####..####", 3},
        {"#.##.####..#..#", 4},
        {"####..###..####", 5},
        {"####..####.####", 6},
        {"###..#..#..#..#", 7},
        {"####.#####.####", 8},
        {"####.####..####", 9}
    };
    
    vector<string> arr;
    for(int i = 0; i < n; i += n/5)
        arr.push_back(s.substr(i, n/5));
    
    for(int i = 0; i < n/5; i++) {
        if(arr[0][i] == '#') {
            
            if((i == n/5 - 1 || (arr[0][i+1] == '.' && arr[3][i] == '#'))) {
                cout << "1";
                continue;
            }
            
            string tmp = "";
            for(int j = 0; j < 5; j++) {
                tmp += arr[j].substr(i, 3);
            }
            
            if(m.find(tmp) != m.end()) {
                cout << m[tmp];
                i += 3;
            }
        }
        
    }
    
}

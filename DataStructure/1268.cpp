//
//  1268.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/04/03.
//

#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int student[1001][5];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> student[i][j];
        }
    }
    
    int max = 0;
    int res = 0;
    for(int i = 0; i < n; i++) {  //학생
        set<int> same;
        for(int j = 0; j < 5; j++) {  //학년
            int cl = student[i][j];
            for(int k = 0; k < n; k++) {
                if(k == i) continue;
                if(cl == student[k][j]) {
                    same.insert(k);
                }
            }
        }

        if(max < same.size()) {
            max = same.size();
            res = i;
        }
    }
    cout << res+1;
}

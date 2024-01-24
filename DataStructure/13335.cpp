//
//  13335.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/23.
//

#include <iostream>
#include <queue>
#include <numeric>
using namespace std;

int main() {
    int n, w, l;  //트럭 수, 다리 길이, 다리 최대 하중
    cin >> n >> w >> l;
    
    int truck[1000];
    for(int i = 0; i < n; i++) {
        cin >> truck[i];
    }
    
    int cnt = 1;
    queue<int> q;
    q.push(truck[0]);
    int weigth = truck[0];
    
    for(int i = 1; i < n; i++) {
        while (true) {
            if(q.size() == w) {
                weigth -= q.front();
                q.pop();
            }
            
            if(weigth + truck[i] <= l) break;
            
            else {
                cnt++;
                q.push(0);
            }
        }
        q.push(truck[i]);
        weigth += truck[i];
        cnt++;
        
    }
    
    cout << cnt + w << endl;
}

//
//  13335.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/23.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, w, l;  //트럭 수, 다리 길이, 다리 최대 하중
    cin >> n >> w >> l;
    
    int truck[1000];
    for(int i = 0; i < n; i++) {
        cin >> truck[i];
    }
    
    queue<int> q;
    int weight = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        while (true) {
            if(q.size() >= w) {
                weight -= q.front();
                q.pop();
            }
            
            if(weight + truck[i] > l) {
                q.push(0);
                cnt++;
            }
            else if(weight + truck[i] <= l) break;
        }
        q.push(truck[i]);
        weight += truck[i];
        cnt++;
    }
    
    cout << cnt + w << endl;
}


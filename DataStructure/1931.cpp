//
//  1931.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/13.
//

#include <iostream>
#include <queue>
using namespace std;

struct meeting {
    int start;
    int end;
    meeting(int s, int e) : start(s), end(e) {}
    
    bool operator < (const meeting t) const {
        if(this -> end == t.end) return this -> start > t.start;
        else return this -> end > t.end;
    }
};

int main() {
    int n;
    cin >> n;
    
    priority_queue<meeting> q;
    for(int i = 0; i < n; i++) {  //end를 vector의 first에 넣는 방법도 있음
        int a, b;
        cin >> a >> b;
        q.push(meeting(a, b));
    }
    
    int res = 1;
    int now = q.top().end;
    q.pop();
    while(!q.empty()) {
        if(q.top().start >= now) {
            now = q.top().end;
            res++;
        }
        q.pop();
    }
    
    cout << res;
}

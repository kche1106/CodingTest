//
//  11866.cpp
//  DataStructure
//
//  Created by 김채은 on 2022/07/24.
//

#include <iostream>
using namespace std;

int arr[100];
int i = 0;
int j = 0;

class Queue {
private:
    int arr[100];
    int i = 0; //다음에 들어갈 곳
    int j = 0; //시작
    int size = 0;
    
public:
    void push(int n) {
        size++;
        arr[i++] = n;
    }
    
    void pop() {
        if (size == 0)
            return;
        else {
            arr[j++] = 0;
            size--;
        }
    }
    
    int sizeF() {
        return size;
    }
    
    bool empty() {
        if (size == 0)
            return "true";
        else
            return "false";
    }
    
    int front() {
        if (size == 0)
            return -1;
        else {
            return arr[j];
        }
    }
    
    void back() {
        if (size == 0)
            cout << -1 << endl;
        else {
            cout << arr[i-1] << endl;
        }
    }
};


int main() {
    
    int n, k;
    cin >> n;
    cin >> k;
    
    Queue q;
    
    for(int i = 1; i <= n; i++) {
        q.push(i);
    }
    
    cout << "<";
    while(n > 0) {
        
        for(int i = 1; i <= k - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        
        cout << q.front();
        q.pop();
        
        if(q.sizeF() > 0) {
            cout << ",";
        }
        
        n--;
    }
    cout << ">";
}

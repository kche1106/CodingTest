//
//  18258.cpp
//  DataStructure
//
//  Created by 김채은 on 2022/07/24.
//

#include <iostream>
#include <string>
using namespace std;

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
            cout << "-1" << endl;
        else {
            cout << arr[j] << endl;
            arr[j++] = 0;
            size--;
        }
    }
    
    void sizeF() {
        cout << size << endl;
    }
    
    void empty() {
        if (size == 0)
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
    
    void front() {
        if (size == 0)
            cout << -1 << endl;
        else {
            cout << arr[j] << endl;
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
    
    int N;
    cin >> N;
    
    Queue q;
    
    string s;
    for(int i = 0; i < N; i++) {
        cin >> s;
        if(s == "push") {
            int n;
            cin >> n;
            q.push(n);
        }
        
        else if(s == "pop") {
            q.pop();
        }
        
        else if(s == "size") {
            q.sizeF();
        }
        
        else if(s == "empty") {
            q.empty();
        }
        
        else if(s == "front") {
            q.front();
        }
        
        else if(s == "back") {
            q.back();
        }
    }
}



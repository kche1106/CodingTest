//
//  10828.cpp
//  DataStructure
//
//  Created by 김채은 on 2022/07/13.
//

#include <iostream>
#include <string>
using namespace std;

void stack(string);
int arr[100];
int i = 0;

int main() {
    
    int N;
    cin >> N;
    
    string s;
    for(int i = 0; i < N; i++) {
        cin >> s;
        stack(s);
    }
}

void stack(string s) {
    
    if(s == "push") {
        int n;
        cin >> n;
        arr[i++] = n;
    }
    
    else if(s == "pop") {
        if (i == 0)
            cout << "-1" << endl;
        else {
            cout << arr[i - 1] << endl;
            arr[i--] = 0;
        }
    }
    
    else if(s == "size") {
        cout << i << endl;
    }
    
    else if(s == "empty") {
        if (i == 0)
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
    
    else if(s == "top") {
        if (i == 0)
            cout << "-1" << endl;
        else {
            cout << arr[i - 1] << endl;
        }
    }
}

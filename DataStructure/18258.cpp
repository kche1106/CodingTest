//
//  18258.cpp
//  DataStructure
//
//  Created by 김채은 on 2022/07/24.
//

#include <iostream>
#include <string>
using namespace std;

int arr[100];
int i = 0;
int j = 0;

int main() {
    
    int N;
    cin >> N;
    
    string s;
    for(int i = 0; i < N; i++) {
        cin >> s;
        if(s == "push") {
            int n;
            cin >> n;
            arr[i++] = n;
        }
        
        else if(s == "pop") {
            if (i == 0 || j >= i)
                cout << "-1" << endl;
            else {
                cout << arr[j] << endl;
                arr[j++] = 0;
            }
        }
        
        else if(s == "size") {
            cout << i-j << endl;
        }
        
        else if(s == "empty") {
            if (i == 0 || j >= i)
                cout << "1" << endl;
            else
                cout << "0" << endl;
        }
        
        else if(s == "front") {
            if (i == 0)
                cout << -1 << endl;
            else {
                cout << arr[j] << endl;
            }
        }
        
        else if(s == "back") {
            if (i == 0)
                cout << -1 << endl;
            else {
                cout << arr[i-1] << endl;
            }
        }
    }
}

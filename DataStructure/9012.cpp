//
//  9012.cpp
//  DataStructure
//
//  Created by 김채은 on 2022/07/14.
//

#include <iostream>
#include <string>
using namespace std;


class Stack{
private:
    char arr[100] = {};
    int i = 0;
    
public:
    void push(char c) {
        arr[++i] = c;
    }
    
    bool pop() {
        if(empty())
            return false;
        else {
            arr[i--] = {};
            return true;
        }
    }
    
    bool empty() {
        if (i <= 0) {
            return true;
        }
        else return false;
    }
};

string foo(string s, Stack stack) {
    
    for(int i = 0; i < s.length(); i++) {
        
        if(s[i] == '(')
            stack.push('(');
        
        else {
            //스택이 비어있어서 pop을 못하는경우(')'만 남음)
            if(!stack.pop())
                return "NO";
        }
    }
    if(stack.empty())
        return "YES";
    //문자열 마지막까지 왔는데도 stack에 '('이 남아있을 때
    else return "NO";
}

int main() {
    int n;
    cin >> n;
    
    Stack stack;
    string result;
    
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        cout << foo(s, stack) << endl;
    }
}

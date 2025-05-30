#include <bits/stdc++.h>
using namespace std;
stack<char> opr;
stack<int> num;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    getline(cin, s);
    int n = s.length();
    for(int i = 0; i < n; i++) {
        if(isdigit(s[i])) {
            string num_str = "";
            while(i < n && isdigit(s[i])) num_str += s[i++];
            num.push(stoi(num_str));
        }
        if(s[i] == ' ') continue;
        if(s[i] == 'h') opr.push('h');
        if(s[i] == 'g') opr.push('g');
        if(s[i] == 'f') opr.push('f');
        if(!num.empty()) {
            if(opr.top() == 'f') {
                opr.pop();
                int x = num.top()*2-3;
                num.pop();
                num.push(x);
            }
            if(opr.top() == 'g') {
        }
    }
    return 0;
}
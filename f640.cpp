#include <bits/stdc++.h>
using namespace std;
stack<char> opr;
stack<int> num;
stack<int> track_opr;
stack<int> track_num;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    bool sat;
    getline(cin, s);
    int n = s.length();
    for(int i = 0; i < n; i++) {
        if(isdigit(s[i])) {
            string num_str = "";
            while(i < n && isdigit(s[i])) num_str += s[i++];
            num.push(stoi(num_str));
            track_num.push(i);
        }
        if(s[i] == 'h') {
            opr.push('h');
            track_opr.push(i);
        }else if(s[i] == 'g') {
            opr.push('g');
            track_opr.push(i);
        }else if(s[i] == 'f') {
            opr.push('f');
            track_opr.push(i);
        }
        sat = false;
        while(!sat && !num.empty() && !opr.empty()) {
            if(opr.top() == 'f') {
                if(track_opr.top() < track_num.top()) {
                    opr.pop();
                    int x = num.top()*2-3;
                    num.pop();
                    num.push(x);
                }
            }
        }
    }
    cout << num.top() << endl;
    return 0;
}
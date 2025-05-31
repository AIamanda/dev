#include <bits/stdc++.h>
using namespace std;
stack<char> opr;
stack<long long int> num;
stack<int> track_opr;
stack<long long int> track_num;

void popr(char x, int i) {
    opr.push(x);
    track_opr.push(i);
}
void pnum(int x, int i) {
    num.push(x);
    track_num.push(i);
}
void dopr() {
    opr.pop();
    track_opr.pop();
}
void dnum() {
    num.pop();
    track_num.pop();
}
int main() {
    string s;
    bool sat;
    getline(cin, s);
    int n = s.length(), temp[3];
    for(int i = 0; i < n; i++) {
        if(isdigit(s[i]) || s[i] == '-') {
            string num_str = "";
            while(i < n && (isdigit(s[i]) || s[i] == '-')) num_str += s[i++];
            if(i == n) i--;
            pnum(stoi(num_str), i);
        }
        if(s[i] == 'h') popr('h', i);
        if(s[i] == 'g') popr('g', i);
        if(s[i] == 'f') popr('f', i);
        sat = false;
        while(!sat && !num.empty() && !opr.empty()) {
            if(opr.top() == 'f') {
                if(track_opr.top() < track_num.top()) {
                    dopr();
                    int x = num.top()*2-3;
                    dnum();
                    pnum(x, i);
                }else sat = true;
            }
            else if (opr.top() == 'g') {
                if(track_opr.top() < track_num.top() && !(track_num.size() == 1)) {
                    int tmp = track_num.top();
                    track_num.pop();
                    if(track_opr.top() < track_num.top()) {
                        track_num.push(tmp);
                        dopr();
                        int x1 = num.top();
                        dnum();
                        int x2 = num.top();
                        dnum();
                        pnum((x2*2)+x1-7, i);
                    }else {
                        track_num.push(tmp);
                        sat = true;
                    }
                }else sat = true;
            }
            else if(opr.top() == 'h') {
                if(num.size() < 3) sat = true;
                if(!sat && track_opr.top() < track_num.top()) {
                    temp[0] = track_num.top();
                    track_num.pop();
                    temp[1] = track_num.top();
                    track_num.pop();
                    temp[2] = track_num.top();
                    track_num.pop();
                    if(track_opr.top() > temp[2]) sat = true;
                    track_num.push(temp[2]);
                    track_num.push(temp[1]);
                    track_num.push(temp[0]);
                }else sat = true;
                if(!sat) {
                    dopr();
                    int x1 = num.top();
                    dnum();
                    int x2 = num.top();
                    dnum();
                    int x3 = num.top();
                    dnum();
                    pnum((x3*3)-(x2*2)+x1, i);
                }
            }
        }
    }
    cout << num.top() << endl;
    return 0;
}
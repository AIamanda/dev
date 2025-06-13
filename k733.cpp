#include<bits/stdc++.h>
using namespace std;

int magnet(string &s, string &copy, int idx, int last_one) {
    if(idx >= copy.length()) return 0;
    if(copy[idx] == 'T') {
        int tmp = copy[++idx]*10+copy[++idx];
        if(!last_one) return magnet(s, copy, (idx+1), tmp);
        return abs((tmp-last_one)) + magnet(s, copy, (idx+1), tmp);
    }
    else if(copy[idx] == 'L') {
        copy[idx+1]--;
        return magnet(s, copy, (idx+2), last_one);
    }
    else if(copy[idx] == 'E') {
        int temp = idx, val = 0;
        for(; temp >= 0; --temp) {
            if(copy[temp] == 'E') val ++;
            else if(copy[temp] == 'L') val--;
            if(val == 0) break;
        }
        if(copy[temp+1] == '0') {
            copy[temp+1] = s[temp+1];
            return magnet(s, copy, (idx+1), last_one);
        }
        else {
            copy[temp+1]--;
            idx = temp+2;
            return magnet(s, copy, idx, last_one);
        }
        return 0;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    string copy = s;
    cout << magnet(s, copy, 0, 0) << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int n = s.length();
    int at;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'T') {
            string num_str = "";
            i++;
            while(isdigit(s[i])) {
                num_str += s[i];
                i++;
            }
            at = stoi(num_str);
            i = n;
        }
    }
    string 
}
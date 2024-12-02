#include <iostream>
#include <string>
using namespace std;
 int d = 256;
 int q = 101;
int gethasf( string &s, int m) {
    int val = 0;
    for (int i=0;i<m;i++) {
        val= (val * d + s[i]) % q;
    }
    return val;
}
int rabin_krap( string &text,  string &pattern) {
    int n = text.length();
    int m = pattern.length();
    if (m>n) {
        return -1;
    }
    int p=gethasf(pattern, m);
    int h=gethasf(text, m);
    int h=1;
    for (int i=0;i<m-1;i++) {
        h=(h*d)%q;
    }
    for (int i = 0; i <= n - m; i++) {
        if (p == h) {
        if (text.substr(i, m) == pattern) {
        return i;
    }
}
        if (i < n - m) {
            h = (d * (h-text[i]*h)+text[i+m])%q;
            if (h < 0) {
            h += q;
    }
    }
}
    return -1;
}
int main() {
    string text="ABABDABACDABABCABAB";
    string pattern="ABABCABAB";
    int r=rabin_krap(text,pattern);
    if (r!=-1) 
        cout<<"Pattern found at index:" <<r<< endl;
     else 
        cout<<"Pattern not found!"<<endl;
    return 0;
}

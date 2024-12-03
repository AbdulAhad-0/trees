#include <iostream>
#include <string>
using namespace std;

void getlps(string &p, int lps[]) {
    int m = p.length(), length = 0, i = 1;
    lps[0] = 0;
    while (i < m) {
        if (p[i] == p[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int searchkmp(string &t, string &p) {
    int n = t.length(), m = p.length(), i = 0, j = 0;
    int lps[m];
    getlps(p, lps);

    while (i < n) {
        if (p[j] == t[i]) {
            i++;
            j++;
        }
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            return i - j;
        } else if (i < n && p[j] != t[i]) {
            j = (j != 0) ? lps[j - 1] : 0;
        }
    }
    cout << "Pattern not found." << endl;
    return -1;
}

int main() {
    string t = "ABCDABCEEEF";
    string p = "EEEF";
    searchkmp(t, p);
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

const int d = 256;
const int q = 101;

int compute_hash(const string &s, int m) {
    int hash_val = 0;
    for (int i = 0; i < m; i++) {
        hash_val = (hash_val * d + s[i]) % q;
    }
    return hash_val;
}

int rabin_karp_search(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();

    if (m > n) {
        return -1;
    }

    int pattern_hash = compute_hash(pattern, m);
    int text_hash = compute_hash(text, m);

    int h = 1;
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (pattern_hash == text_hash) {
            if (text.substr(i, m) == pattern) {
                return i;
            }
        }

        if (i < n - m) {
            text_hash = (d * (text_hash - text[i] * h) + text[i + m]) % q;
            if (text_hash < 0) {
                text_hash += q;
            }
        }
    }

    return -1;
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    int result = rabin_karp_search(text, pattern);
    if (result != -1) {
        cout << "Pattern found at index: " << result << endl;
    } else {
        cout << "Pattern not found!" << endl;
    }

    return 0;
}

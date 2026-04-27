#include <bits/stdc++.h>
using namespace std;

vector<int> Rabin_karp(string s, string t) {
    vector<int> ans;

    int n = s.size();
    int m = t.size();

    if (m > n) return ans;

    const int base=26;
    const int mod=1e9 + 7;
    
    
    long long hash_s = 0, hash_t = 0, power = 1;

    for (int i = 0; i < m; i++) {
        hash_t = (hash_t * base + (t[i] - 'a' + 1)) % mod;
        hash_s = (hash_s * base + (s[i] - 'a' + 1)) % mod;

        if (i < m - 1)
            power = (power * base) % mod;
    }

    for (int i = 0; i <= n - m; i++) {
        if (hash_s == hash_t) {
          if(s.substr(i,m)==t) {
             ans.push_back(i);
          }
        }

        if (i < n - m) {
            hash_s = (hash_s - (s[i] - 'a' + 1) * power % mod + mod) % mod;
            hash_s = (hash_s * base + (s[i + m] - 'a' + 1)) % mod;
        }
    }

    return ans;
}

int main() {
    string s = "abcab";
    string t = "ab";

    vector<int> ans = Rabin_karp(s, t);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

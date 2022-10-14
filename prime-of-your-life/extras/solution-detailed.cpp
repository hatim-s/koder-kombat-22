#include <bits/stdc++.h>
using namespace std;

#define sze 10000

class primeSieve {
    public:
    vector <int> sv;
    primeSieve (int sz){
        sv.resize (sz+1, 0);
        sv[0] = sv[1] = 0;
        for (int i = 2; i <= sz; i++){
            if (sv[i] == 0) {
                sv[i] = -1;
                for (int j = 2*i; j <= sz; j += i) sv[j]++;
            }
        }
    }
    bool isPrime (int num) { return sv[num] == -1; }
    int primeFactors (int num) { return abs(sv[num]); }
    void printSieve () { for (const auto& si : sv) cout << si << "\n"; }
};

int main () {
    #ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif
    
    int n, m; cin>>n>>m;
    vector <int> nums (n);
    for (auto& ni : nums) cin >> ni;

    primeSieve sieve (sze);
    int idx = 1;
    map <int,int> hashtable;
    vector <int> primes;
    for (int i = 2; i <= sze; i++) {
        if (sieve.isPrime (i)) {
            hashtable [i] = idx; 
            primes.push_back (i);
            idx++;
        }
    }

    vector <int> factor_count (hashtable.size() + 1, 0);
    for (const auto& ni : nums) 
        if (sieve.isPrime (sieve.primeFactors (ni)))
            factor_count [hashtable[sieve.primeFactors (ni)]]++;
    
    partial_sum (factor_count.begin(), factor_count.end(), factor_count.begin());

    while (m--){
        int l, r; cin >> l >> r;
        l = *lower_bound (primes.begin(), primes.end(), l);
        r = (sieve.isPrime (r)) ? r : *(lower_bound (primes.begin(), primes.end(), r) - 1);
        cout << factor_count [hashtable[r]] - factor_count [hashtable[l]-1] <<"\n";
    }
}
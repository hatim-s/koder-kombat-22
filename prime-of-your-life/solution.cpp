#include <bits/stdc++.h>
using namespace std;

vector <int> sv = vector <int> (1e6+1, 0);
void sieve (){
    for (int i = 1; i < sv.size(); i++) 
        for (int j = i; j < sv.size(); j+=i)
            sv[j]++;
}

bool isPrime (int x) { return sv[x] == 2; }

int main (){
    // #ifndef ONLINE_JUDGE
    // freopen("./extra/testcases/input/input10.txt", "r", stdin);
    // freopen("./extra/testcases/output/output10.txt", "w", stdout);
    // #endif

    sieve ();

    int n, m; cin>> n >> m;
    vector <int> vec (n);
    vector <int> cnt (101, 0);

    for (int& vi : vec){
        cin>>vi;
        if (!isPrime(sv[vi]) && sv[vi] <= 100) cnt[sv[vi]]++;
    }

    partial_sum (cnt.begin(), cnt.end(), cnt.begin());

    while (m--){
        int l, r; cin >> l >> r;
        cout << cnt[r] - cnt[l-1] << "\n";
    }

    return 0;
}
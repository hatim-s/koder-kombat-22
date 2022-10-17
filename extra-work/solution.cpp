#include <bits/stdc++.h>
using namespace std;

bool isPrime (int x) {
    for (int j = 2; j * j <= x; j++) if (x % j == 0) return false;
    return true;
}


int main (){
    // #ifndef ONLINE_JUDGE
    // freopen("../prime-of-your-life/input/input00.txt", "r", stdin);
    // freopen("output05.txt", "w", stdout);
    // #endif

    int n, m; cin >> n >> m;
    vector <int> vec (n);
    for (int& vi : vec) cin >> vi;

    vector <int> cnt (101, 0);
    for (int i = 0 ; i < n; i++){
        int vi = vec[i];
        int factors = 1;
        for (int j = 2; j * j <= vi; j++){
            int cnt = 0;
            while (vi % j == 0){
                vi = vi/j;
                cnt++;
            }
            factors = factors * (cnt+1);
        }

        if (vi > 1) factors = 2*factors;

        // cout << vec[i] << " " << factors << "\n";
        if (factors <= 100) cnt[factors]++;
    }

    // for (int i = 0; i < 10; i++) cout << cnt[i] << " "; cout << "\n";
    for (int i = 2; i <= 100; i++){
        if (isPrime(i)) cnt[i] = 0;
    }

    partial_sum (cnt.begin(), cnt.end(), cnt.begin());

    while (m--){
        int l, r;
        cin>> l >> r;

        int ans = cnt[r] - cnt[l-1];
        cout << ans <<"\n";
    }

    return 0;
}

/*
7 3
19 25 10 30 105 3 8
1 3
2 2
2 5
*/
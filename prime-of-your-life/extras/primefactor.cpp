#include <bits/stdc++.h>
using namespace std;

int pf (int n) {
    int cnt = 0;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) cnt++;
        while (n % i == 0) n = n/i;
    }
    if (n > 2) cnt++;
    return cnt;
}

int main (){
    #ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    #endif

    int n, m; cin >> n >> m;
    while (n--){
        int temp; cin>>temp;
        cout << pf (temp) << "\n";
    }
    cout << "\n";

    return 0;
}
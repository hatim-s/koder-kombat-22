#include <bits/stdc++.h>
using namespace std;

bool isPrime (int x){
    for (int i = 2; i * i <= x; i++){
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("primes-1e3.txt", "w", stdout);
    #endif

    vector <int>  primes;
    int p = 1e3;
    while (primes.size() < 20){
        if (isPrime (p)) primes.push_back(p);
        p--;
    }

    for (const auto& pi : primes) cout << pi << " ";
    cout << "\n";

    return 0;
}
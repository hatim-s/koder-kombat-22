// #include <bits/stdc++.h>
// using namespace std;

// bool isPrime (int x) {
//     for (int j = 2; j * j <= x; j++) if (x % j == 0) return false;
//     return true;
// }


// int main (){
//    // #ifndef ONLINE_JUDGE
//    // freopen("../prime-of-your-life/input/input00.txt", "r", stdin);
//    // freopen("output05.txt", "w", stdout);
//    // #endif

//     int n, m; cin >> n >> m;
//     vector <int> vec (n);
//     for (int& vi : vec) cin >> vi;

//     vector <int> cnt (101, 0);
//     for (int i = 0 ; i < n; i++){
//         int vi = vec[i];
//         int factors = 1;
//         for (int j = 2; j * j <= vi; j++){
//             int cnt = 0;
//             while (vi % j == 0){
//                 vi = vi/j;
//                 cnt++;
//             }
//             factors = factors * (cnt+1);
//         }

//         if (vi > 1) factors = 2*factors;

//         // cout << vec[i] << " " << factors << "\n";
//         if (factors <= 100) cnt[factors]++;
//     }

//     // for (int i = 0; i < 10; i++) cout << cnt[i] << " "; cout << "\n";
//     for (int i = 2; i <= 100; i++){
//         if (isPrime(i)) cnt[i] = 0;
//     }

//     partial_sum (cnt.begin(), cnt.end(), cnt.begin());

//     while (m--){
//         int l, r;
//         cin>> l >> r;

//         int ans = cnt[r] - cnt[l-1];
//         cout << ans <<"\n";
//     }

//     return 0;
// }

// /*
// 7 3
// 19 25 10 30 105 3 8
// 1 3
// 2 2
// 2 5
// */


/*
  Created by: Amit Kumar at 10:02 on 16 Oct 22
*/
#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define db(...)
#endif
using namespace std;

#define all(x) x.begin(), x.end()

inline constexpr int MAXN = 2e5 + 1;
inline constexpr int mod = 1e9 + 7;

#define int long long

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> edges(2 * n - 1);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> edges[i].first >> edges[i].second;
    }
    for (int i = n - 1; i < edges.size(); i++)
    {
        edges[i] = {i - n + 1, i - n + 1};
    }
    db(edges);
    vector<int> g(n);
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }

    sort(all(edges), [&](const pair<int, int> &a, const pair<int, int> &b)
         { return max(g[a.first], g[a.second]) < max(g[b.first], g[b.second]); });

    int k;
    cin >> k;

    vector<pair<int, int>> queries(k);
    for (int i = 0; i < k; i++)
    {
        cin >> queries[i].first;
        queries[i].second = i;
    }

    sort(all(queries));

    vector<int> ans(k);

    // dsu
    vector<int> parent(n), sz(n), sum(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
        sum[i] = g[i];
    }

    function<int(int)> find = [&](int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    };

    db(edges);
    int a = 0;
    int i = 0;
    for (auto &[q, idx] : queries)
    {
        while (i < edges.size() and max(g[edges[i].first], g[edges[i].second]) <= q)
        {
            int u = find(edges[i].first);
            int v = find(edges[i].second);
            if (u != v)
            {
                if (sz[u] < sz[v])
                    swap(u, v);
                parent[v] = u;
                sz[u] += sz[v];
                sum[u] += sum[v];
            }
            a = max({a, sum[u], sum[v]});
            i++;
        }
        ans[idx] = a;
    }
    for (auto &it : ans)
        cout << it << '\n';
}
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("../kayamkulam-kochunni/input/input14.txt", "r", stdin);
    freopen("output14.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    // cin >> t;
    for (int I = 1; I <= t; I++)
    {
#ifdef LOCAL
        cerr << "Case #" << I << ": ";
#endif
        solve();
    }
#ifdef LOCAL
    auto done = std::chrono::high_resolution_clock::now();
    cerr << "Time = " << std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count() << " ms\n";
#endif
    return 0;
}
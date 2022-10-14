#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

// tree definition
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update>ordered_set;

const char newl = '\n';

void solve(){
    int n,k; cin >> n >> k;
    vector<pair<int,int>> a(n);
    vector<int> b(n);
    ordered_set s,t;

    for(int i = 0; i < n; i++ ) cin >> a[i].first;
    for(int i = 0; i < n; i++) {
        cin >> a[i].second ;
        t.insert(a[i].second);
    }

    sort(a.begin(),a.end());
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int cntl = i;
        int cntr = t.order_of_key(a[i].second);
        int cntu = s.order_of_key(a[i].second);
        if( cntl + cntr - cntu == k ) ans++;
        s.insert(a[i].second);
    }
    cout << ans << newl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}

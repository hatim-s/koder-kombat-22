#include <bits/stdc++.h>
using namespace std;

void make_set(int v, vector<int>& parent, vector<int>& size) {
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v, vector<int>& parent) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent);
}

void union_sets(int a, int b, vector<int>& parent, vector<int>& size) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input32.txt", "r", stdin);
    // freopen("output32.txt", "w", stdout);
    // #endif

    // Since the graph is a tree no of edges is nodes-1;
    int nodes; 
    cin >> nodes;

    vector<pair<int,int>> edges;
    map<int,vector<pair<int,int>>> adj;
    vector<int> a(nodes,0);
    map<int,int> ans;
    vector<int> queries;

    for(int i=0; i<nodes-1; i++){
        int u,v;
        cin >> u >> v;
        edges.push_back({u,v});
    }

    for(int i=0; i<nodes; i++){
        cin >> a[i];
        ans[a[i]]=a[i];
    }

    for(auto x : edges){
        int u = x.first;
        int v = x.second;
        adj[max(a[u],a[v])].push_back({u,v});
    }

    vector<int> size(nodes,0);
    vector<int> parent(nodes,0);
    vector<int> gold(nodes,0);

    for(int i=0; i<nodes; i++){
        make_set(i,parent,size);
        gold[i] = a[i];
    }

    int bestGoldSoFar = 0;
    for(auto x : adj){
        int cur_val = x.first;
        int goldForThisLevel = 0;
        for(auto y : x.second){
            int parent1 = find_set(y.first,parent);
            int parent2 = find_set(y.second,parent);
            int totalGold = (parent1==parent2) ? gold[parent1] : (gold[parent1]+gold[parent2]);
    
            goldForThisLevel = max(goldForThisLevel,totalGold);
            union_sets(y.first,y.second,parent,size);
            int newParent = find_set(y.first,parent);
            gold[newParent] = totalGold;
        }
        bestGoldSoFar = max(bestGoldSoFar,goldForThisLevel);
        ans[cur_val] = max(bestGoldSoFar, ans[cur_val]);
    }

    int q; cin >> q;
    for(int i=0; i<q; i++){
        int temp; cin >> temp;
        queries.push_back(temp);
    }

    // for(auto val : ans)
    //     cout << val.first << " " << val.second << endl;
    // cout << endl;

    for(auto val:queries){
        int ret = 0;

        auto iter = ans.lower_bound(val);
        if(iter == ans.end()){
            iter--;
            ret = max(ret,(*iter).second);
        }
        else if((*iter).first == val){
            ret = max(ret,(*iter).second);
        }
        else{
            if(iter != ans.begin()){
                iter--;
                ret = max(ret,(*iter).second);
            }
        }
        cout << ret << endl;
    }
}
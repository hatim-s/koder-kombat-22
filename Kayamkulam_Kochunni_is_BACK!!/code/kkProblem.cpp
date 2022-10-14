/*
Kayamkulam Kochunni is BACK!!

You are given several districts of kerala. Each district is connected directly or indirectly to all other districts(the graph formed by connecting the districts is a tree). Each district
has some gold reserves which is guarded by security. There are certain security levels(security level of x is more superior than security level y if x > y). Level x security, guardes the 
districts which has x units of gold reserved.
For those who don't know who Kayamkulam Kochunni is; He steals money/gold from rich and gives it to poor.
Kayamkulam Kochunni is back in state and he is planning a big heist and he need your help to plan that heist. You are given k different scenario, each scenario will have a number which
denotes his mood and the risk he is willing to take for the heist. Say for example if his mood is x for a particular scenario then he will only steal from those districts who's security 
level is less or equal to x. Find the maximum amount of loot he can pull off for each of the given scenario.

Note
1. He can start his heist from any district, but once the heist starts he can only go to its adjacent districts.
2. Say if his mood level for a particular scenario is x then, he will get caught if he goes to district who's security level is more than x(i.e total loot will be 0)

*/

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
    #ifndef ONLINE_JUDGE
    freopen("sample_input2.txt", "r", stdin);
    freopen("sample_output2.txt", "w", stdout);
    #endif

    // Since the graph is a tree no of edges is nodes-1;
    int nodes; 
    cin >> nodes;

    vector<pair<int,int>> edges;
    map<int,vector<pair<int,int>>> adj;
    vector<int> a(nodes,0);
    map<int,int> ans;
    unordered_set<int> distinctGoldUnits;
    vector<int> queries;

    for(int i=0; i<nodes-1; i++){
        int u,v;
        cin >> u >> v;
        edges.push_back({u,v});
    }

    for(int i=0; i<nodes; i++){
        cin >> a[i];
        distinctGoldUnits.insert(a[i]);
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
        ans[cur_val] = bestGoldSoFar;
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
        ret = (distinctGoldUnits.find(val)!=distinctGoldUnits.end()) ? (*distinctGoldUnits.find(val)) : 0;

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
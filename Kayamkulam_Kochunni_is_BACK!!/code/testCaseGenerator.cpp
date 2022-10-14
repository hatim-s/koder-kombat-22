#include <bits/stdc++.h>
#include <cstdlib>
#include <time.h>
using namespace std;

void makeTree(vector<pair<int,int>> & edges, int& n, int& minChild, int& maxChild){
    srand(time(NULL));
    queue<int> q;
    q.push(0);

    int nodes = 1;

    while(q.size()){
        int len = q.size();
        for(int i=0; i<len; i++){
            int noOfChild = rand()%(maxChild-minChild+1)+minChild;
            // cout << "No Of Child Is " << noOfChild << endl;
            int parentVal = q.front();
            for(int j=0; j<noOfChild; j++){
                if(nodes == n) return;
                edges.push_back({parentVal,nodes});
                q.push(nodes++);
            }
            q.pop();
        }
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("sample_input2.txt", "w", stdout);
    #endif

    srand(time(NULL));

    // no of nodes
    int n = 8;
    int q = n;

    // Range for no of children for each nodes.
    int minChild = 1;
    int maxChild = 2;

    // Ranges for the nodes values
    int lower = 2;
    int higher = 5;

    vector<pair<int,int>> edges;
    vector<int> nodeValues;
    vector<int> queries;

    makeTree(edges,n,minChild,maxChild);
    
    for(int i=0; i<n; i++) 
        nodeValues.push_back(rand()%(higher-lower+1)+lower);

    for(int i=1; i<=q; i++) queries.push_back(i);
    random_shuffle(queries.begin(), queries.end());

    cout << n << endl;
    for(auto val:edges) cout << val.first << " " << val.second << endl;
    for(auto val:nodeValues) cout << val << " ";
    cout << endl;
    cout << q << endl;
    for(int i=0; i<queries.size(); i++) cout << queries[i] << " ";
    cout << endl;
    return 0;
}
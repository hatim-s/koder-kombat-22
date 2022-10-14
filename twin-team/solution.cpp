#include<bits/stdc++.h>
using namespace std;

int main() {
    // ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
    // fstream f1,f2;
    // for(int t=12;t<=12;t++)
    // {
        // char* pp1 = (char*)malloc(100*sizeof(char));
        // char* pp2 = (char*)malloc(100*sizeof(char));
        // string p1 = "in" + to_string(t) + ".txt";
        // string p2 = "out" + to_string(t) + ".txt";
        // for(int j=0;j<8;j++)
        //     pp1[j] = p1[j];
        // pp1[8] = '\0';
        // for(int j=0;j<9;j++)
        //     pp2[j] = p2[j];
        // pp2[9] = '\0';
        
        // freopen("in30.txt","r",stdin);
        // freopen("out30.txt","w",stdout);
        // f1.open("in12.txt",ios::in);
        // f2.open("out12.txt",ios::out);
        int tc;
        cin>>tc;
        // cout<<tc<<endl;
        while(tc--) {
            int n;
            cin>>n;
            // cout<<n<<endl;
            int arr[2*n];
            for(int i=0;i<2*n;i++)
                arr[i] = -1;
            int idx[n][2];
            for(int i=0;i<n;i++)
                idx[i][0] = idx[i][1] = -1;
            for(int i=0;i<2*n;i++) {
                cin>>arr[i];
                if(idx[arr[i]-1][0] == -1)
                    idx[arr[i]-1][0] = i;
                else
                    idx[arr[i]-1][1] = i;
            }
            int x[2*n];
            for(int i=0;i<2*n;i++)
                x[i] = 0;
            for(int i=0;i<n;i++) {
                x[idx[i][0]]+=2;
                x[idx[i][0]+1]--;
                x[idx[i][1]]++;
                x[idx[i][1]+1]-=2;
            }
            long long curr = 0;
            for(int i=0;i<2*n;i++) {
                curr += x[i];
                if(curr%2)
                    cout<<0;
                else
                    cout<<1;
            }
            cout<<endl;
            // cout<<"Done\n";
        }
        // f1.close();
        // f2.close();
        // free(pp1);
        // free(pp2);
    // }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pb push_back

const int N=1e5+10;
vector<int> g[N];
bool vis[N];
vector<vector<int>> connected_comp;
vector<int> current_cc;

void dfs(int vertex){
    current_cc.pb(vertex);
    vis[vertex]=true;
    for(auto child:g[vertex]){
        if(vis[child]) continue;
        dfs(child);
    }
}
void sanat(){
    int cnt=0;
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int v1,v2;cin>>v1>>v2;
        g[v1].pb(v2);
        g[v2].pb(v1);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        current_cc.clear();
        dfs(i);
        connected_comp.pb(current_cc);
        cnt++;
    }
    cout<<cnt<<"\n";
    for(auto cur_cc:connected_comp){
        for(auto vertex:cur_cc){
            cout<<vertex<<" ";
        }
        cout<<"\n";
    }
}
// TC : O(V+E)
int main() {
    int t=1;
    while(t--){
        sanat();
    }
}

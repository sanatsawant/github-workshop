#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pb push_back
const int INF=1e9+7;
const int N=1e5+10;
vector<pair<int,int>> g[N];
vector<int> level(N,INF);

void bfs(int v){
    deque<int> q;
    q.push_back(v);
    level[v]=0;
    while(!q.empty()){
        int currv=q.front();
        q.pop_front();

        for(auto child:g[currv]){
            int wt=child.second;
            if(level[currv]+wt < level[child.first]){
                level[child.first]=level[currv]+wt;
                if(wt==1) q.push_back(child.first);
                else if(wt==0) q.push_front(child.first);
            }
            
        }

    }

}
void sanat(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int v1,v2;cin>>v1>>v2;
        g[v1].pb({v2,0});
        g[v2].pb({v1,1});
    }
    bfs(1);
    cout<<level[n]<<"\n";

}

int main() {
    int t=1;
    while(t--){
        sanat();
    }
}

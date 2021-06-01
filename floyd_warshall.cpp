#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back

int n, m;

int main(){
    // ll n, m;
    int q;
    cin>>n>>m>>q;
   
    vector<pair<ll, ll> > adj[n];
    vector<vector<ll> > dist(n, vector<ll> (n, 1e18));
    for(int i=0; i<n; i++)
        dist[i][i]=0;

    for(int i=0; i<m; i++){
        ll u, v, w;
        cin>>u>>v>>w;
        u--;
        v--;
        adj[u].pb(make_pair(v,w));
         adj[v].pb(make_pair(u,w));
        
         dist[u][v]=min(dist[u][v], w);
         dist[v][u]=min(dist[v][u], w);
         
    }
    // dist=adj;

    for (int k = 0; k < n; k++) {
       
        for (int i = 0; i < n; i++) {
          
            for (int j = 0; j < n; j++) {
              
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != 1e18
                        && dist[i][k] != 1e18))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for(int i=0; i<q; i++){
        int st, end;
        cin>>st>>end;
        if(dist[st-1][end-1]==1e18)
            cout<<"-1\n";
        else
        cout<<dist[st-1][end-1]<<"\n";
        
    }
   
    return 0;
}

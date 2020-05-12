
#include <bits/stdc++.h>

using namespace std;

#define pb push_back

#define ll long long int
vector< pair<int, int>> edges[100000];
#define max 1000000
ll dist[max];
int n,m;
map <int, int> visit;

int calc_min(){
    
    int mini=max, min_i;
    for(int i=0; i<n; i++){
        
        if(visit[i]==0 && dist[i]<=mini){
            min_i=i;
            mini=dist[i];
        }
    }
    
    visit[min_i]=1;
    // cout<<"index: "<<min_i<<"\n";
    return min_i;
    
}

void dijkstra(){
    
    for(int i=0; i<n; i++){
        
        dist[i]=max;
        
    }
    
    dist[0]=0;
for(int l=0; l<n; l++){
    
    
     int u= calc_min();
    // cout<<edges[u].size()<<"\n\n";
    for(int i=0; i<edges[u].size(); i++){
        // for(int j=0; j<edges[i].size; j++){
            
            if(visit[edges[u][i].first]==0 && dist[u]!=max)
            {
                if(dist[u]+ edges[u][i].second < dist[edges[u][i].first]){
                    dist[edges[u][i].first] = dist[u]+ edges[u][i].second;
                }
            }
        // }
    }
    
    
    
}
// cout<<"n: "<<n<<"\n";
   
    for(int i=0; i<n; i++){
        // cout<<"hey";
        if(dist[i]==max){
            cout<<"-1\n";
            
        }
        else{
            cout<<dist[i]<<"  ";
        }
    }
}



void run(){
    
    visit.clear();

    cin>>n>>m;
    
    int a,b, weight;
    for(int i=0; i<m; i++){
        cin>>a>>b>>weight;
        edges[a].pb({b, weight});
        
       
    }
   
    dijkstra();
    
    
}

int main()
{
    ll t=1;
    // cin>>t;
    while(t--)
    {
        run();
        
    }
    
    
}



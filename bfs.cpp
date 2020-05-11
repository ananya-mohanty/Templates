
#include <bits/stdc++.h>

using namespace std;

#define pb push_back

#define ll long long int
vector<pair<int, int>> graph[100000];
#define max 1000000
unordered_map<int,int> visited;


void bfs(int u)
{
    queue <int> q;
    // cout<<"hey";
    q.push(u);
    visited[u]=1;
    
    while(!q.empty()){
        int ind= q.front();
        cout<<ind<<"  ";
        q.pop();
        // cout<<graph[ind].size()<<"\n";
        for(int i=0; i<graph[ind].size(); i++){
            
            if(visited[graph[ind][i].first]==0){
                 
                 visited[graph[ind][i].first]=1;
                 q.push(graph[ind][i].first);
                 
                
            }
        }
    }
    
}
void run(){
    
    visited.clear();
 
    
    int n, m; 
    cin>>n>>m;
    
    int a,b, weight;
    for(int i=0; i<m; i++){
        cin>>a>>b>>weight;
        
        graph[a].pb({b, weight});
      
    }
    for(int i=0; i<n; i++){
        if(visited[i]==0){
            bfs(i);
        }
    }
    // bfs(2);
    
    
    
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



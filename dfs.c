
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define max 200000
#define ll long long int
// #define INT_MIN -99
vector<int> adj[max];
unordered_map<int,int> visited;
ll n, count;
ll arr[max], par;
#define mod  1000000007 

void addEdge(int u, int v)
{
    adj[u].push_back(v);
    // adj[v].push_back(u); 

}

void DFSUtil(int v){
    visited[v] = 1; 
    cout<<v<<" ";
    for(int i = 0; i < adj[v].size(); i++) 
    {
        // cout<<"child : "<<adj[v][i]<<endl;
       
        if(visited[adj[v][i]]==0) {
              
                DFSUtil(adj[v][i]);
        }
           
    }
        
}

void run(){
    
    visited.clear();
    int n, m; 
    cin>>n>>m;
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        addEdge(a,b);
        // cout<<a<<" "<<b<<"\n";
    }
    for(int i=0; i<n; i++){
        if(visited[i]==0){
            DFSUtil(i);
        }
    }
    // for(int i=1; i<=n; i++){
    //     cout<<arr[i]<<" ";
    // }
    
    
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


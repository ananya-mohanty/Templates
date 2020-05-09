
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define max 200000
#define ll long long int

vector<int> adj[max];
unordered_map<int,int> visited;
ll n, count;
ll arr[max], par;
#define mod  1000000007 
int fre[max];

void addEdge(int u, int v) 
{ 
    adj[u].push_back(v); 
    fre[v]++; 
    // cout<<fre[v]<<" ";
    //adj[v].push_back(u); 
} 
vector<int> topological_sorting() 
{ 
    queue<int> q; 
    
    for (int i = 0; i < n; i++)
    {
        if (!fre[i]) 
            q.push(i); 
       
    } 
        
  
    vector<int> l; 
  
    while (!q.empty()) { 
        // cout<<"udhar";
        int u = q.front(); 
        q.pop(); 
  
        l.push_back(u); 
  
    
        for (int i = 0; i < adj[u].size(); i++) { 
            fre[adj[u][i]]--; 
 
            if (!fre[adj[u][i]]) 
                q.push(adj[u][i]); 
        } 
    } 
    
    return l; 
} 

void run(){
    int m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        addEdge(a,b);
        
    }
    // cout<<"idhar";
    vector <int> ans = topological_sorting();
    // cout<<ans.size();
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<"\t";
    }
    
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


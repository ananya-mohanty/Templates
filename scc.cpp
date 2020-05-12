
#include <bits/stdc++.h>

using namespace std;

#define pb push_back

#define ll long long int
vector<int> graph[100000], trGraph[100000];
#define max 1000000
stack <int> stk;
map <int, int> visited;
int n,m;

void fillit(int index){
    
    // cout<<index<<"\t";
    visited[index]=1;
    
    for(int i=0; i<graph[index].size(); i++){
        if(visited[graph[index][i]]==0){
            
            fillit(graph[index][i]);
        }
    }
    stk.push(index);
    //  cout<<stk.top()<<" ";
}

void DFSUtil(int u){
    
    visited[u]=1;
    
     cout<<u<<" ";
    
    for(int v=0; v<trGraph[u].size(); v++){
        
        if(visited[trGraph[u][v]]==0){
            
            DFSUtil(trGraph[u][v]);
        }
    }
}
void scc(){
    
    visited.clear();
    for(int i=0; i<n; i++){
        if(visited[i]==0)
        fillit(i);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<graph[i].size(); j++){
            // cout<<graph[i][j]<<" "<<i<<"\n";
            trGraph[graph[i][j]].pb(i);
        }
    }
    
    visited.clear();
    
    while(!stk.empty()){
        // cout<<"topp ; "<<stk.top()<<endl;
        int tp=stk.top();
        stk.pop();
        
        if(visited[tp]==0){
            // cout<<"tp : "<<tp<<endl;
            DFSUtil(tp);
            cout<<"\n";
        }
    }
    
    
}


void run(){
    
    cin>>n>>m;
    
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        
        graph[a].pb(b);
      
    }
    scc();
   
}

int main()
{
    ll t=1;
  
    while(t--)
    {
        run();
        
    }
    
    
}



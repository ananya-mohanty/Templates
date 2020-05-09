#include <bits/stdc++.h>
#define pb push_back
using namespace std;

// first element indicates the node it is connected to the second element is the weight of the edge between them
vector<pair<int,int> > graph[100005];
map<int,int> vis;

/*sample input:
5 6
1 2 3
2 3 4
3 4 5
2 4 3
1 5 2
2 4 5*/


void dfs(int s)
{
    vis[s]=1;
    for(int i=0;i<graph[s].size();i++)
    {
        if(!vis[graph[s][i].first])
        {
           
            dfs(vis[graph[s][i].first]);

        }
    }
}

void bfs(int starting_node){
    queue<int> q;
    q.push(starting_node);
    vis[starting_node]=1;
    while(!q.empty()){
        int s= q.front();
        q.pop();
        for(int i=0;i<graph[s].size();i++){
            if(!vis[graph[s][i].first]){
                //processing

                q.push(vis[graph[s][i].first]);
                vis[graph[s][i].first]=1;
            // processing 
                
            }
        }
    }
}

signed main() {
    int n,edges;
    cin>>n>>edges;
    for(int i=0;i<edges;i++){
        int u,v, weight;
        cin>>u>>v>>weight;
        graph[u].pb({v,weight});
        graph[v].pb({u,weight});  // bidirectional edges
    }


}

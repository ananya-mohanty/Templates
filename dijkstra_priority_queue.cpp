
#include <bits/stdc++.h>

using namespace std;

#define pb push_back

#define ll long long
vector<pair<int, int>> graph[100000];
#define max 1000000

// int main(){
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);
//   ll n, x;
   
//   cin>>x>>n;
   
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        
    vector<int> dist(V, INT_MAX);
    
    priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>> > pq;
    
    pq.push({0, S});
    dist[S]=0;
    while(!pq.empty()){
        pair<int, int> curr = pq.top();
        int ind=curr.second;
        pq.pop();
        
        for(int i=0; i<adj[ind].size(); i++){
            int dest = adj[ind][i][0];
            int d = curr.first + adj[ind][i][1];
            if(d<dist[dest]){
                dist[dest]=d;
                pq.push({d, dest});
            }
        }
    }
    
    return dist;
}

   
   
 
  
   
//     return 0;
// }

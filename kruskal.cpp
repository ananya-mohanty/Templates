
#include <bits/stdc++.h>

using namespace std;

#define pb push_back

#define ll long long int
vector<pair<int, int>> graph[100000];
#define max 1000000
unordered_map<int,int> visited;
ll n, count;
ll arr[max], sz[max], par;
#define mod  1000000007 
vector<pair<int, pair<int,int> > > edges,ans;

int subset(int index){
    
    while(arr[index]!=index)
    {
        arr[index] = arr[arr[index]];
        index = arr[index];
    }
    return index;
}
void make_union(int x, int y)
{
    int r1 = subset(x), r2=subset(y);
    if(r1==r2)
        return;
    
    if(sz[r1] > sz[r2]){
        arr[r2]= r1;
        sz[r1]+=sz[r2];
        
        
    }
    else{
        sz[r2]+=sz[r1];
        arr[r1]=r2;
    }
}
int compi(const void *a, const void *b){
    
    const pair<int, int>*a1 = (pair<int, int>*)a;
    const pair<int, int>*a2 = (pair<int, int>*)b;
    return a1->second > a2->second;
}
void kruskal()
{
    int e=0, i=0;
    
    sort(edges.begin(), edges.end());
    
    for(int i=0;i<edges.size();i++){
    
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        
        if(subset(a)!=subset(b)){
            make_union(a,b);
            ans.pb(edges[i]);
            
        }
        
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i].first<<" ";
    }
    
    return;
}

void run(){
    
    visited.clear();
    
    for(int i=0; i<max; i++){
        sz[i]=1;
        arr[i]=i;
        
    }
    
    int n, m; 
    cin>>n>>m;
    
    int a,b, weight;
    for(int i=0; i<m; i++){
        cin>>a>>b>>weight;
        edges.pb({weight,{a,b}});
      
    }
    kruskal();
    
    
    
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


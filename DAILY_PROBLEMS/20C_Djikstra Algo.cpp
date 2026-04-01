#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m;
    cin>>n>>m;
 
    vector<pair<int,int>> adj[n+1];
 
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
 
    vector<long long> dist(n+1,1e18);
    vector<int> parent(n+1);
 
    for(int i=1;i<=n;i++) parent[i]=i;
 
    priority_queue<pair<long long,int>,
    vector<pair<long long,int>>,
    greater<pair<long long,int>>> pq;
 
    dist[1]=0;
    pq.push({0,1});
 
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
 
        int node=it.second;
        long long d=it.first;
 
        for(auto edge:adj[node]){
            int adjNode=edge.first;
            int wt=edge.second;
 
            if(d+wt < dist[adjNode]){
                dist[adjNode]=d+wt;
                pq.push({dist[adjNode],adjNode});
                parent[adjNode]=node;
            }
        }
    }
 
    if(dist[n]==1e18){
        cout<<-1;
        return 0;
    }
 
    vector<int> path;
    int node=n;
 
    while(parent[node]!=node){
        path.push_back(node);
        node=parent[node];
    }
 
    path.push_back(1);
 
    reverse(path.begin(),path.end());
 
    for(auto it:path) cout<<it<<" ";
}
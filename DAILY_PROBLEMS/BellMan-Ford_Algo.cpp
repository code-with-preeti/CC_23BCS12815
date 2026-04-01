#include<bits/stdc++.h>
using namespace std;

int main(){
    int V = 5;
    int E = 8;

    vector<vector<int>> edges = {
        {0,1,6},
        {0,2,7},
        {1,2,8},
        {1,3,5},
        {1,4,-4},
        {2,3,-3},
        {2,4,9},
        {3,1,-2}
    };

    vector<int> dist(V, INT_MAX);
    int src = 0;
    dist[src] = 0;

    // relax edges V-1 times
    for(int i=0;i<V-1;i++){
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];

            if(dist[u]!=INT_MAX && dist[u]+wt < dist[v]){
                dist[v]=dist[u]+wt;
            }
        }
    }

    // check negative cycle
    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        int wt=edge[2];

        if(dist[u]!=INT_MAX && dist[u]+wt < dist[v]){
            cout<<"Negative Cycle Detected";
            return 0;
        }
    }

    for(int i=0;i<V;i++)
        cout<<dist[i]<<" ";
}
#include <bits/stdc++.h>
using namespace std;
priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

void dijkstra(vector<pair<int,int>> *adj,int curr,int n,int *dist,bool *visit)
{
    
    visit[curr] = true;
    //cout<<curr<<" |  ";
    for(int i=0;i<adj[curr].size();i++)
    {
        int next = adj[curr][i].first;
        int w = adj[curr][i].second;
        
        if(!visit[next] && dist[next] > dist[curr]+w)
        {
            dist[next] = dist[curr]+w;
            pq.push({dist[next],next});
        }
    }
    
    while(!pq.empty())
    {
        pair<int,int> p = pq.top();
        if(visit[p.second] == false)
            break;  
        pq.pop();
    }
    
    if(!pq.empty())
    {
        pair<int,int> p = pq.top();
        pq.pop();
        dijkstra(adj,p.second,n,dist,visit);
    }
    
    return;
}

int main() {
    int n,m;
    cin>>n>>m;
    
    vector<pair<int,int>> *adj = new vector<pair<int,int>>[n+1];
    
    for(int i=0;i<n;i++)
    {
        int s,e,w;
        cin>>s>>e>>w;
        adj[s].push_back({e,w});
    }
    int *dist = new int[n+1];
    bool *visit = new bool[n+1];
    
    for(int i=0;i<n+1;i++)
    {
        visit[i] = false;
        dist[i] = 1e9;
    }
    dist[1] = 0;
    visit[1] = true;
    
    dijkstra(adj,1,n,dist,visit);
    
    for(int i=2;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
    
    while(!pq.empty())
    {
        pq.pop();
    }
    
    delete[] dist;
    delete[] visit;
    
	return 0;
}

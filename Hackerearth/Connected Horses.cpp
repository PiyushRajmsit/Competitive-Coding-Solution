// Date - 12 April 2018
/*
Solution By: Piyush Raj

/=============\   /===========\
||           ||   ||          ||
||           ||   ||          ||
||           ||   ||          ||
||=============   ||===========/
||                ||  \\
||                ||   \\
||                ||    \\
||                ||     \\
                           

Platform : Hackerearth
Ques   : Connected Horses Problem
Concept : DFS/BFS Graph
*/


#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
 
bool visit[1000001];
 
void dfs(vector<int> *edges,int start,vector<int> *v, bool *visit)
{
   visit[start] = true;
    v->push_back(start);
  
     for(int i=0;i<edges[start].size();i++)
     {
         int next = edges[start][i];
         
       if(visit[next]==false)
       {
           dfs(edges,next,v,visit);
       }
     }
     
}
 
long long factorial(int size)
{
long long f=1;
 
  while(size>=1)
  {
     f = ( (f%mod) * (size %mod)) %mod;
    size--;
  }
  return f;
}
 
 
 
int main()
{
    int t;
    
   int dp[1001][1001];
 
 
  cin>>t;
  while(t--)
  {
    
    int n,m,q;
    cin>>n>>m>>q;
    
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
    dp[i][j]=0;
    }
    int x,y;
    
    for(int i=1;i<=q;i++)
    {
      cin>>x>>y;
      dp[x][y] = i;
    }
    
    vector<int> *edges = new vector<int>[q+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
         if(dp[i][j]>0)
         {
          int start = dp[i][j];   
             
             // checking board configuration
         
           //condition 1
             if(i+2<=n && j+1<=m)
             {
                 if(dp[i+2][j+1]>0)
                 edges[start].push_back(dp[i+2][j+1]);
             }
             //condition 2
             if(i+2<=n && j-1>=1)
             {
                 if(dp[i+2][j-1]>0)
                 edges[start].push_back(dp[i+2][j-1]);
             }
             //condition 3
             if(i-2>=1 && j+1<=m)
             {
                 if(dp[i-2][j+1]>0)
                 edges[start].push_back(dp[i-2][j+1]);
             }
             //condition 4
             if(i-2>=1 && j-1>=1)
             {
                 if(dp[i-2][j-1]>0)
                 edges[start].push_back(dp[i-2][j-1]);
             }
             //condition 5     
             if(i+1<=n && j+2<=m)
             {
                 if(dp[i+1][j+2]>0)
                 edges[start].push_back(dp[i+1][j+2]);
             }
             //condition 6
             if(i-1>=1 && j+2<=m)
             {
                 if(dp[i-1][j+2]>0)
                 edges[start].push_back(dp[i-1][j+2]);
             }
             //condition 7
             if( i-1 >=1 && j-2>=1)
             {
              if(dp[i-1][j-2]>0)   
             edges[start].push_back(dp[i-1][j-2]);    
             }
             //condition 8
             if(i+1<=n && j-2>=1)
             {
                 if(dp[i+1][j-2]>0)
                 edges[start].push_back(dp[i+1][j-2]);
             }
             
             
         }
        }
    }
    
   // bool *visit = new bool[q+1];
    long long total=1;
    
    for(int i=1;i<=q;i++)
    visit[i] = false;
    
    for(int i=1;i<=q;i++)
    {
      if(visit[i] == false)
      {
        vector<int> *v = new vector<int>();
        dfs(edges,i,v,visit);
            long long len = factorial(v->size());
          total = (total%mod * len%mod)%mod;
      }
   
    }
    
    
   cout<<total<<endl; 
  }
	return 0;
}

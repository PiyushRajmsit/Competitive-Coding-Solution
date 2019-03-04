// Date - 12 Jan 2018
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
Ques   : Falling Dominos Problem
Concept : Kosaraju Graph
*/



#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
   void dfs( vector<int> *edges , int start,int n,bool *visit ,stack<int> *nodex)
    {
      
      visit[start]  = true;
//       cout<<start<<endl;
 
      for (int i = 0; i < edges[start].size(); ++i)
      {
            int next = edges[start][i];
              
              if(visit[next] == false)
               dfs(edges,next,n,visit,nodex);
 
      }
 
         nodex->push(start);
    }
 
 void dfs(vector<int> *edges,int start, bool *visit,int n)
{
	visit[start] = true;
	
	for(int i=0;i<edges[start].size();i++)
	{
	int next = edges[start][i];	
		if(visit[next]==false)
		dfs(edges,next,visit,n);
	}
}
 
int main()
{
	int t;
	cin>>t;
  while(t--)
{
       int n,m;
       cin>>n>>m;
       
       vector<int> *edges = new vector<int>[n+1];
 
            for (int i = 0; i < m; ++i)
            {
            	int start,end;
                 cin>>start>>end;
 
                 edges[start].push_back(end);  
            }
              
            //  cout<<"PHASE 1"<<endl;
              
              bool *visit = new bool[n+1];
 
              for (int i = 0; i<=n; ++i)
              {
              	visit[i] = false;
              }
                
                 
            stack<int> *nodex = new stack<int>();
             
             for (int i = 1; i<=n; ++i)
               {
                 if(visit[i]  == false)
                   dfs(edges,i,n,visit,nodex);
               }
            //   cout<<"PHASE 2"<<endl;
             
         for(int i=0;i<=n;i++)
          visit[i] = false;
 
               int count=0;
               while(!nodex->empty())
                    {
                   int up = nodex->top();
                    nodex->pop();
//                  cout<<" EVERYTHING ISS FINE  "<<up<<endl;
                    	if(visit[up] ==false )
                        {
                        	dfs(edges,up,visit,n);
                        	count++;
                        }       
                //        cout<<"Everrything is fine "<<up<<endl;
                	
                    }
                    cout<<count<<endl;
 
}
 
	return 0;
}

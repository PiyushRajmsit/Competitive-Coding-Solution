// Date - 12 Jan 2018
/*
Solution By: Piyush Raj

/=============\   /===========\
||	      ||  ||	      ||
||	      ||  ||          ||
||	      ||  ||	      ||
||=============   ||==========||
||		  ||  \\
||		  ||   \\
||		  ||	\\
||		  ||	 \\
                           

Platform : Hackerearth
Ques   : Space Smuggler Problem
Concept : Reverse Graph
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
struct node{
  int end;
  int wt; 
    };
 
node tree[4001000];
 
   void buildtree(int start,int ed,int treenode)
       {
           if(start==ed)
           {
               tree[treenode].end = start;
               tree[treenode].wt = INT_MAX;
                return;
           }
           
           int mid  = (start+ed)/2;
           
           buildtree(start,mid,2*treenode);
           buildtree(mid+1,ed,2*treenode+1);
           
           tree[treenode].end = start;
           tree[treenode].wt  = INT_MAX;
           return;
       }
       
       void update(int start,int ed,int treenode,int index,int val)
       {
           if(start==ed)
           {
             tree[treenode].wt = val;
            tree[treenode].end = start;
               return ;
           }
           
           int mid  = (start+ed)/2;
           
           if(index<=mid)
           update(start,mid,2*treenode,index,val);
           else
           {
           update(mid+1,ed,2*treenode + 1,index,val);
           }
           node left = tree[2*treenode];
           node right = tree[2*treenode +1];
           
           if(left.wt<right.wt)
           tree[treenode] = left;
           
           else
           {
               tree[treenode] = right;
           }
           return;
       }
       
   void dijkstra(ll *dijs,vector<node> *edges,bool *visit,int src,int n)
   {
     for(int i=0;i<=n;i++)
   {
    dijs[i] = INT_MAX;
   visit[i] = false; 
   }  
     
  visit[src] = true;
   dijs[src] = 0;
  int curr = src;
  int count=0; 
  
  buildtree(1,n,1);
  
  while(count!= n-1)
  {
    for(int i=0;i<edges[curr].size();i++)
    {
      node n3 = edges[curr][i];
    if(visit[n3.end] == false)  
    {
       if(dijs[n3.end] > dijs[curr] + n3.wt )    
        {
            dijs[n3.end] = dijs[curr] + n3.wt;
            update(1,n,1,n3.end,dijs[n3.end]);
        }    
        }
    }
    
    curr = tree[1].end;
 //  cout<<tree[1].end<<endl;
   if(curr!=INT_MAX)
   {
       update(1,n,1,curr,INT_MAX);
       visit[curr] = true;
   }
     count++; 
    
  }        
   }
 
int main()
{
     int n,m,s,t;
     cin>>n>>m>>s>>t;
         
   vector<node> *edges = new vector<node>[n+1];
   vector<node> *redges = new vector<node>[n+1];
      
       node n1;
       node n2;
       
     for(int i=1;i<=m;i++)
     {
         int start,ed,weigh;
       cin>>start>>ed>>weigh;
       
       n1.end = ed;
       n1.wt = weigh;
       
       edges[start].push_back(n1);
       
       n2.end = start;
       n2.wt = weigh;
       
         redges[ed].push_back(n2);
     }
       
    ll  *dijs = new ll[n+1];
    ll  *dijt = new ll[n+1];
    ll *rdijs = new ll[n+1];
    ll *rdijt = new ll[n+1];
  bool  *visit = new bool[n+1];
  bool flag=true;
  
  
  // Applying Dijkstra for S to all vertex
  
  dijkstra(dijs,edges,visit,s,n);  
 
  
  // Applying dijkstra for t to all vertex
 
  dijkstra(dijt,edges,visit,t,n);  
 
  //Applying dijkstra for s to all vertex reverse
 
  dijkstra(rdijs,redges,visit,s,n);  
  
  
  //Applying dijkstra for t to all vertex reverse
  
  dijkstra(rdijt,redges,visit,t,n); 
 
int mini = INT_MAX;
  for(int i=1;i<=n;i++)
  {
    
    if(dijs[i]!=INT_MAX && dijt[i]!=INT_MAX && rdijs[i]!=INT_MAX && rdijt[i]!=INT_MAX )
    {
    if(i!=s && i!=t)
      {
    if( mini>dijs[i]+dijt[i]+rdijs[i]+rdijt[i] )
    mini = dijs[i]+dijt[i]+rdijs[i]+rdijt[i];
      }
          
      } 
}
if(mini==INT_MAX)
cout<<-1<<endl;
    else{
      cout<<mini<<endl;
  }
	return 0;
}

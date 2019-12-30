// Date - 24 Feb 2018
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
Ques   : Monk and the Islands  Problem
Concept : DFS/BFS Graph
*/


#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define ll long long
int main()
{
	//code
 
  int n,x,y,m,t;
  cin>>t;
 
  while(t--)
  {
    cin>>n>>m;
  
  queue <int> s;
 
  vector <int> a[100005];
  
  
  bool v[100005];
 ll int d[100005];
 
  
    for(int i=0;i<=n;i++)
    {
        a[x].clear(),d[i]=1000000000000,v[i]=false;
}
    
  for(int i=1;i<=m;i++)
  {
    cin>>x>>y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
 
 
  s.push(1);
    d[1]=0;
    v[1]=true;
  while(s.empty()==0)
  {
    int ii=s.front();
    
    s.pop();
    
    for(int i=0;i<a[ii].size();i++)
    {
      int z=a[ii][i];
      /*if(z==n)
      {
        v[z]=true;
      o=d[ii]+1;
        break;
      }*/
        
      if(d[z]>d[ii]+1 && v[z]==false)
      {
        s.push(z);
        d[z]=d[ii]+1;
      v[z]=true;
      }
    }
 
  }
  
  
  cout<<d[n]<<endl;
}
  return 0;
}

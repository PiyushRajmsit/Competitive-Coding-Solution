// Date - 4 April 2018
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



#include<bits/stdc++.h>
using namespace std;
  
void dfs( vector<int> *edges , int start, bool *visit , set<int> *s)
{
   visit[start]  = true;
    s->insert(start);
  
  for(int i=0;i<edges[start].size();i++)
  {
  int next = edges[start][i];
    
    if( visit[next] == false )
    dfs(edges,next,visit,s);
  }
  
  return;
}
 
 
 
 
  set <set<int> *> * getconnect(vector <int > *edges , int n)
  {
    bool *visit = new bool[n+1];
    
    for(int i=0;i<=n;i++)
      visit[i]=false;
    
    set <set<int> *> *output = new  set <set<int> *>();
    
    for(int i=1;i<=n;i++)
    {
      if(visit[i] == false)
      {
        set<int>* s = new set<int>();
        	dfs(edges,i,visit,s);
          
           output->insert(s);
      }
    }
    delete[] visit;
    return output;
  }
 
 
   int main()
   {
  int *input = new int[100009];
  int *perm  = new int[100009];
  int t;
  cin>>t;
  
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    bool flag=true;
    vector<int> *edges = new vector<int>[n+1];
    
    for(int i=1;i<=n;i++)
      cin>>input[i];   
    
    for(int i=1;i<=n;i++)
      cin>>perm[i];
    
    for(int i=0;i<m;i++)
    {
      int start,end;
      cin>>start>>end;
      edges[start].push_back(end);
      edges[end].push_back(start);
    }
    set <set<int> *> *component = getconnect(edges,n); 
    set<set<int> *>:: iterator it = component->begin();
 
    set <set<int>> *s1 = new  set <set<int>>();
    set <set<int>> *s2 = new  set <set<int>>();
    
    
      while(it!=component->end())
   {
 
          set<int>* arr = *it;
          set<int> :: iterator it1 = arr->begin();
          
          set<int> p;// = new set<int>();
          set<int> p1;// = new set<int>();
       
        while(it1!=arr->end())
         {
       p.insert( input[*it1]);   
       p1.insert(perm[*it1]);
         it1++; 
       }
        s1->insert(p);
        s2->insert(p1);   
        it++; 
   }
   
  
    /*
      set<set<int>>:: iterator it2 = s1->begin();
      while(it2!=s1->end())
   {
 
          set<int> arr = *it2;
          set<int> :: iterator it3 = arr.begin();
 
       while(it3!=arr.end())
         {
         	cout<<*it3<<" ";
         it3++;
         }
         cout<<endl;
         it2++; 
   }
      set<set<int>>:: iterator it4 = s2->begin();
       while(it4!=s2->end())
   {
 
          set<int> arr = *it4;
          set<int> :: iterator it5 = arr.begin();
 
       while(it5!=arr.end())
         {
         	cout<<*it5<<" ";
         it5++;
         }
         cout<<endl;
         it4++; 
   }
    */
    set<set<int>>:: iterator it6 = s1->begin();
    set<set<int>>:: iterator it8 = s2->begin();
    while(it6!=s1->end())
    {
     // set<set<int> *>:: iterator it2 = s1->begin();
      set<int> cmp1 = *it6; 
      set<int >cmp2 = *it8;
      
      if(cmp1!=cmp2)
      {
      //  cout<<"True"<<endl;
        flag=false;
         break;
       }
     //   cout<<"thik hain"<<endl;
      it6++;
      it8++;
    }
   // cout<<flag<<endl;
    if(flag)
    cout<<"YES"<<endl;
  else
  {
    cout<<"NO"<<endl;
  }
    // delete edges;
      //delete component;
      delete s1;
      delete s2;
     // delete
  }
  	return 0;
}

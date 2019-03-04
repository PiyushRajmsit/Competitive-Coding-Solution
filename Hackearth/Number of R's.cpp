// Date - 2 Feb 2018
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
Ques   : Number of R's Problem
Concept : Adhoc
*/


#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int t;
  int len;
  
  
  
  cin>>t;
  string s1;
  while(t--)
  {
    cin>>s1;
    len=s1.length();
   int curr = 0 ;
    int best=0;
    int no_of_r = 0;
   for(int i=0;i<len;i++) 
   {
     if(s1[i]=='R')
     {
       curr = curr-1;
       no_of_r++;
     }
       if(s1[i]=='K')
     curr = curr+1;
     
     if(curr>best)
       best = curr;
     if(curr<0)
       curr=0;
   }
    if(no_of_r==len)
      cout<<no_of_r-1<<endl;
    else
    {
    cout<<no_of_r + best<<endl; 
    }
    
    
    
  }
    return 0;
}

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
                           

Platform : Codeforces
Ques   : Jon Snow and his favourite number Problem
Concept : DP
*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
  int *arr = new int[1026];
  int *mark = new int[1026];
  
  for(int i=0;i<=1025;i++)
  {
    arr[i]=0;
    mark[i]=0;
  }
  int n,k,x,index;
  cin>>n>>k>>x;
  
  for(int i=0;i<n;i++)
  {
  cin>>index;
  arr[index] = arr[index]+1;    
  }
  
  /*
  for(int i=1;i<=32;i++)
    cout<<arr[i]<<" ";
  cout<<endl;
  */
  int collect=0;
  int range=0;
  int add;
  int xoro;
  for(int i=0;i<k;i++)
  {
    collect=0;
   for(int j=0;j<=1025;j++)
   {
   
     if(arr[j]>0)
     {
     range=arr[j];  
     add = range/2;

       
     if((collect+1)%2==1 && range%2==1)
     add++;
    
    //   cout<<add<<endl;
       
     collect=collect+range;
     xoro = j^x;  
  
     mark[xoro] = mark[xoro]+add;
      mark[j] = mark[j]+arr[j]-add;
     }
     
     }
   for(int j=0;j<=1025;j++)
   {
     
     arr[j]=mark[j];
     mark[j]=0;
   }
  
/*    for(int q=1;q<=32;q++)
    cout<<arr[q]<<" ";
    cout<<endl;
  */  
  }
  
 int low,high;
  //=1000;
  int r=1;
  for(int i=0;i<=1025;i++)
  {
    if(arr[i]>0 && r==1)
    {
      low=i;
     r=0;
    }
    if(arr[i]>0)
      high=i;
    
  }
 
   /*for(int i=1;i<=50;i++)
    cout<<arr[i]<<" ";
  cout<<endl;
  */
  
  cout<<high<<" "<<low;
  
    return 0;
}
